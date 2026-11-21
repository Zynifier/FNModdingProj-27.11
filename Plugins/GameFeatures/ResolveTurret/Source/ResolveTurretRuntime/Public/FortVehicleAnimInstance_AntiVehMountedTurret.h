// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortMountedTurretAnimInstance.h"
#include "FortVehicleAnimInstance_AntiVehMountedTurret.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleAnimInstance_AntiVehMountedTurret : public UFortMountedTurretAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Anti Vehicle Mounted Turret")
	float YawDeltaSmoothed;

};

