// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ModuleConfigProjectTarget : TargetRules
{
	public ModuleConfigProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("ModuleConfigProject");
        ExtraModuleNames.Add("VorpisBaseCharacterModule");
        ExtraModuleNames.Add("VorpisInventoryComponentModule");
        ExtraModuleNames.Add("VorpisItemsModule");
    }
}
