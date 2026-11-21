// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameSpawnerComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortMinigameSpawnerComponent::MakeSpawnParamsFromItemEntry(FMinigameSpawnerSpawnParams& SpawnParams, const FFortItemEntry& ItemEntry, const FTransform& SpawnTransform) const
{
	return false;
}

void UFortMinigameSpawnerComponent::OnRep_ToSpawnList()
{
}

AFortPickup* UFortMinigameSpawnerComponent::SpawnPickupFromSpawnParams(const FMinigameSpawnerSpawnParams& SpawnParams, TSubclassOf<AFortPickup> PickupClass, FVector Position, FVector Direction, bool bToss, bool bRandomRotation, bool bBlockedFromAutoPickup, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source, AFortPlayerController* OptionalOwnerPC, bool bPickupOnlyRelevantToOwner)
{
	return nullptr;
}

void UFortMinigameSpawnerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameSpawnerComponent, ToSpawnList);
}
