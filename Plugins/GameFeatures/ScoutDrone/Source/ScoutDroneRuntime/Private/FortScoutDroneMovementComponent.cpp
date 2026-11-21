// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortScoutDroneMovementComponent.h"
#include "Net/UnrealNetwork.h"

void UFortScoutDroneMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortScoutDroneMovementComponent, ReplicatedAcceleration);
}
