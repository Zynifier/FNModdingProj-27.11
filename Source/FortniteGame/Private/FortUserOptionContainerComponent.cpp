// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUserOptionContainerComponent.h"
#include "Net/UnrealNetwork.h"

void UFortUserOptionContainerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortUserOptionContainerComponent, UserOptionData);
}
