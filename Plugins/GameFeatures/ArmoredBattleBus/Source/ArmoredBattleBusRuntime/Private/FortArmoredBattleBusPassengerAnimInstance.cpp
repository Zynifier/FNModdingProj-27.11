// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortArmoredBattleBusPassengerAnimInstance.h"

void UFortArmoredBattleBusPassengerAnimInstance::GenerateCharacterPitchAndYawForSlopedTerrain(const AFortAthenaVehicle* VehicleActor, float& TurretYaw, float& TurretPitch, FRotator& PawnYawRotator)
{
}

FTransform UFortArmoredBattleBusPassengerAnimInstance::GetFootAttachTransform(const USkeletalMeshComponent* BusMeshComponent)
{
	return FTransform();
}

FVector UFortArmoredBattleBusPassengerAnimInstance::GetHandAttachLocation(const USkeletalMeshComponent* BusMeshComponent, const FName FrontHandAttachBoneName, const FName RearHandAttachBoneName)
{
	return FVector();
}

FTransform UFortArmoredBattleBusPassengerAnimInstance::GetPassengerTransform(const USkeletalMeshComponent* BusMeshComponent)
{
	return FTransform();
}

FVector UFortArmoredBattleBusPassengerAnimInstance::UnrotateHandAttachLocation(const FVector& HandLocation, const FVector& FootLocation, const FRotator& FootRotation)
{
	return FVector();
}

void UFortArmoredBattleBusPassengerAnimInstance::UpdateHandPositionsSlopeValues(const USkeletalMeshComponent* BusMeshComponent)
{
}

void UFortArmoredBattleBusPassengerAnimInstance::UpdateSmoothedVehicleYawRate(const AFortAthenaVehicle* VehicleActor)
{
}

void UFortArmoredBattleBusPassengerAnimInstance::UpdateYawDeltaSmoothed(const AFortAthenaVehicle* VehicleActor, const FName SocketName, const FRotator& NewRotation, float& SmoothedYawValue)
{
}
