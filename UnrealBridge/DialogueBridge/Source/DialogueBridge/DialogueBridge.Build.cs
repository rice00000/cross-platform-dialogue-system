using UnrealBuildTool;

public class DialogueBridge : ModuleRules
{
    public DialogueBridge(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UMG",
            "WebBrowser",
            "WebBrowserWidget",
            "Json",
            "JsonUtilities"
        });
    }
}
