// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCableModulatorPortComponent.h"
#include "Net/UnrealNetwork.h"

void UFMDeviceCableModulatorPortComponent::SetDeviceCableManager(UFMDeviceCableManagerComponent* InDeviceCableManager)
{
}

void UFMDeviceCableModulatorPortComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMDeviceCableModulatorPortComponent, AssociatedProperty);
}
