# DialogueBridge 配置文档

`DialogueBridge` 是 UE 侧桥接插件，负责把 `Content/` 下的 CSV 对话数据注入到 WebBrowserWidget 里的 `hud.html`。对话解析和 UI 仍由 `cross-platform-dialogue-system` 里的 JS 文件负责。

## 最少要怎么配

1. 启用插件
   - `Edit > Plugins` 启用 `Web Browser Widget`
   - 启用本插件 `Dialogue Bridge`
   - 重启 UE

2. 放外部文件到项目 `Content/ExternalData/`

   ```text
   Content/
     ExternalData/
       hud.html
       dialogue-engine.js
       nodes.csv
       choices.csv
       loc.csv
       portraits/        可选，只有当前 Web HUD 用图片路径时需要
   ```

   这些文件来自：

   ```text
   D:\Game_Production\cross-platform-dialogue-system
   ```

   注意：CSV、HTML、JS 要作为真实文件放在 `Content/ExternalData/`，不要只导入成 UE 资产。插件用文件路径读取。

3. 创建 UMG Widget
   - 新建 Widget Blueprint，例如 `WBP_DialogueHud`
   - 添加一个 `Web Browser` 控件，命名为 `DialogueBrowser`
   - 初始 URL 留空，或设为 `about:blank`

4. 初始化顺序
   在持有该 Widget 的 Actor / PlayerController 上添加 `DialogueBridgeComponent`，运行时按这个顺序调用：

   ```text
   Create Widget WBP_DialogueHud
   Add To Viewport
   Get DialogueBrowser
   DialogueBridgeComponent.Init(
     Browser = DialogueBrowser,
     HudHtmlRelPath = "ExternalData/hud.html",
     NodesCsvRelPath = "ExternalData/nodes.csv",
     ChoicesCsvRelPath = "ExternalData/choices.csv",
     LocCsvRelPath = "ExternalData/loc.csv",
     InitialState = 空 FDialogueSaveData
   )
   ```

   不需要手动调用 `DialogueBrowser.LoadURL(...)`。`Init` 会把 `HudHtmlRelPath` 拼成 `file:///.../Content/ExternalData/hud.html` 并加载。

5. 打包设置
   `Project Settings > Packaging > Additional Non-Asset Directories to Copy` 添加：

   ```text
   Content/ExternalData
   ```

   否则打包后 HTML、JS、CSV 可能不会被带进去。

## CSV 格式

### nodes.csv

```csv
id,type,speakerKey,textKey,next,condition,effect,event,portrait
start,line,speaker_mara,line_start,ask_path,,,evt_intro_seen,portraits/mara_neutral.png
ask_path,choice,speaker_mara,line_ask_path,,,,,portraits/mara_neutral.png
end_good,end,speaker_mara,line_end_good,,,,,portraits/mara_happy.png
```

字段说明：

| 字段 | 说明 |
|---|---|
| `id` | 节点 ID，入口默认是 `start` |
| `type` | `line`、`choice`、`end` |
| `speakerKey` | 说话人本地化 key |
| `textKey` | 正文本地化 key |
| `next` | `line` 节点点击继续后的下一个节点 |
| `condition` | 可选条件表达式，例如 `has_badge && !alarm` |
| `effect` | 可选状态变化，例如 `has_badge=true;reputation=5` |
| `event` | 进入节点时触发的事件名 |
| `portrait` | 可选平台元数据；当前 Web HUD 会把它当相对 `hud.html` 的图片路径 |

`DialogueEngine` 不处理图片。`portrait` 只是随 node 一起透传的平台字段；UE 可以忽略它，改用自己的 DataTable、SoftObjectPath 或资源 key。

### choices.csv

```csv
nodeId,choiceId,textKey,next,condition,effect,event
ask_path,c_forest,choice_forest,forest,,,evt_choose_forest
ask_path,c_service_road,choice_service_road,service_road,has_badge && !alarm,,evt_choose_service_road
```

`nodeId` 对应 `nodes.csv` 里的 choice 节点。`condition` 为空则总是显示；否则按 JS 引擎的小型条件表达式判断。

支持的条件写法：

```csv
has_badge
!has_badge
has_badge && met_mara
has_badge || knows_password
reputation >= 5
route == forest
```

UE 侧继续用 `SetFlag("has_badge", true)` 和 `SetVarString("reputation", "5")` 写入变量；条件解析只在 `dialogue-engine.js` 中执行。

剧情也可以直接通过 `effect` 写变量。进入节点时执行 `nodes.csv` 的 `effect`；点击选项时先执行 `choices.csv` 的 `effect`，再跳到 `next`。

### loc.csv

```csv
key,lang,text
speaker_mara,en,Mara
speaker_mara,zh,玛拉
ui_next,en,Next
ui_next,zh,继续
```

同一个 `key` 可以有多种 `lang`。HUD 里语言下拉框会自动读取所有语言。

## 蓝图常用接口

| 接口 | 用途 |
|---|---|
| `Init` | 绑定 WebBrowser、加载 HUD、注入 CSV |
| `JumpToNode(NodeId)` | 跳到指定节点 |
| `SetLanguage(Lang)` | 切换语言，例如 `zh`、`en` |
| `SetFlag(Key, bValue)` | 设置布尔变量，条件分支会读取 |
| `SetVarString(Key, Value)` | 设置字符串变量 |
| `RequestSave()` | 请求 JS 导出存档 |
| `ApplySave(SaveData)` | 把存档恢复到 JS 引擎 |

事件：

| 事件 | 说明 |
|---|---|
| `OnReady` | HUD 通知 UE 页面已准备好，插件随后注入 CSV |
| `OnNodeChanged` | 节点变化，返回 `NodeId` 和完整 `NodeJson` |
| `OnDialogueEvent` | 触发 CSV 里的 `event`，返回 `EventName` 和完整 payload JSON |
| `OnSaveReady` | `RequestSave()` 后返回 `FDialogueSaveData` |
| `OnError` | CSV 读取失败、存档解析失败等错误 |

## 存档

保存：

```text
DialogueBridgeComponent.RequestSave()
OnSaveReady(SaveData) -> 存到你的 SaveGame
```

读取：

```text
从 SaveGame 取出 FDialogueSaveData
DialogueBridgeComponent.ApplySave(SaveData)
```

首次进入可以传空的 `FDialogueSaveData` 给 `Init`。如果要从存档开局，把保存过的 `FDialogueSaveData` 作为 `InitialState` 传入。

## 本地预览

在 `cross-platform-dialogue-system` 里先测 CSV：

```powershell
python validate_dialogue_csv.py
python web_dialogue_bridge/serve.py
```

浏览器会打开：

```text
http://localhost:8000/hud.html
```

实际会自动打开：

```text
http://localhost:8000/hud.html?preview=1
```

`preview=1` 只给浏览器测试用，会加载 `web_only_dialogue_bridge/dialogue-web.js` 来 fetch CSV。UE 里不要加这个参数，直接打开裸 `hud.html`，CSV 由 `DialogueBridgeComponent.Init` 注入。

确认网页能跑，再把 `hud.html`、`dialogue-engine.js`、CSV 和图片同步到 UE 项目的 `Content/ExternalData/`。

## 当前插件边界

- 插件只处理 UE 到网页的数据注入、跳节点、变量、语言、存档、节点变化和事件转发。
- 图片、音频、动画、镜头等表现逻辑由平台自己处理；CSV 里的额外列只作为 node 元数据透传。
