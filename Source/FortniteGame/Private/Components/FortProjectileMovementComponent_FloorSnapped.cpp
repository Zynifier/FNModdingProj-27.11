// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortProjectileMovementComponent_FloorSnapped.h"
#include "Net/UnrealNetwork.h"

void UFortProjectileMovementComponent_FloorSnapped::OnRep_CurrentGravity()
{
}

void UFortProjectileMovementComponent_FloorSnapped::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortProjectileMovementComponent_FloorSnapped, ReplicatedGravity);
}
