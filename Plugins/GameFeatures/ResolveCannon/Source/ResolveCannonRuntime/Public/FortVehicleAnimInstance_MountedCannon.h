// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortMountedTurretAnimInstance.h"
#include "FortVehicleAnimInstance_MountedCannon.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleAnimInstance_MountedCannon : public UFortMountedTurretAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Mounted Cannon|Native Properties")
	float AimingYawLastFrame;

	UPROPERTY(EditDefaultsOnly, Category="Mounted Cannon|Magic Numbers", meta=(ClampMin="0.001"))
	float MinTimeStepForInterpolatingTurnRate;

};

