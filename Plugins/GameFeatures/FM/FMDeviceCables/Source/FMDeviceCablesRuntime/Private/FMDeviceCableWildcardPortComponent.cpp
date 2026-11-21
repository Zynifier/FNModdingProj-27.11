// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCableWildcardPortComponent.h"
#include "Net/UnrealNetwork.h"

void UFMDeviceCableWildcardPortComponent::OnPlayerControllerPortConnectedWildcard(const TArray<UFMDeviceCablePortComponent*>& ControllerPorts)
{
}

void UFMDeviceCableWildcardPortComponent::OnPlayerControllerPortDisconnectedWildcard()
{
}

void UFMDeviceCableWildcardPortComponent::OnRep_SavedSlotIndex()
{
}

void UFMDeviceCableWildcardPortComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMDeviceCableWildcardPortComponent, SavedSlotIndex);
}
