/*
 * ── 模块封装（IIFE）────────────────
 *
 * 整个引擎包在 (function() { ... })() 里，叫做 IIFE（立即执行函数表达式）。
 *
 * 为什么要这样做：
 *   JavaScript 里，直接写在 <script> 顶层的 var/let/const 变量是全局的——
 *   所有脚本都能读写它们，容易相互干扰（比如两个脚本都叫 data）。
 *   把代码包在函数里，函数内部的所有变量就变成"私有"，外部看不到。
 *
 * 唯一暴露给外部的是最后赋值给 window.DialogueEngine 的对象——
 * 其他脚本（hud.html、dev-debug.js、Unreal C++ 桥）只能通过
 * DialogueEngine.xxx 来访问引擎的公开方法，内部实现完全隔离。
 */
(function () {
  const START = "start";   // 每次启动或重置时的起始节点 id，CSV 里要有 id=start 的行

  /*
   * 三层状态：
   *
   * rawData  原始 CSV 字符串，loadData 存进来，loadAll / patch* 用它重新解析。
   *          是"数据源头"，热重载时重新解析的就是它。
   *
   * data     解析后的索引结构（Map），每次 loadAll 重建。
   *          用 Map 而不是普通对象 {} 是因为 Map 的键查找更快，
   *          且键可以是任意类型（虽然这里都是字符串）。
   *
   * state    运行时会话状态：当前语言、当前节点 id、变量表。
   *          玩家的每一步操作（选选项、触发事件）都会改变这里。
   *          通过 exportState/importState 可以序列化到存档。
   */
  let rawData = null;
  let data = emptyData();
  const state = { lang: "en", nodeId: START, vars: {} };

  /*
   * 返回一个"空的"数据结构，用作初始值和重置时的模板。
   * Map 类似于对象，区别：Map 的 .get/.set/.has 操作专门为频繁查找优化；
   * 也不会和 Object 原型上的属性名冲突（比如 "constructor"、"toString" 等）。
   */
  function emptyData() {
    return { nodes: new Map(), choices: new Map(), loc: new Map(), languages: [] };
  }

  /*
   * ── CSV 解析器 ─────────────────────
   *
   * 把一个 CSV 文本字符串解析成"对象数组"，每个对象的键是 CSV 表头。
   * 例：
   *   输入："id,type,text\nstart,line,你好"
   *   输出：[{ id: "start", type: "line", text: "你好" }]
   *
   * 为什么自己实现而不用现有库：
   *   标准库没有内置 CSV 解析；引入第三方库会增加外部依赖，
   *   而这里的需求很明确（只需要符合 RFC 4180 的 CSV），自己写更轻量。
   *
   * RFC 4180 规则（主要的）：
   *   逗号分隔字段；字段可以用双引号包裹（允许字段内含逗号和换行）；
   *   双引号内的 "" 表示一个字面引号字符。
   *
   * 实现方式：逐字符扫描（状态机）。
   *   inQuotes 标记当前是否在引号字符串内——在引号内时，逗号和换行不作为分隔符。
   */
  function parseCsv(raw) {
    const rows = [];
    let row = [], cell = "", inQuotes = false;
    for (let i = 0; i < raw.length; i++) {
      const currentChar = raw[i], nextChar = raw[i + 1];
      // 引号内的 "" → 代表一个字面引号，跳过第二个引号继续
      if (currentChar === '"' && inQuotes && nextChar === '"') { cell += '"'; i++; continue; }
      // 单个引号 → 切换"在引号内/外"状态
      if (currentChar === '"')                                  { inQuotes = !inQuotes; continue; }
      // 逗号且不在引号内 → 当前单元格结束，开始下一个
      if (currentChar === ","  && !inQuotes) { row.push(cell); cell = ""; continue; }
      // 换行且不在引号内 → 当前行结束，\r\n 算一个换行
      if ((currentChar === "\n" || currentChar === "\r") && !inQuotes) {
        if (currentChar === "\r" && nextChar === "\n") i++;   // 跳过 \n，避免读两次
        row.push(cell); rows.push(row); row = []; cell = "";
        continue;
      }
      cell += currentChar;   // 普通字符，追加到当前单元格
    }
    // 文件末尾可能没有换行，把最后一行也加进去
    if (cell || row.length) { row.push(cell); rows.push(row); }

    // 第一行是表头，shift() 把它取出来；剩下的行转成 {表头: 值} 对象
    const headers = rows.shift().map(h => h.trim());
    return rows
      .filter(rowValues => rowValues.some(value => value.trim()))   // 跳过全空行
      .map(rowValues => Object.fromEntries(                          // 数组 → 对象
        headers.map((header, i) => [header, (rowValues[i] ?? "").trim()])
      ));
  }

  /*
   * ── 数据索引构建 ───────────────────
   *
   * 把三张 CSV 解析后的行数组，建成三个 Map 以便 O(1) 速度查找：
   *
   * nodes Map：    id → 节点行对象          （可直接 nodes.get("start")）
   * choices Map：  nodeId → [选项行, ...]   （一个节点可以有多个选项）
   * loc Map：      "lang:key" → 翻译文本    （"zh:speaker_alice" → "爱丽丝"）
   *
   * 同时收集所有语言代码，如果当前语言不在新数据里，降级到第一个可用语言。
   */
  function buildData(nodeRows, choiceRows, locRows) {
    const indexedData = emptyData();
    nodeRows.forEach(nodeRow => indexedData.nodes.set(nodeRow.id, nodeRow));
    choiceRows.forEach(choiceRow => {
      // 一个节点可能对应多个选项，所以用数组存
      const choiceList = indexedData.choices.get(choiceRow.nodeId) ?? [];   // ?? 是空合并，左边 null/undefined 时取右边
      choiceList.push(choiceRow);
      indexedData.choices.set(choiceRow.nodeId, choiceList);
    });
    const langSet = new Set();   // Set 自动去重，适合收集不重复的语言代码
    locRows.forEach(locRow => {
      indexedData.loc.set(`${locRow.lang}:${locRow.key}`, locRow.text);   // 模板字符串拼 key
      langSet.add(locRow.lang);
    });
    indexedData.languages = [...langSet];   // Set 转 Array（... 是展开运算符）
    // 当前语言不在新数据里时，降级到第一个语言，防止翻译全部显示 [key]
    if (!indexedData.languages.includes(state.lang)) state.lang = indexedData.languages[0] ?? "en";
    return indexedData;
  }

  /*
   * ── 翻译函数
   *
   * 用 "lang:key" 格式在 loc Map 里查找文本。
   * 三级降级：当前语言 → 英语 → "[key]"（明显的占位符，方便发现漏翻译）。
   * ?? 运算符：左边不是 null/undefined 时取左边，否则取右边（短路求值）。
   */
  function translate(key) {
    return key
      ? data.loc.get(`${state.lang}:${key}`) ?? data.loc.get(`en:${key}`) ?? `[${key}]`
      : "";
  }

  /*
   * 读取变量表里的值，并把字符串自动转换为合适的类型。
   * hasOwnProperty 安全检查：只读自身属性，不读原型链上的属性。
   */
  function readVar(name, fallback = undefined) {
    const value = Object.prototype.hasOwnProperty.call(state.vars, name) ? state.vars[name] : fallback;
    return parseValue(value);
  }

  /*
   * 把一个值判断为"真"或"假"，用于条件表达式。
   * 规则：true 是真；数字非 0 是真；其他值按 JS 的 !! 转换（空字符串、null、undefined 为假）。
   */
  function truthy(value) {
    return value === true || (typeof value === "number" ? value !== 0 : !!value);
  }

  /*
   * 比较两个值，支持 == != >= <= > < 六种运算符。
   * 如果两边都是数字，就做数值比较；否则转成字符串做字典序比较。
   * 这让 CSV 里写 score >= 3 或 route == "forest" 都能正确工作。
   */
  function compareValues(left, op, right) {
    const bothNumeric = typeof left === "number" && typeof right === "number";
    const a = bothNumeric ? left : String(left ?? "");
    const b = bothNumeric ? right : String(right ?? "");
    switch (op) {
      case "==": return a == b;
      case "!=": return a != b;
      case ">=": return a >= b;
      case "<=": return a <= b;
      case ">":  return a > b;
      case "<":  return a < b;
      default:   return false;
    }
  }

  /*
   * ── 条件表达式解析器 
   * CSV 里 condition 列可以写简单条件，比如：
   *   metBob                     → 变量 metBob 为真
   *   !angry                     → 变量 angry 为假
   *   trust >= 3                 → 变量 trust 大于等于 3
   *   route == "forest"          → 变量 route 等于字符串 "forest"
   *   metBob && trust >= 3       → 两个条件同时满足
   *   tired || hungry            → 任一条件满足
   *   (a || b) && c              → 括号改变优先级
   *
   * 实现分两步：
   *   1. tokenizeCondition：把字符串切成 token（词）列表
   *   2. evalCondition：用递归下降解析器求值
   */

  /*
   * 词法分析：把条件字符串切成 token 列表。
   * 结果例：'trust >= 3 && !angry' → [{ name:'trust' }, '>=', 3, '&&', '!', { name:'angry' }]
   *
   * Token 类型：
   *   { name: "变量名" } → 变量名（需要去 state.vars 里查）
   *   字符串字面量       → 直接是字符串（从引号之间提取）
   *   数字字面量         → 已转为 Number
   *   运算符字符串       → "&&" "||" "==" "!=" ">=" "<=" ">" "<" "!" "(" ")"
   */
  function tokenizeCondition(expr) {
    const tokens = [];
    const isName = c => /[A-Za-z0-9_.:-]/.test(c);   // 变量名允许的字符集
    for (let i = 0; i < expr.length;) {
      if (/\s/.test(expr[i])) { i++; continue; }   // 跳过空白 
      const two = expr.slice(i, i + 2);
      if (["&&", "||", "==", "!=", ">=", "<="].includes(two)) { tokens.push(two); i += 2; continue; }
      if ("()!<>".includes(expr[i])) { tokens.push(expr[i++]); continue; }
      if (expr[i] === '"' || expr[i] === "'") {   // 字符串字面量
        const quote = expr[i++];
        let value = "";
        while (i < expr.length && expr[i] !== quote) value += expr[i++];
        if (expr[i++] !== quote) throw new Error(`Bad condition: ${expr}`);
        tokens.push(value);
        continue;
      }
      if (/-?\d/.test(expr[i])) {   // 数字字面量（支持负数）
        let value = "";
        while (i < expr.length && /[-\d.]/.test(expr[i])) value += expr[i++];
        tokens.push(Number(value));
        continue;
      }
      if (/[A-Za-z_]/.test(expr[i])) {   // 变量名（以字母或下划线开头）
        let name = "";
        while (i < expr.length && isName(expr[i])) name += expr[i++];
        tokens.push({ name });   // 包成对象，与字符串字面量区分
        continue;
      }
      throw new Error(`Bad condition: ${expr}`);
    }
    return tokens;
  }

  /*
   * 语法分析 + 求值：递归下降解析器。
   *
   * 按运算符优先级分层（优先级低的函数调用高的，高的先求值）：
   *   orExpr    → 处理 ||，优先级最低
   *   andExpr   → 处理 &&
   *   comparison → 处理 == != >= <= > <
   *   unary     → 处理 !（一元取反）
   *   primary   → 处理括号和原子值（变量/字面量）
   *
   * 这种结构天然保证了 && 比 || 优先级高，括号最高。
   */
  function evalCondition(expr) {
    const tokens = tokenizeCondition(expr);
    let pos = 0;                                    // 当前读到哪个 token
    const peek = () => tokens[pos];                 // 看下一个但不消费
    const take = token => peek() === token && (pos++, true);  // 如果下一个是 token 就消费

    function primary(nameFallback) {
      if (take("(")) {
        const value = orExpr();
        if (!take(")")) throw new Error(`Bad condition: ${expr}`);
        return value;
      }
      const token = tokens[pos++];
      // { name } 对象是变量名，去 vars 里读取
      if (token && typeof token === "object") return readVar(token.name, nameFallback ? token.name : undefined);
      if (token !== undefined) return token;   // 字面量（字符串/数字）直接返回
      throw new Error(`Bad condition: ${expr}`);
    }

    function unary(nameFallback) {
      // take("!") 消费掉 ! 并递归处理后面的值，再取反
      return take("!") ? !truthy(unary(nameFallback)) : primary(nameFallback);
    }

    function comparison() {
      let left = unary(false);
      if (["==", "!=", ">=", "<=", ">", "<"].includes(peek())) {
        const op = tokens[pos++];
        left = compareValues(left, op, unary(true));
      }
      return left;
    }

    function andExpr() {
      let value = truthy(comparison());
      // 短路求值：JS 的 && 右边不求值如果左边已经是 false，但这里是文本条件语言，都求了
      while (take("&&")) value = truthy(comparison()) && value;
      return value;
    }

    function orExpr() {
      let value = truthy(andExpr());
      while (take("||")) value = truthy(andExpr()) || value;
      return value;
    }

    const result = orExpr();
    // 如果还有剩余 token，说明表达式语法有问题
    if (pos !== tokens.length) throw new Error(`Bad condition: ${expr}`);
    return result;
  }

  /*
   * 检查一行数据（节点或选项）是否"允许"进入。
   * 没有 condition 字段 → 无条件允许。
   * 有 condition → 用 evalCondition 求值；表达式出错时报错并返回 false（阻止进入）。
   * 用于：enter() 检查节点条件、choices() 过滤不满足条件的选项。
   */
  function allowed(row) {
    if (!row.condition) return true;
    try { return truthy(evalCondition(row.condition)); }
    catch (e) { engineApi.onError?.(e.message); return false; }
  }

  /*
   * 把 CSV 里的字符串值转换为合适的 JS 类型：
   *   "true"/"false" → Boolean
   *   数字字符串 → Number
   *   其他 → 保持字符串
   */
  function parseValue(value) {
    if (value === "true") return true;
    if (value === "false") return false;
    return value !== "" && !Number.isNaN(Number(value)) ? Number(value) : value;
  }

  /*
   * 执行节点或选项的 effect 字段，格式：key=value; key2=value2
   * 例："met_alice=true; trust=3; route=forest"
   * 分号分割，解析每对 key=value 并写入 state.vars。
   */
  function applyEffect(effect) {
    if (!effect) return;
    effect.split(";").forEach(part => {
      const [key, ...rest] = part.split("=");   // 用 ...rest 兼容值里含 = 的情况
      if (key?.trim()) state.vars[key.trim()] = parseValue(rest.join("=").trim());
    });
  }

  /*
   * 触发一个具名事件，通知外部（HUD/Unreal）。
   * 用可选链 ?. 安全调用：onEvent 没赋值时直接跳过，不报错。
   */
  function fire(name, source, currentCtx) {
    if (name) engineApi.onEvent?.(name, source, currentCtx);
  }

  /*
   * 把存档数据（对象或 JSON 字符串）规范化为引擎接受的格式。
   * 防御性处理：字段缺失或类型错误时用安全默认值，不让残破的存档导致崩溃。
   */
  function normalizeStateSnapshot(input) {
    let source = input;
    if (typeof source === "string") {
      try { source = JSON.parse(source); }
      catch { return null; }
    }
    if (!source || typeof source !== "object") return null;

    const vars = (source.vars && typeof source.vars === "object") ? source.vars : {};
    return {
      nodeId: (typeof source.nodeId === "string" && source.nodeId) ? source.nodeId : START,
      lang: (typeof source.lang === "string" && source.lang) ? source.lang : "en",
      vars: { ...vars },   // 浅拷贝，防止外部修改影响内部状态
    };
  }

  function applyStateSnapshot(snapshot) {
    state.nodeId = snapshot.nodeId;
    state.lang = snapshot.lang;
    state.vars = { ...snapshot.vars };
  }

  /*
   * ── ctx 上下文对象
   *
   * 每次调用回调（onNodeChange / onLoad / ...）时都会构建这个对象传出去。
   * 对外暴露只读的工具函数，不直接暴露 state/data（防止外部随意修改内部状态）。
   *
   *   t(key)          → 翻译当前语言的文本
   *   enter(id)       → 跳转到一个节点
   *   choose(c)       → 确认一个选项
   *   state           → 当前状态的浅拷贝（只读快照）
   *   choices(nodeId) → 返回该节点过滤后的选项数组
   *   languages       → 所有可用语言列表
   */
  function ctx() {
    return {
      t: translate,
      enter,
      choose,
      state: { ...state },                                              // 浅拷贝，外部改不了内部
      choices: nodeId => (data.choices.get(nodeId) ?? []).filter(allowed),
      languages: [...data.languages],
    };
  }

  /*
   * 玩家选了一个选项时的处理流程：
   *   1. 执行选项的 effect（改变变量）
   *   2. 触发选项的 event（通知 Unreal 等外部）
   *   3. 进入选项指向的下一节点
   */
  function choose(choiceRow) {
    applyEffect(choiceRow.effect);
    fire(choiceRow.event);
    enter(choiceRow.next);
  }

  /*
   * ── enter：引擎的核心前进函数
   *
   * 每次切换到一个节点都经过这里，流程：
   *   1. 查找节点是否存在，不存在 → 报错
   *   2. 检查节点 condition，不满足 → 触发 onBlocked，停在原地
   *   3. 更新 state.nodeId
   *   4. 执行节点的 effect（改变变量）
   *   5. 触发节点的 event
   *   6. 调用 onNodeChange → HUD 重新渲染
   *
   * 调用者：choose、loadAll（初始进入）、jumpToNode、HUD 通过 ctx.enter
   */
  function enter(id) {
    const node = data.nodes.get(id);
    if (!node)           return engineApi.onError?.(`Missing node: ${id}`);
    if (!allowed(node))  return engineApi.onBlocked?.(node.condition, node);
    state.nodeId = id;
    applyEffect(node.effect);
    const currentCtx = ctx();
    fire(node.event, node, currentCtx);
    engineApi.onNodeChange?.(node, currentCtx);
  }

  /*
   * 全量重新解析 rawData 并重新进入当前节点。
   * 每次 loadData 或 patch* 后调用，保证热重载时数据是最新的。
   * onLoad 先触发（HUD 用来填充语言列表），然后 enter 再更新对话内容。
   */
  function loadAll() {
    data = buildData(
      parseCsv(rawData.nodes),
      parseCsv(rawData.choices),
      parseCsv(rawData.loc)
    );
    engineApi.onLoad?.(ctx());
    // 优先重新进入上一次的节点（保存/热重载场景）；节点不存在时从头开始
    enter(data.nodes.has(state.nodeId) ? state.nodeId : START);
  }

  /*
   * ── 公开 API（window.DialogueEngine）
   *
   * 赋值给 window.DialogueEngine 使其成为全局变量，所有脚本都能访问。
   * window 上的属性就是全局变量：window.foo 等同于直接写 foo。
   *
   * 分两类：
   *   回调属性（初始为 null）：外部（hud.html、dev-debug.js）赋值后，引擎在合适时机调用。
   *   方法：由外部（Unreal C++ 桥、预览脚本、hud.html 的 UI 事件）主动调用。
   */
  const engineApi = window.DialogueEngine = {

    // ── 回调（赋值后引擎自动调用）
    onLoad:       null,   // (ctx) → loadData 完成后调一次；HUD 用来填充语言列表
    onNodeChange: null,   // (node, ctx) → 每次节点切换；HUD 用来渲染对话内容
    onEvent:      null,   // (name, sourceRow, ctx) → 节点/选项有 event 字段时触发
    onError:      null,   // (msg) → 找不到节点或引擎内部错误
    onBlocked:    null,   // (condition, node) → 节点 condition 不满足；HUD 保持当前内容

    /*
     * 主入口：Unreal / Unity 把三张 CSV 的文本内容传进来。
     * initialState 可选，传存档时的 { nodeId, lang, vars }（对象或 JSON 字符串）。
     */
    loadData(nodesCSV, choicesCSV, locCSV, initialState) {
      rawData = { nodes: nodesCSV, choices: choicesCSV, loc: locCSV };
      if (initialState != null) {
        const snapshot = normalizeStateSnapshot(initialState);
        if (!snapshot) return engineApi.onError?.("Invalid initial state payload");
        applyStateSnapshot(snapshot);
      }
      loadAll();
    },

    /*
     * 热重载：单独更新一张表，不需要重传其他两张。
     * 用于 Unreal / Unity 监听到 CSV 文件变动时实时刷新内容。
     */
    patchNodes(csv)   { rawData.nodes   = csv; loadAll(); },
    patchChoices(csv) { rawData.choices = csv; loadAll(); },
    patchLoc(csv)     { rawData.loc     = csv; loadAll(); },

    /*
     * 直接跳到任意节点，绕过 choose()，不触发选项的 effect 和 event。
     * 用于剧情触发器、任务标志等外部直接跳转的情况。
     */
    jumpToNode(id) { enter(id); },

    /*
     * 切换语言并用新语言重新渲染当前节点（不跳转，只刷新文本）。
     * 从 HUD 的语言下拉框触发。
     */
    setLanguage(lang) {
      state.lang = lang;
      engineApi.onNodeChange?.(data.nodes.get(state.nodeId), ctx());
    },

    // 快捷写布尔变量（比 setVar 语义更明确）
    setFlag(key, value) { state.vars[key] = !!value; },   // !! 强制转 Boolean

    // 写入/读取条件变量，供条件表达式使用
    setVar(key, val) { state.vars[key] = val; },
    getVar(key)      { return state.vars[key]; },

    /*
     * 序列化当前状态为 JSON 字符串，供 Unreal / Unity 存档系统保存。
     * 读出来的数据包含恢复进度所需的一切：在哪个节点、什么语言、所有变量值。
     */
    exportState() {
      return JSON.stringify({
        nodeId: state.nodeId,
        lang: state.lang,
        vars: { ...state.vars },   // 浅拷贝，防止外部改动影响内部 对象展开运算符{ ...obj } 创建了 obj 的一个浅拷贝  
      });
    },

    /*
     * 从存档恢复状态。接受对象或 JSON 字符串。
     * 如果数据已经加载，立即重新进入对应节点；如果数据还没加载，
     * 状态会在后续 loadData 时自动生效（loadAll 检查 state.nodeId）。
     */
    importState(snapshotLike) {
      const snapshot = normalizeStateSnapshot(snapshotLike);
      if (!snapshot) return engineApi.onError?.("Invalid state payload");
      applyStateSnapshot(snapshot);
      if (data.nodes.size) enter(data.nodes.has(state.nodeId) ? state.nodeId : START);
    },

    // 返回当前状态的只读快照，供外部检查（不要直接修改返回值）
    getState() { return { ...state }; },
  };
})();
