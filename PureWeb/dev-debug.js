// dev-debug.js — debug overlay for the dialogue HUD.
// Loaded only when hud.html is opened with ?debug.
// Wraps DialogueEngine.* callbacks instead of touching hud.html.
(function () {
  // ── styles (scoped via #debug-* / .dbg-* / .tag-* selectors) ───
  const css = `
    #debug-panel {
      position: fixed;
      top: 10px; right: 10px;
      width: 320px; max-height: 240px;
      overflow-y: auto;
      padding: 6px 8px;
      background: rgba(0, 0, 0, 0.75);
      border: 1px solid rgba(255, 255, 255, 0.15);
      border-radius: 4px;
      font: 11px/1.5 "Consolas", "Menlo", monospace;
      pointer-events: auto;
      z-index: 200;
      display: none;
    }
    #debug-panel.visible { display: block; }
    #debug-panel .dbg-row { display: flex; gap: 6px; padding: 2px 0; border-bottom: 1px solid rgba(255,255,255,0.06); }
    #debug-panel .dbg-row:last-child { border-bottom: none; }
    #debug-panel .dbg-time { color: #666; flex-shrink: 0; }
    #debug-panel .dbg-tag  { flex-shrink: 0; font-weight: 700; }
    #debug-panel .dbg-msg  { color: #cdd; word-break: break-all; }
    .tag-block { color: #ff8c42; }
    .tag-err   { color: #ff6b6b; }
    .tag-event { color: var(--green, #7bd88f); }
    #debug-panel .dbg-toolbar {
      display: flex; justify-content: space-between; align-items: center;
      gap: 6px;
      margin-bottom: 4px; padding-bottom: 4px;
      border-bottom: 1px solid rgba(255,255,255,0.12);
      color: #888; font-size: 10px;
    }
    .dbg-toolbar-actions { display: flex; gap: 6px; align-items: center; }
    .dbg-clear { font: inherit; font-size: 10px; color: #888; background: none; border: none; cursor: pointer; }
    .dbg-clear:hover { color: #ccc; }
    .dbg-back {
      font: inherit; font-size: 10px;
      padding: 0 6px;
      color: var(--gold, #f2bf5e);
      background: none;
      border: 1px solid rgba(242,191,94,0.25);
      border-radius: 2px;
      cursor: pointer;
    }
    .dbg-back:hover { color: #f9d98a; }
    .dbg-back:disabled { color: #444; border-color: rgba(255,255,255,0.08); cursor: default; }

    #debug-toggle {
      position: fixed;
      top: 10px; right: 10px;
      padding: 3px 8px;
      font: 11px "Consolas", monospace;
      color: #888;
      background: rgba(0,0,0,0.60);
      border: 1px solid rgba(255,255,255,0.12);
      border-radius: 3px;
      cursor: pointer;
      pointer-events: auto;
      z-index: 201;
    }
    #debug-toggle:hover { color: #ccc; }
  `;
  const styleEl = document.createElement("style");
  styleEl.textContent = css;
  document.head.append(styleEl);

  document.body.insertAdjacentHTML("beforeend", `
    <button id="debug-toggle">DBG</button>
    <div id="debug-panel">
      <div class="dbg-toolbar">
        <span>Dialogue Debug</span>
        <div class="dbg-toolbar-actions">
          <button class="dbg-back" disabled title="Back to previous choice">↩ Back</button>
          <button class="dbg-clear" data-act="clear">clear</button>
          <button class="dbg-clear" data-act="close">close</button>
        </div>
      </div>
      <div id="debug-log"></div>
    </div>
  `);

  const panel   = document.getElementById("debug-panel");
  const log     = document.getElementById("debug-log");
  const toggle  = document.getElementById("debug-toggle");
  const backBtn = panel.querySelector(".dbg-back");

  // ── state ──────────────────────────────────────────────────────
  let userClosed   = false; // suppresses auto-reopen on subsequent logs once user clicks close
  let _enterRef    = null;  // latest enter() captured from onNodeChange
  const _choiceStack = []; // ids of choice nodes visited
  const STACK_CAP = 64;
  const LOG_CAP   = 150;

  // ── panel visibility ───────────────────────────────────────────
  function setOpen(open) {
    panel.classList.toggle("visible", open);
    toggle.style.display = open ? "none" : "";
  }
  toggle.onclick = () => {
    const opening = !panel.classList.contains("visible");
    if (opening) userClosed = false;
    setOpen(opening);
  };
  panel.querySelector('[data-act="clear"]').onclick = () => { log.innerHTML = ""; };
  panel.querySelector('[data-act="close"]').onclick = () => { userClosed = true; setOpen(false); };

  // ── log a row, auto-open panel only if user hasn't explicitly closed ──
  function dbgLog(tag, tagClass, msg) {
    if (log.childElementCount > LOG_CAP) log.firstElementChild?.remove();
    const now = new Date();
    const ts = `${String(now.getMinutes()).padStart(2,"0")}:${String(now.getSeconds()).padStart(2,"0")}`;
    const row = document.createElement("div");
    row.className = "dbg-row";
    [["dbg-time", ts], [`dbg-tag ${tagClass}`, tag], ["dbg-msg", msg]].forEach(([cls, txt]) => {
      const s = document.createElement("span");
      s.className = cls;
      s.textContent = txt;
      row.append(s);
    });
    log.append(row);
    if (!panel.classList.contains("visible") && !userClosed) setOpen(true);
    if (panel.classList.contains("visible")) panel.scrollTop = panel.scrollHeight;
  }

  // ── back button: replay engine.enter on the previous choice node ─
  backBtn.onclick = () => {
    _choiceStack.pop();                                   // drop current choice id
    const prev = _choiceStack[_choiceStack.length - 1];
    if (prev === undefined) return;
    _choiceStack.pop();   // wrapped onNodeChange will re-push when we land on it
    if (_enterRef) _enterRef(prev);
  };

  // ── wrap engine callbacks (preserve originals from hud.html) ────
  const origNode    = DialogueEngine.onNodeChange;
  const origEvent   = DialogueEngine.onEvent;
  const origBlocked = DialogueEngine.onBlocked;
  const origError   = DialogueEngine.onError;

  DialogueEngine.onNodeChange = (node, ctx) => {
    _enterRef = ctx.enter;
    if (node.type === "choice" && _choiceStack[_choiceStack.length - 1] !== node.id) {
      _choiceStack.push(node.id);
      if (_choiceStack.length > STACK_CAP) _choiceStack.shift();
    }
    backBtn.disabled = _choiceStack.length < 2;
    origNode?.(node, ctx);
  };

  DialogueEngine.onEvent = (name, source) => {
    origEvent?.(name, source);
    dbgLog("EVENT", "tag-event", name + (source?.id ? ` (${source.id})` : ""));
  };

  DialogueEngine.onBlocked = (condition, node) => {
    origBlocked?.(condition, node);
    dbgLog("BLOCK", "tag-block", `Blocked: ${condition}` + (node?.id ? ` @ ${node.id}` : ""));
  };

  DialogueEngine.onError = msg => {
    origError?.(msg);
    dbgLog("ERR", "tag-err", msg);
  };
})();
