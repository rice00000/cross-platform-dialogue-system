# Cross-Platform Dialogue System

Lightweight dialogue UI for browser, Unity WebGL, and Unreal WebBrowserWidget.  
No dependencies. CSV-driven. Engine-agnostic.

## File Structure

```
dialogue-engine.js   core logic — CSV parsing, node traversal, state
index.html           standalone debug UI (with debug panel)
hud.html             game overlay UI (portrait, no debug panel)
nodes.csv            node graph
choices.csv          choice rows
loc.csv              localization strings
```

---

## DialogueEngine — Interface

### Callbacks (assign before `load()`)

| Callback | Signature | When |
|---|---|---|
| `onLoad` | `(ctx) => void` | once after CSV parse |
| `onRender` | `(node, ctx) => void` | every node transition |
| `onError` | `(msg) => void` | missing or blocked node |

### `ctx` object passed to callbacks

| Field | Type | Description |
|---|---|---|
| `t(key)` | `string` | localized text lookup |
| `enter(id)` | `fn` | jump to a node |
| `choose(c)` | `fn` | fire choice event + enter next |
| `choices(id)` | `fn → array` | condition-filtered choices for a node |
| `state` | `object` | `{ lang, nodeId, vars }` snapshot |
| `languages` | `string[]` | all langs found in loc.csv |

### Runtime methods (Unity / UE bridge)

```js
DialogueEngine.loadData(nodesCSV, choicesCSV, locCSV)  // replace all tables
DialogueEngine.patchNodes(csv)                          // hot-swap one table
DialogueEngine.patchChoices(csv)
DialogueEngine.patchLoc(csv)
DialogueEngine.jumpToNode(id)
DialogueEngine.setLanguage(lang)
DialogueEngine.setVar(key, val)
DialogueEngine.getVar(key)
DialogueEngine.getState()                               // → { lang, nodeId, vars }
```

---

## Wiring up a new HTML

```html
<script src="dialogue-engine.js"></script>
<script>
  DialogueEngine.onLoad = ({ languages, state }) => {
    // populate language selector once
  };

  DialogueEngine.onRender = (node, { t, enter, choose, choices }) => {
    document.getElementById("speaker").textContent = t(node.speakerKey);
    document.getElementById("text").textContent    = t(node.textKey);
    // build choice buttons, wire next/restart button, etc.
  };

  DialogueEngine.onError = msg => { /* show error in your UI */ };

  DialogueEngine.load().catch(e => DialogueEngine.onError(e.message));
</script>
```

---

## Engine Injection (Unity / UE)

Assign `window.DialogueData` **before** the page script runs to skip the CSV fetch entirely:

```js
// UE Blueprint → ExecuteJavascript
window.DialogueData = { nodes: "...", choices: "...", loc: "..." };

// Unity C# WebGL
gameInstance.SendMessage("JSBridge", "SetData", JSON.stringify({ nodes, choices, loc }));
```

Or push data after load via the bridge:

```js
DialogueEngine.loadData(nodesCSV, choicesCSV, locCSV);
```

Override condition / event hooks before page load:

```js
window.DialogueHooks = {
  condition: (name, state) => state.vars[name] === true,
  event:     (name, state) => UnrealCallback(name, JSON.stringify(state)),
};
```

---

## Local Preview

Requires an HTTP server (`fetch` is blocked on `file://`):

```
python -m http.server
# then open http://localhost:8000/index.html
```
