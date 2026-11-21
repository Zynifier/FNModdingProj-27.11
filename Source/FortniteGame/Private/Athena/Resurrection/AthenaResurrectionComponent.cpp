// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Resurrection/AthenaResurrectionComponent.h"
#include "Net/UnrealNetwork.h"

void UAthenaResurrectionComponent::ClientNotifyCloneMachineUnderAttack_Implementation(const USoundCue* DamageSound)
{
}

void UAthenaResurrectionComponent::ClientNotifyCloneMchineDestroyed_Implementation(const USoundCue* DestroyedSound)
{
}

void UAthenaResurrectionComponent::OnRep_PlayerIdsForResurrection()
{
}

void UAthenaResurrectionComponent::OnTeamChanged(uint8 OldTeam)
{
}

void UAthenaResurrectionComponent::ServerOnBeginResurrectionInteraction_Implementation(ABuildingGameplayActorSpawnMachine* SpawnMachine)
{
}
bool UAthenaResurrectionComponent::ServerOnBeginResurrectionInteraction_Validate(ABuildingGameplayActorSpawnMachine* SpawnMachine)
{
	return true;
}

void UAthenaResurrectionComponent::ServerOnInterruptResurrectionInteraction_Implementation(ABuildingGameplayActorSpawnMachine* SpawnMachine)
{
}
bool UAthenaResurrectionComponent::ServerOnInterruptResurrectionInteraction_Validate(ABuildingGameplayActorSpawnMachine* SpawnMachine)
{
	return true;
}

void UAthenaResurrectionComponent::UpdatePlayerIdsForResurrectionForNewTeam()
{
}

void UAthenaResurrectionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAthenaResurrectionComponent, PlayerIdsForResurrection);
	DOREPLIFETIME(UAthenaResurrectionComponent, CloneMachineRepData);
}
