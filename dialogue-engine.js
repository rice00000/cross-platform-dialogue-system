(function () {
  const START = "start";
  let data = emptyData();
  const state = { lang: "en", nodeId: START, vars: {} };

  function emptyData() {
    return { nodes: new Map(), choices: new Map(), loc: new Map(), languages: [] };
  }

  // RFC-4180: quoted fields, escaped double-quotes, CRLF
  function parseCsv(raw) {
    const rows = [];
    let row = [], cell = "", q = false;
    for (let i = 0; i < raw.length; i++) {
      const c = raw[i], nx = raw[i + 1];
      if (c === '"' && q && nx === '"') { cell += '"'; i++; continue; }
      if (c === '"')                    { q = !q;       continue; }
      if (c === ","  && !q) { row.push(cell); cell = ""; continue; }
      if ((c === "\n" || c === "\r") && !q) {
        if (c === "\r" && nx === "\n") i++;
        row.push(cell); rows.push(row); row = []; cell = "";
        continue;
      }
      cell += c;
    }
    if (cell || row.length) { row.push(cell); rows.push(row); }
    const hdrs = rows.shift().map(h => h.trim());
    return rows
      .filter(r => r.some(v => v.trim()))
      .map(r => Object.fromEntries(hdrs.map((h, i) => [h, (r[i] ?? "").trim()])));
  }

  function buildData(nodeRows, choiceRows, locRows) {
    const d = emptyData();
    nodeRows.forEach(r => d.nodes.set(r.id, r));
    choiceRows.forEach(r => {
      const list = d.choices.get(r.nodeId) ?? [];
      list.push(r);
      d.choices.set(r.nodeId, list);
    });
    locRows.forEach(r => {
      d.loc.set(`${r.lang}:${r.key}`, r.text);
      if (!d.languages.includes(r.lang)) d.languages.push(r.lang);
    });
    if (!d.languages.includes(state.lang)) state.lang = d.languages[0] ?? "en";
    return d;
  }

  function t(key) {
    return key
      ? data.loc.get(`${state.lang}:${key}`) ?? data.loc.get(`en:${key}`) ?? `[${key}]`
      : "";
  }

  function allowed(row) {
    return !row.condition || window.DialogueHooks.condition(row.condition, state);
  }

  function fire(name) {
    if (name) window.DialogueHooks.event(name, state);
  }

  function ctx() {
    return {
      t,
      enter,
      choose,
      state: { ...state },
      choices: id => (data.choices.get(id) ?? []).filter(allowed),
      languages: [...data.languages],
    };
  }

  function choose(c) {
    fire(c.event);
    enter(c.next);
  }

  function enter(id) {
    const node = data.nodes.get(id);
    if (!node)           return E.onError?.(`Missing node: ${id}`);
    if (!allowed(node))  return E.onError?.(`Blocked: ${node.condition}`);
    state.nodeId = id;
    fire(node.event);
    E.onRender?.(node, ctx());
  }

  function loadAll() {
    data = buildData(
      parseCsv(window.DialogueData.nodes),
      parseCsv(window.DialogueData.choices),
      parseCsv(window.DialogueData.loc)
    );
    E.onLoad?.(ctx());
    enter(data.nodes.has(state.nodeId) ? state.nodeId : START);
  }

  const E = window.DialogueEngine = {
    // ── Callbacks — assign before calling load() ──────────────────────────────
    onLoad:   null,   // (ctx) => void        fires once after CSV parse
    onRender: null,   // (node, ctx) => void  fires on every node transition
    onError:  null,   // (msg) => void        fires on missing / blocked node

    // ── Lifecycle ─────────────────────────────────────────────────────────────
    async load() {
      window.DialogueHooks ??= {
        condition: () => false,
        event: (n, s) => console.log("[dialogue:event]", n, s),
      };
      if (!window.DialogueData) {
        const [nodes, choices, loc] = await Promise.all([
          fetch("nodes.csv").then(r => r.text()),
          fetch("choices.csv").then(r => r.text()),
          fetch("loc.csv").then(r => r.text()),
        ]);
        window.DialogueData = { nodes, choices, loc };
      }
      loadAll();
    },

    // ── Unity / UE bridge ─────────────────────────────────────────────────────
    loadData(nodesCSV, choicesCSV, locCSV) {
      window.DialogueData = { nodes: nodesCSV, choices: choicesCSV, loc: locCSV };
      loadAll();
    },
    patchNodes(csv)   { window.DialogueData.nodes   = csv; loadAll(); },
    patchChoices(csv) { window.DialogueData.choices = csv; loadAll(); },
    patchLoc(csv)     { window.DialogueData.loc     = csv; loadAll(); },
    jumpToNode(id)    { enter(id); },
    setLanguage(lang) { state.lang = lang; E.onRender?.(data.nodes.get(state.nodeId), ctx()); },
    setVar(key, val)  { state.vars[key] = val; },
    getVar(key)       { return state.vars[key]; },
    getState()        { return { ...state }; },
  };
})();
