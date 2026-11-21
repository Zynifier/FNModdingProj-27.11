// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortProjectPlayComponent.h"
#include "Net/UnrealNetwork.h"

void UFortProjectPlayComponent::OnRep_BoundsScale()
{
}

void UFortProjectPlayComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortProjectPlayComponent, BoundsScale);
	DOREPLIFETIME(UFortProjectPlayComponent, EstimatedGameplayBounds);
}
