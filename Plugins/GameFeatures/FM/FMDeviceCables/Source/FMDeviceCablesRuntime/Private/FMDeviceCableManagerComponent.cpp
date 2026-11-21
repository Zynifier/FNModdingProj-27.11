// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCableManagerComponent.h"
#include "Net/UnrealNetwork.h"

EDeviceCableInteractionType UFMDeviceCableManagerComponent::GetCableInteractionType()
{
	return EDeviceCableInteractionType();
}

void UFMDeviceCableManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMDeviceCableManagerComponent, FreeDeviceCables);
}
