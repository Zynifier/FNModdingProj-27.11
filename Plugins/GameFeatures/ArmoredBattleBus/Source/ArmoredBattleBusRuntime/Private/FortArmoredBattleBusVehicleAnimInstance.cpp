// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortArmoredBattleBusVehicleAnimInstance.h"

void UFortArmoredBattleBusVehicleAnimInstance::GetPitchAndYaw(const AFortAthenaVehicle* VehicleActor, const AFortPlayerPawn* GunnerActor, float& AdjustedPitch, float& AdjustedYaw, bool& bIsLocalPlayerControlled, FRotator& YawRotator)
{
}

float UFortArmoredBattleBusVehicleAnimInstance::UpdateSmoothedVehicleYawRate(const AFortAthenaVehicle* VehicleActor, const FRotator PreviousRotator)
{
	return float();
}

void UFortArmoredBattleBusVehicleAnimInstance::UpdateTurretAimPitchWeaponYaw(const AFortAthenaVehicle* OwnerVehicle, const AFortPlayerPawn* GunnerActor, const FName SocketName, const float YawOffset, float& TurretAimPitch, float& YawDeltaSmoothed, FRotator& WeaponYaw)
{
}

float UFortArmoredBattleBusVehicleAnimInstance::UpdateYawDeltaSmoothed(const AFortAthenaVehicle* VehicleActor, const FName SocketName, const FRotator NewRotation, const float SmoothedYawValue)
{
	return float();
}
