// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInstance.h"
#include "FortValetMountedGunAnimInstance.generated.h"

class AFortDagwoodVehicle;
class AFortWeaponRangedForVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortValetMountedGunAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<AFortDagwoodVehicle> VehicleActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="MountedWeapon")
	bool bIsUsingMountedGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="MountedWeapon")
	int32 SeatIndexCached;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedWeapon")
	float AimingYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedWeapon")
	float AimingPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedWeapon")
	TObjectPtr<AFortWeaponRangedForVehicle> MountedWeapon;

};

