// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortProjectileMoveComp_Drunk.h"
#include "Net/UnrealNetwork.h"

void UFortProjectileMoveComp_Drunk::OnRep_RandSeed()
{
}

void UFortProjectileMoveComp_Drunk::SetDrunkConfig(const FProjectileMovementDrunkConfig& NewConfig)
{
}

void UFortProjectileMoveComp_Drunk::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortProjectileMoveComp_Drunk, RandSeed);
}
