// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorCloneMachine.h"
#include "Net/UnrealNetwork.h"

void ABuildingGameplayActorCloneMachine::OnCloneMachineActivationBegins_Implementation()
{
}

void ABuildingGameplayActorCloneMachine::OnCloneMachineRespawningBegins_Implementation()
{
}

void ABuildingGameplayActorCloneMachine::OnCloneMachineSpawnsPlayer_Implementation(AFortPlayerPawn* PlayerPawn)
{
}

void ABuildingGameplayActorCloneMachine::OnRep_ActivationServerEndTime()
{
}

void ABuildingGameplayActorCloneMachine::OnRep_RespawnServerEndTime()
{
}

void ABuildingGameplayActorCloneMachine::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorCloneMachine, ActivationServerEndTime);
	DOREPLIFETIME(ABuildingGameplayActorCloneMachine, RespawnServerEndTime);
}
