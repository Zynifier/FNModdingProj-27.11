// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorSpawnMachine.h"
#include "Net/UnrealNetwork.h"

bool ABuildingGameplayActorSpawnMachine::CanPlayerSquadInteract(const AFortPawn* InteractingPawn, const TEnumAsByte<TInteractionType>& InteractionType) const
{
	return false;
}

float ABuildingGameplayActorSpawnMachine::GetCooldownLength_Implementation() const
{
	return float();
}

ESpawnMachineState ABuildingGameplayActorSpawnMachine::GetSpawnMachineState() const
{
	return ESpawnMachineState();
}

void ABuildingGameplayActorSpawnMachine::OnBeginLongUse_Implementation(AFortPlayerControllerAthena* AthenaPC)
{
}

void ABuildingGameplayActorSpawnMachine::OnInterruptLongUse_Implementation(AFortPlayerControllerAthena* AthenaPC)
{
}

void ABuildingGameplayActorSpawnMachine::OnPlayerPawnResurrected_Implementation(AFortPlayerPawn* PlayerPawn)
{
}

void ABuildingGameplayActorSpawnMachine::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void ABuildingGameplayActorSpawnMachine::OnRep_SpawnMachineState()
{
}

void ABuildingGameplayActorSpawnMachine::OnResurrectionCompleted_Implementation()
{
}

void ABuildingGameplayActorSpawnMachine::OnResurrectionStarted_Implementation(AFortPlayerControllerAthena* PlayerController)
{
}

void ABuildingGameplayActorSpawnMachine::OnSpawnMachineStateChanged_Implementation()
{
}

bool ABuildingGameplayActorSpawnMachine::RebootPlayersInAir() const
{
	return false;
}

void ABuildingGameplayActorSpawnMachine::SetSpawnMachineState(ESpawnMachineState NewState)
{
}

bool ABuildingGameplayActorSpawnMachine::UseResurrectionTetherRange() const
{
	return false;
}

void ABuildingGameplayActorSpawnMachine::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorSpawnMachine, SpawnMachineState);
	DOREPLIFETIME(ABuildingGameplayActorSpawnMachine, HandleIntoGameState);
}
