// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PatronStrategy : ModuleRules
{
	public PatronStrategy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
