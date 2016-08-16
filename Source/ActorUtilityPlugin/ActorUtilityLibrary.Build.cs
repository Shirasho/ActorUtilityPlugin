// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ActorUtilityLibrary : ModuleRules
{
    public ActorUtilityLibrary(TargetInfo Target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "RHI",
                "RenderCore"
            }
        );
        PrivateIncludePaths.AddRange(new string[] {
            "ActorUtilityLibrary/Public",
            "ActorUtilityLibrary/Private"
        });
    }
}
