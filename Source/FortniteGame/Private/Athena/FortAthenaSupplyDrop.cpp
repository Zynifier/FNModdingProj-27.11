// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaSupplyDrop.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaSupplyDrop::EnableArrivedNearDestinationEvent(USceneComponent* CrateComponent, USceneComponent* DestinationComponent, float EventDistance)
{
}

FVector AFortAthenaSupplyDrop::FindGroundLocationAt(const FVector& InLocation)
{
	return FVector();
}

void AFortAthenaSupplyDrop::GetSupplyDropSpawnData(float& MinSpawnHeight, float& MaxSpawnHeight)
{
}

void AFortAthenaSupplyDrop::GetSupplyDropSpeedData(float& MinSpeed, float& MaxSpeed)
{
}

bool AFortAthenaSupplyDrop::GroundTrace(const FVector& TraceStart, const FVector& TraceEnd, FHitResult& OutHit) const
{
	return false;
}

void AFortAthenaSupplyDrop::HandlePickedUpForAnalyticsEvent(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation)
{
}

bool AFortAthenaSupplyDrop::IsClientCollisionReductionEnabled() const
{
	return false;
}

bool AFortAthenaSupplyDrop::IsPlayingAReplay() const
{
	return false;
}

void AFortAthenaSupplyDrop::OnCheckForBeingInStorm()
{
}

void AFortAthenaSupplyDrop::OnDespawnDueToStorm()
{
}

void AFortAthenaSupplyDrop::OnLootSpawned()
{
}

void AFortAthenaSupplyDrop::OnRep_NumPlayersInteracting()
{
}

void AFortAthenaSupplyDrop::SendSpawnLootAnalytics(AFortPlayerController* FortPC, const TArray<FFortItemEntry>& ItemsToSpawn) const
{
}

void AFortAthenaSupplyDrop::SetLootTableNameOverride(FName TableNameToUse)
{
}

AFortGameModePickup* AFortAthenaSupplyDrop::SpawnGameModePickup(UFortWorldItemDefinition* ItemDefinition, TSubclassOf<AFortGameModePickup> PickupClass, int32 NumberToSpawn, AFortPawn* TriggeringPawn, FVector Position, FVector Direction)
{
	return nullptr;
}

void AFortAthenaSupplyDrop::SpawningLootOnDestruction(AController* EventInstigator)
{
}

AFortPickup* AFortAthenaSupplyDrop::SpawnPickup(UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, AFortPawn* TriggeringPawn, FVector Position, FVector Direction)
{
	return nullptr;
}

AFortPickup* AFortAthenaSupplyDrop::SpawnPickupFromItemEntry(UFortWorldItemDefinition* ItemDefinition, const FFortItemEntry& InItemEntry, int32 NumberToSpawn, AFortPawn* TriggeringPawn, FVector Position, FVector Direction)
{
	return nullptr;
}

void AFortAthenaSupplyDrop::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaSupplyDrop, SpecialActorID);
	DOREPLIFETIME(AFortAthenaSupplyDrop, NumPlayersInteracting);
}
