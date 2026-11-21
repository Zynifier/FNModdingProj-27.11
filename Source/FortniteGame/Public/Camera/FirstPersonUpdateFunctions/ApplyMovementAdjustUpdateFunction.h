// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "Camera/FortFirstPersonState.h"
#include "ApplyMovementAdjustUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UApplyMovementAdjustUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ApplyMovementAdjustUpdateFunction")
	EMotionTarget MotionTarget;

	UPROPERTY(EditAnywhere, Category="Velocity", meta=(ClampMin="1.0"))
	float MaxVelocity;

	UPROPERTY(EditAnywhere, Category="Velocity", meta=(ClampMax="90.0", ClampMin="-90.0"))
	float RollAtMaxVelocity;

	UPROPERTY(EditAnywhere, Category="Velocity", meta=(ClampMax="90.0", ClampMin="-90.0"))
	float PitchAtMaxVelocity;

	UPROPERTY(EditAnywhere, Category="Velocity", meta=(ClampMax="10.0", ClampMin="1.0"))
	float VelocityResponsiveness;

	UPROPERTY(EditAnywhere, Category="Acceleration", meta=(ClampMin="1.0"))
	float MaxAcceleration;

	UPROPERTY(EditAnywhere, Category="Acceleration", meta=(ClampMax="90.0", ClampMin="-90.0"))
	float RollAtMaxAcceleration;

	UPROPERTY(EditAnywhere, Category="Acceleration", meta=(ClampMax="90.0", ClampMin="-90.0"))
	float PitchAtMaxAcceleration;

	UPROPERTY(EditAnywhere, Category="Acceleration", meta=(ClampMax="10.0", ClampMin="1.0"))
	float AccelerationResponsiveness;

	UPROPERTY(EditAnywhere, Category="ApplyMovementAdjustUpdateFunction", meta=(ClampMax="10.0", ClampMin="1.0"))
	float BrakingResponsiveness;

	UPROPERTY(EditAnywhere, Category="Translation")
	FVector TranslationCorrectionRatios;

};

