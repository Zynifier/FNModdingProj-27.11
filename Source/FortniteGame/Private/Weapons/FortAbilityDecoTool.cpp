// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortAbilityDecoTool.h"

ABuildingActor* AFortAbilityDecoTool::AbilitySpawnDeco(const FAbilityToolSpawnParameters& SpawnParameters)
{
	return nullptr;
}

FGameplayAbilitySpecHandle AFortAbilityDecoTool::GetPlacementAbilityHandle()
{
	return FGameplayAbilitySpecHandle();
}

UFortGameplayAbility* AFortAbilityDecoTool::GetPlacementAbilityInstance()
{
	return nullptr;
}

void AFortAbilityDecoTool::GetSpawnParameters(FAbilityToolSpawnParameters& OutSpawnParamters) const
{
}
