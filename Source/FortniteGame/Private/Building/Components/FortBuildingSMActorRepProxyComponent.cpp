// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/Components/FortBuildingSMActorRepProxyComponent.h"
#include "Net/UnrealNetwork.h"

UFortBuildingSMActorRepProxyComponent::UFortBuildingSMActorRepProxyComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortBuildingSMActorRepProxyComponent::HandleBuildingAbilitySystemComponentInitialized()
{
}

void UFortBuildingSMActorRepProxyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBuildingSMActorRepProxyComponent, SimulatedProxyActiveGameplayCues);
}
