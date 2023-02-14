// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PhysicsICA2 : ModuleRules
{
	public PhysicsICA2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
