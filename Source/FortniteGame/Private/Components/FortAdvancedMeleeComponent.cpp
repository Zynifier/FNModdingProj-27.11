// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortAdvancedMeleeComponent.h"
#include "Net/UnrealNetwork.h"

void UFortAdvancedMeleeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAdvancedMeleeComponent, FightListHandles);
}
