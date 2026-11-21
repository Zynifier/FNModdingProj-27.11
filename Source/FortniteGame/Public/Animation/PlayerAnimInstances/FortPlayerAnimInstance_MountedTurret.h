// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_MountedTurret.generated.h"

class AFortMountedTurret;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_MountedTurret : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MountedTurret")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MountedTurret")
	FVector ImpactDisplacement;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	TObjectPtr<AFortMountedTurret> MountedTurret;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	float PedalScaler;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	float TurnRate;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	float PitchRate;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MountedTurret")
	float AimingPitchLastTick;

};

