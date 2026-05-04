using System.Collections;
using System.IO;
using Gree.UnityWebView;
using UnityEngine;
using UnityEngine.Networking;

public sealed class DialogueUnityWebBridge : MonoBehaviour
{
    const string Root = "DialogueWebUI";

    static readonly string[] Files =
    {
        "hud.html",
        "dialogue-engine.js",
        "nodes.csv",
        "choices.csv",
        "loc.csv",
        "web_only_dialogue_bridge/Chara1.png",
        "web_only_dialogue_bridge/Chara2.png",
        "web_only_dialogue_bridge/Chara3.webp",
        "web_only_dialogue_bridge/line_start_ISpotBlackTower.mp3",
    };

    WebViewObject webView;
    string localRoot;
    bool pushedData;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void AutoCreate()
    {
        if (FindObjectOfType<DialogueUnityWebBridge>()) return;
        var go = new GameObject("Dialogue WebUI Bridge");
        DontDestroyOnLoad(go);
        go.AddComponent<DialogueUnityWebBridge>();
    }

    IEnumerator Start()
    {
        yield return PrepareFiles();
        OpenWebView(BuildHudUrl());
    }

    public void JumpToNode(string id) => Eval("DialogueEngine.jumpToNode(" + Js(id) + ")");
    public void SetLanguage(string lang) => Eval("DialogueEngine.setLanguage(" + Js(lang) + ")");
    public void SetFlag(string key, bool value) => Eval("DialogueEngine.setFlag(" + Js(key) + "," + (value ? "true" : "false") + ")");
    public void ReloadData() { pushedData = false; StartCoroutine(PushData()); }

    void OpenWebView(string url)
    {
        try
        {
            webView = new GameObject("Dialogue WebView").AddComponent<WebViewObject>();
            webView.Init(
                cb: OnMessage,
                err: msg => Debug.LogError("[DialogueWebUI] " + msg),
                httpErr: msg => Debug.LogError("[DialogueWebUI HTTP] " + msg),
                ld: _ => StartCoroutine(PushData()),
                transparent: true,
                enableWKWebView: true);
            webView.SetMargins(0, 0, 0, 0);
            webView.SetVisibility(true);
            webView.LoadURL(url);
        }
        catch (System.Exception e)
        {
            Debug.LogWarning("[DialogueWebUI] WebView unavailable, opening browser preview. " + e.Message);
            Application.OpenURL(url);
        }
    }

    IEnumerator PushData()
    {
        if (pushedData || webView == null) yield break;
        pushedData = true;

        string nodes = null, choices = null, loc = null;
        yield return ReadText("nodes.csv", v => nodes = v);
        yield return ReadText("choices.csv", v => choices = v);
        yield return ReadText("loc.csv", v => loc = v);

        // 页面加载完后再注入数据；避免 file:// 下 fetch CSV 的跨平台差异。
        Eval(UnityCallShim() + "DialogueEngine.loadData(" + Js(nodes) + "," + Js(choices) + "," + Js(loc) + ");");
    }

    void OnMessage(string msg)
    {
        if (msg.StartsWith("__DIALOGUE_EVENT__")) Debug.Log("[DialogueEvent] " + msg.Substring(18));
        else if (msg.StartsWith("__DIALOGUE_BLOCKED__")) Debug.Log("[DialogueBlocked] " + msg.Substring(20));
    }

    IEnumerator PrepareFiles()
    {
#if UNITY_WEBGL && !UNITY_EDITOR
        localRoot = null;
        yield break;
#else
        localRoot = Path.Combine(Application.temporaryCachePath, Root);
        Directory.CreateDirectory(localRoot);

        foreach (var file in Files)
        {
            var dst = Path.Combine(localRoot, file);
            Directory.CreateDirectory(Path.GetDirectoryName(dst));

            using (var req = UnityWebRequest.Get(StreamingUrl(file)))
            {
                yield return req.SendWebRequest();
                if (req.result != UnityWebRequest.Result.Success)
                {
                    Debug.LogError("[DialogueWebUI] Failed to copy " + file + ": " + req.error);
                    continue;
                }
                File.WriteAllBytes(dst, req.downloadHandler.data);
            }
        }
#endif
    }

    IEnumerator ReadText(string file, System.Action<string> done)
    {
#if UNITY_WEBGL && !UNITY_EDITOR
        using (var req = UnityWebRequest.Get(StreamingUrl(file)))
        {
            yield return req.SendWebRequest();
            done(req.result == UnityWebRequest.Result.Success ? req.downloadHandler.text : "");
        }
#else
        done(File.ReadAllText(Path.Combine(localRoot, file)));
        yield break;
#endif
    }

    string BuildHudUrl()
    {
#if UNITY_WEBGL && !UNITY_EDITOR
        return "StreamingAssets/" + Root + "/hud.html?unity";
#else
        return "file:///" + Path.Combine(localRoot, "hud.html").Replace("\\", "/") + "?unity";
#endif
    }

    static string StreamingUrl(string file)
    {
        var path = Path.Combine(Application.streamingAssetsPath, Root, file).Replace("\\", "/");
        return path.Contains("://") ? path : "file:///" + path;
    }

    void Eval(string js)
    {
        if (webView != null) webView.EvaluateJS(js);
    }

    static string UnityCallShim()
    {
#if UNITY_WEBGL && !UNITY_EDITOR
        return "window.Unity=window.Unity||{call:function(m){parent.unityWebView.sendMessage('WebViewObject',m);}};";
#else
        return "window.Unity=window.Unity||{call:function(m){location.href='unity:'+encodeURIComponent(m);}};";
#endif
    }

    static string Js(string value)
    {
        return "\"" + (value ?? "")
            .Replace("\\", "\\\\")
            .Replace("\"", "\\\"")
            .Replace("\r", "\\r")
            .Replace("\n", "\\n") + "\"";
    }
}
