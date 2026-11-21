// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/EntityActorPlayerComponent.h"
#include "Net/UnrealNetwork.h"

void UEntityActorPlayerComponent::OnRep_PlayerID()
{
}

void UEntityActorPlayerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UEntityActorPlayerComponent, PlayerID);
}
