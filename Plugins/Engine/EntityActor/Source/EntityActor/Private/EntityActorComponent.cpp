// Copyright Epic Games, Inc. All Rights Reserved.

#include "EntityActorComponent.h"
#include "Net/UnrealNetwork.h"

void UEntityActorComponent::OnRep_ActorComponent()
{
}

void UEntityActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UEntityActorComponent, ActorComponent);
}
