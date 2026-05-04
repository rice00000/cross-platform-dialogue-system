// ── simple CSV parser (no quoted-comma support needed for file paths / keys) ──
function parsePresentation(raw) {
  const lines = raw.split(/\r?\n/).filter(l => l.trim() && !l.startsWith("#"));
  if (!lines.length) return { speakerPortrait: new Map(), nodeAudio: new Map() };
  const headers = lines.shift().split(",").map(h => h.trim());
  const rows = lines.map(line => {
    const vals = line.split(",").map(v => v.trim());
    return Object.fromEntries(headers.map((h, i) => [h, vals[i] ?? ""]));
  });
  const speakerPortrait = new Map();
  const nodeAudio       = new Map();
  rows.forEach(r => {
    if (r.speakerKey && r.portrait) speakerPortrait.set(r.speakerKey, r.portrait);
    if (r.nodeId     && r.audio)    nodeAudio.set(r.nodeId, r.audio);
  });
  return { speakerPortrait, nodeAudio };
}

// Wraps the onNodeChange already installed by hud.html.
// Injects portrait (from speakerPortrait) into node before forwarding,
// and plays audio (from nodeAudio) — both without touching hud.html or the engine.
function installPresentationBridge(speakerPortrait, nodeAudio) {
  const audioEl = Object.assign(document.createElement("audio"), { id: "pres-audio" });
  document.body.appendChild(audioEl);

  const orig = DialogueEngine.onNodeChange;
  DialogueEngine.onNodeChange = (node, ctx) => {
    const portrait = speakerPortrait.get(node.speakerKey);
    orig?.(portrait ? { ...node, portrait } : node, ctx);

    const audio = nodeAudio.get(node.id);
    if (audio) {
      audioEl.src = audio;
      audioEl.currentTime = 0;
      audioEl.play().catch(() => {});
    }
  };
}

async function bootDialoguePreview() {
  new URLSearchParams(location.search).get("vars")?.split(",").forEach(pair => {
    const [k, v] = pair.split(":");
    DialogueEngine.setVar(k, v === "true" ? true : v === "false" ? false : v);
  });

  try {
    const noCache = { cache: "no-store" };
    const [nodes, choices, loc, presRaw] = await Promise.all([
      fetch("nodes.csv",                                      noCache).then(r => r.text()),
      fetch("choices.csv",                                    noCache).then(r => r.text()),
      fetch("loc.csv",                                        noCache).then(r => r.text()),
      fetch("web_only_dialogue_bridge/presentation.csv",      noCache).then(r => r.text()).catch(() => ""),
    ]);

    // install bridge BEFORE loadData — loadData fires onNodeChange immediately
    const { speakerPortrait, nodeAudio } = parsePresentation(presRaw);
    installPresentationBridge(speakerPortrait, nodeAudio);

    DialogueEngine.loadData(nodes, choices, loc);
  } catch (e) {
    DialogueEngine.onError?.(e.message);
  }
}

bootDialoguePreview();
