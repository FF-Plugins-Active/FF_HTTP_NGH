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
                PublicDefinitions.Add("NGHTTP2_NO_SSIZE_T=1");

                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "include"));

                // Static Lib.
                //PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "nghttp2_static.lib"));

                // Shared Lib.

                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "nghttp2.lib"));
                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "nghttp2.dll"));
                PublicDelayLoadDLLs.Add("nghttp2.dll");
            }
        }
    }
}
