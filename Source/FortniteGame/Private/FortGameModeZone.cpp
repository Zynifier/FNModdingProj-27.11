// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameModeZone.h"

void AFortGameModeZone::ClearPlayerStartLocationOverrides()
{
}

AFortPlayerStartupController* AFortGameModeZone::GetPlayerStartupController()
{
	return nullptr;
}

TSubclassOf<UGameplayEffect> AFortGameModeZone::GetTeammateReviveGameplayEffectOverride_Implementation()
{
	return TSubclassOf<UGameplayEffect>();
}

bool AFortGameModeZone::IsGameReadyToSelectLoot() const
{
	return false;
}

bool AFortGameModeZone::IsSpectatingAllowedAfterDeath_Implementation() const
{
	return false;
}

void AFortGameModeZone::OnEveningReached()
{
}

void AFortGameModeZone::OnMorningReached()
{
}

void AFortGameModeZone::ReplicateHealthAndShield()
{
}

void AFortGameModeZone::SetActiveSpawnPad(ABuildingSMActor* InActiveSpawnPad)
{
}

void AFortGameModeZone::SetEnemyAIItemCacheLootDrops(bool bValue)
{
}

void AFortGameModeZone::SetJoinability(bool bMatchJoinable)
{
}

void AFortGameModeZone::SetPlayerStartLocationOverrides(TArray<FVector> InPlayerStarts, AFortMission* InMission)
{
}

void AFortGameModeZone::SetSpawnWithinStormShield(bool bSpawnInStormShield)
{
}

void AFortGameModeZone::SetZoneLootNamedWeightsMapOverride(const TMap<FName, float>& NewOverrideMap)
{
}
