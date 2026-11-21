// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortWeaponFxComponent_ChargeAimLocation.h"
#include "Net/UnrealNetwork.h"

void UFortWeaponFxComponent_ChargeAimLocation::GetCachedDamageStartAndAim(FVector& OutDamageStartLocation, FVector& OutAimDirection) const
{
}

void UFortWeaponFxComponent_ChargeAimLocation::SetReplicatedAimOffset(FVector AimOffset)
{
}

void UFortWeaponFxComponent_ChargeAimLocation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWeaponFxComponent_ChargeAimLocation, ReplicatedAimOffset);
}
