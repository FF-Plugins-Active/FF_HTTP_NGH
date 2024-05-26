namespace UnrealBuildTool.Rules
{
    using System.IO;

    public class ff_nghttp2 : ModuleRules
    {
        public ff_nghttp2(ReadOnlyTargetRules Target) : base(Target)
        {
    		Type = ModuleType.External;
            bEnableUndefinedIdentifierWarnings = false;
            bEnableExceptions = true;
            bUseRTTI = true;

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "include"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "nghttp2_static.lib"));
                
                PublicDefinitions.Add("NGHTTP2_STATICLIB=1");
                PublicDefinitions.Add("NGHTTP2_NO_SSIZE_T=1");
            }
        }
    }
}
