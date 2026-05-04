#!/usr/bin/env python3
"""Validate dialogue CSV files (nodes/choices/loc) before runtime.

Usage:
  python validate_dialogue_csv.py
  python validate_dialogue_csv.py --root .
"""

from __future__ import annotations

import argparse
import csv
import re
import sys
from pathlib import Path
from typing import Dict, List, Set, Tuple

NODE_REQUIRED = {"id", "type", "speakerKey", "textKey", "next", "condition", "effect", "event"}
CHOICE_REQUIRED = {"nodeId", "choiceId", "textKey", "next", "condition", "effect", "event"}
LOC_REQUIRED = {"key", "lang", "text"}
VALID_NODE_TYPES = {"line", "choice", "end"}
COND_TOKEN_RE = re.compile(r"^[A-Za-z0-9_ .!&|=<>\"'():-]+$")


def load_csv_rows(path: Path, required: Set[str]) -> Tuple[List[Dict[str, str]], List[str]]:
    errors: List[str] = []
    if not path.exists():
        return [], [f"Missing file: {path}"]

    with path.open("r", encoding="utf-8-sig", newline="") as file:
        reader = csv.DictReader(file)
        fields = set(reader.fieldnames or [])
        missing = sorted(required - fields)
        if missing:
            errors.append(f"{path.name}: missing columns: {', '.join(missing)}")
            return [], errors
        rows = [{key: (value or "").strip() for key, value in row.items()} for row in reader]

    if not rows:
        errors.append(f"{path.name}: no data rows")

    return rows, errors


def validate(root: Path) -> Tuple[List[str], List[str]]:
    errors: List[str] = []
    warnings: List[str] = []

    nodes, e1 = load_csv_rows(root / "nodes.csv", NODE_REQUIRED)
    choices, e2 = load_csv_rows(root / "choices.csv", CHOICE_REQUIRED)
    loc_rows, e3 = load_csv_rows(root / "loc.csv", LOC_REQUIRED)
    errors.extend(e1 + e2 + e3)

    if errors:
        return errors, warnings

    node_ids: Set[str] = set()
    node_types: Dict[str, str] = {}
    referenced_loc_keys: Set[str] = {"ui_next", "ui_restart"}
    used_conditions: Set[str] = set()

    for index, row in enumerate(nodes, start=2):
        node_id = row["id"]
        node_type = row["type"]

        if not node_id:
            errors.append(f"nodes.csv:{index}: id is empty")
            continue
        if node_id in node_ids:
            errors.append(f"nodes.csv:{index}: duplicate node id '{node_id}'")
        node_ids.add(node_id)

        if node_type not in VALID_NODE_TYPES:
            errors.append(f"nodes.csv:{index}: invalid type '{node_type}'")
        node_types[node_id] = node_type

        if not row["speakerKey"]:
            errors.append(f"nodes.csv:{index}: speakerKey is empty for node '{node_id}'")
        if not row["textKey"]:
            errors.append(f"nodes.csv:{index}: textKey is empty for node '{node_id}'")

        referenced_loc_keys.add(row["speakerKey"])
        referenced_loc_keys.add(row["textKey"])

        if node_type == "line" and not row["next"]:
            errors.append(f"nodes.csv:{index}: line node '{node_id}' must provide next")

        condition = row["condition"]
        if condition:
            used_conditions.add(condition)
            if not COND_TOKEN_RE.match(condition):
                warnings.append(f"nodes.csv:{index}: condition '{condition}' contains unusual characters")

    if "start" not in node_ids:
        errors.append("nodes.csv: missing required start node id 'start'")

    choice_pairs: Set[Tuple[str, str]] = set()
    nodes_with_choices: Set[str] = set()

    for index, row in enumerate(choices, start=2):
        node_id = row["nodeId"]
        choice_id = row["choiceId"]
        next_id = row["next"]
        text_key = row["textKey"]

        if not node_id:
            errors.append(f"choices.csv:{index}: nodeId is empty")
        if not choice_id:
            errors.append(f"choices.csv:{index}: choiceId is empty")
        if not text_key:
            errors.append(f"choices.csv:{index}: textKey is empty")
        if not next_id:
            errors.append(f"choices.csv:{index}: next is empty for choice '{choice_id}'")

        key = (node_id, choice_id)
        if key in choice_pairs:
            errors.append(f"choices.csv:{index}: duplicate choice '{choice_id}' under node '{node_id}'")
        choice_pairs.add(key)

        if node_id and node_id not in node_ids:
            errors.append(f"choices.csv:{index}: nodeId '{node_id}' not found in nodes.csv")
        if node_id in node_types and node_types[node_id] != "choice":
            errors.append(
                f"choices.csv:{index}: nodeId '{node_id}' is type '{node_types[node_id]}' but choices require type 'choice'"
            )

        if next_id and next_id not in node_ids:
            errors.append(f"choices.csv:{index}: next node '{next_id}' not found in nodes.csv")

        if text_key:
            referenced_loc_keys.add(text_key)

        condition = row["condition"]
        if condition:
            used_conditions.add(condition)
            if not COND_TOKEN_RE.match(condition):
                warnings.append(f"choices.csv:{index}: condition '{condition}' contains unusual characters")

        if node_id:
            nodes_with_choices.add(node_id)

    for node_id, node_type in node_types.items():
        if node_type == "choice" and node_id not in nodes_with_choices:
            errors.append(f"choices.csv: choice node '{node_id}' has no choice rows")

    for index, row in enumerate(nodes, start=2):
        next_id = row["next"]
        if next_id and next_id not in node_ids:
            errors.append(f"nodes.csv:{index}: next node '{next_id}' not found in nodes.csv")

    loc_map: Dict[Tuple[str, str], str] = {}
    languages: Set[str] = set()

    for index, row in enumerate(loc_rows, start=2):
        key = row["key"]
        lang = row["lang"]
        text = row["text"]

        if not key:
            errors.append(f"loc.csv:{index}: key is empty")
            continue
        if not lang:
            errors.append(f"loc.csv:{index}: lang is empty for key '{key}'")
            continue

        pair = (lang, key)
        if pair in loc_map:
            errors.append(f"loc.csv:{index}: duplicate (lang,key)=({lang},{key})")
        loc_map[pair] = text
        languages.add(lang)

    if "en" not in languages:
        errors.append("loc.csv: missing required language 'en'")

    for key in sorted(referenced_loc_keys):
        if not key:
            continue
        if ("en", key) not in loc_map:
            errors.append(f"loc.csv: missing English text for key '{key}'")

    for lang in sorted(languages):
        if lang == "en":
            continue
        for key in sorted(referenced_loc_keys):
            if key and (lang, key) not in loc_map:
                warnings.append(f"loc.csv: missing translation for key '{key}' in lang '{lang}'")

    return errors, warnings


def main() -> int:
    parser = argparse.ArgumentParser(description="Validate dialogue CSV files")
    parser.add_argument("--root", default=None, help="Directory containing nodes.csv/choices.csv/loc.csv")
    args = parser.parse_args()

    root = Path(args.root).resolve() if args.root else Path(__file__).resolve().parent
    errors, warnings = validate(root)

    for message in warnings:
        print(f"[WARN] {message}")

    if errors:
        for message in errors:
            print(f"[ERROR] {message}")
        print(f"\nValidation failed: {len(errors)} error(s), {len(warnings)} warning(s).")
        return 1

    print(f"Validation OK: {len(warnings)} warning(s).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
