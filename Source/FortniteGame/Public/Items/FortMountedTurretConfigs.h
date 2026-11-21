// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortMountedTurretConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortMountedTurretConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeAmplitudeMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeAmplitudeMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeNormalizedSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraShake")
	float CameraShakeSpeedCurvePow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraOffset")
	float AimInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="CameraOffset")
	float InitialCameraInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float InitialCameraLerpTime;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	float MaxYawPerSecondThreshold;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	float MaxPitchPerSecondThreshold;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	float PitchConstraintAngleOffset;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	bool bConstrainVerticalRotationOnly;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	FVector LocalAimOffsetWhenPitchedUp;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	FVector LocalAimOffsetWhenPitchedFlat;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	FVector LocalAimOffsetWhenPitchedDown;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	float PedalCyclesPerFullTurn;

	UPROPERTY(EditAnywhere, Config, Category="Aiming")
	int32 bWeaponIgnoresMountedTurretBase;

};

