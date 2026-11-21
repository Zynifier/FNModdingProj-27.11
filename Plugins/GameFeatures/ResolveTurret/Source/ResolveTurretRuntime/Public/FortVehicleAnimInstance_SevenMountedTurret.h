// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortMountedTurretAnimInstance.h"
#include "FortVehicleAnimInstance_SevenMountedTurret.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleAnimInstance_SevenMountedTurret : public UFortMountedTurretAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Seven Mounted Turret")
	float YawDeltaSmoothed;

};

