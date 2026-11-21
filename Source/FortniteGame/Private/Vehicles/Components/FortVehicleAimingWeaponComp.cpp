// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/Components/FortVehicleAimingWeaponComp.h"
#include "Net/UnrealNetwork.h"

void UFortVehicleAimingWeaponComp::OnRep_TargetLocalAimOrientationCorrectedRepped()
{
}

void UFortVehicleAimingWeaponComp::OnRep_TargetLocalAimOrientationRepped()
{
}

void UFortVehicleAimingWeaponComp::ServerSetAnimatedMuzzleLocation_Implementation(const FVector& NewValue)
{
}

void UFortVehicleAimingWeaponComp::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehicleAimingWeaponComp, TargetLocalAimOrientationRepped);
	DOREPLIFETIME(UFortVehicleAimingWeaponComp, TargetLocalAimOrientationCorrectedRepped);
}
