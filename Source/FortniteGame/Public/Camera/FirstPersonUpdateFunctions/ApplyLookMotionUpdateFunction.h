// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "ApplyLookMotionUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UApplyLookMotionUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ApplyLookMotionUpdateFunction")
	FRotator RotationInheritRatios;

	UPROPERTY(EditAnywhere, Category="ApplyLookMotionUpdateFunction")
	float BlendRate;

	UPROPERTY(EditAnywhere, Category="ApplyLookMotionUpdateFunction", meta=(ClampMax="5.0", ClampMin="0.0"))
	float MaxYawRate;

	UPROPERTY(EditAnywhere, Category="ApplyLookMotionUpdateFunction", meta=(ClampMax="5.0", ClampMin="0.0"))
	float MaxPitchRate;

	UPROPERTY(EditAnywhere, Category="Translation")
	FVector TranslationCorrectionRatios;

private:
	UPROPERTY(Transient)
	float YawRate;

	UPROPERTY(Transient)
	float PitchRate;

	UPROPERTY(Transient)
	FTransform SmoothedTransform;

};

