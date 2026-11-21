// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Abilities/FortGameplayAbilityAthena_PeriodicItemGrant.h"
#include "UObject/Class.h"

bool FActiveItemGrantInfo::operator==(const FActiveItemGrantInfo& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FActiveItemGrantInfo& Value)
{
	return 0;
}

void UFortGameplayAbilityAthena_PeriodicItemGrant::StartItemAwardTimers()
{
}

void UFortGameplayAbilityAthena_PeriodicItemGrant::StopItemAwardTimers()
{
}
