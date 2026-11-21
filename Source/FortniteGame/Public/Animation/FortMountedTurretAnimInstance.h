// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortMountedTurretAnimInstance.generated.h"

class AFortMountedTurret;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortMountedTurretAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortMountedTurret> MountedTurret;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="MountedTurret")
	bool bIsUsingMountedTurret;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="MountedTurret")
	float AimingYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="MountedTurret")
	float AimingPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="MountedTurret")
	float PedalScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="MountedTurret")
	float TurnRate;

};

