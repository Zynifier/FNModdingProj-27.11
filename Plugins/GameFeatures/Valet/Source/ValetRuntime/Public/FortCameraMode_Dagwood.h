// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortCameraMode_AthenaVehicle.h"
#include "FortCameraMode_Dagwood.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortCameraMode_Dagwood : public UFortCameraMode_AthenaVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Camera")
	float HorizontalCameraSpaceOffsetWhileTurning;

	UPROPERTY(EditAnywhere, Category="Camera")
	float SteeringAngleForMaxHorizontalOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	float InAirVerticalOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	float AirOffsetDampFactor;

	UPROPERTY(EditAnywhere, Category="Camera")
	float SpeedAlphaDampFactor;

	UPROPERTY(EditAnywhere, Category="Camera")
	float TimeInAirRequiredForVertOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	float VehicleBasePitch;

	UPROPERTY(EditAnywhere, Category="FortCameraMode_Dagwood")
	float HorizOffsetInterpSpeed;

	UPROPERTY(EditAnywhere, Category="FortCameraMode_Dagwood")
	float HorizOffsetInterpSpeedRecovery;

	UPROPERTY(Transient)
	float CurrentSpeedAlpha;

	UPROPERTY(Transient)
	float CurrentVerticalOffset;

	UPROPERTY(Transient)
	float CurrentHorizontalOffset;

	UPROPERTY(Transient)
	float TimeInAir;

	UPROPERTY(Transient)
	float PreviousSpeed;

	UPROPERTY(Transient)
	float AppliedPitch;

};

