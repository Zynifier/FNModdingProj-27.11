// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortGameModeAthena.h"

void AFortGameModeAthena::AddAIClassToReplicationGraph(TSubclassOf<AFortPawn> NewAIClass) const
{
}

void AFortGameModeAthena::AddContentKeysToGameState()
{
}

void AFortGameModeAthena::AddMutatorToList(AFortGameplayMutator* Mutator)
{
}

void AFortGameModeAthena::EnableGameplayMutator(FGameplayTag MutatorTag, bool bEnable)
{
}

AFortGameplayMutator* AFortGameModeAthena::GetGameplayMutator(FGameplayTag MutatorTag)
{
	return nullptr;
}

AFortGameplayMutator* AFortGameModeAthena::GetMutatorByClass_Implementation(const AActor* ContextActor, TSubclassOf<AFortGameplayMutator> MutatorClass)
{
	return nullptr;
}

bool AFortGameModeAthena::GetPlaylistEnableBots() const
{
	return false;
}

void AFortGameModeAthena::GetSquadIds(TArray<uint8>& SquadIds)
{
}

void AFortGameModeAthena::GetSquadIdsOfNonSolos(TArray<uint8>& SquadsWithNonSolos)
{
}

void AFortGameModeAthena::GetSquadMembers(uint8 SquadId, TArray<AFortPlayerStateAthena*>& SquadMembers)
{
}

TSubclassOf<AActor> AFortGameModeAthena::GetVehicleClassOverride(TSubclassOf<AActor> DefaultVehicleClass) const
{
	return TSubclassOf<AActor>();
}

bool AFortGameModeAthena::HavePlaylistLootTablesBeenApplied() const
{
	return false;
}

bool AFortGameModeAthena::IsMapInfoInitialized() const
{
	return false;
}

void AFortGameModeAthena::OnCheckForOrphanedServer(bool bFromPlayerLogout, bool bConsiderPendingPlayers)
{
}

void AFortGameModeAthena::OnEndGameKickPlayers()
{
}

void AFortGameModeAthena::RemoveAllLootFromWorld(UObject* WorldContext, int32 ContainersPerIteration, int32 PickupsPerIteration, float TimeBetweenIterations, bool bProcessContainersAndPickupsConcurrently)
{
}

void AFortGameModeAthena::RemoveMutatorFromList(AFortGameplayMutator* Mutator)
{
}

void AFortGameModeAthena::SetTimeOfDayManagerGameplayOverride(TSubclassOf<AInfo> TimeOfDayManagerClass)
{
}

bool AFortGameModeAthena::ShouldForceSpawnInsideOfVolume() const
{
	return false;
}

void AFortGameModeAthena::StopRemovingAllLoot(UObject* WorldContext, bool bImmediateCleanup)
{
}

void AFortGameModeAthena::UpdateLootForBuildingContainers()
{
}

void AFortGameModeAthena::UpdateToNewLootTables()
{
}

void AFortGameModeAthena::UpdateToNewLootTablesAsync()
{
}
