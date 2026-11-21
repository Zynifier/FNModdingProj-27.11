// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "Camera/FortFirstPersonState.h"
#include "SinusoidalMotionUpdateFunction.generated.h"

UENUM(BlueprintType)
enum class ESineWaveTarget : uint8
{
	TranslationX = 0,
	TranslationY = 1,
	TranslationZ = 2,
	RotationPitch = 3,
	RotationRoll = 4,
	RotationYaw = 5,
};

USTRUCT(BlueprintType)
struct FSineWave
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SineWave")
	float PhaseOffset;

	UPROPERTY(EditAnywhere, Category="SineWave")
	float FrequencyHz;

	UPROPERTY(EditAnywhere, Category="SineWave")
	float Multiplier;

	UPROPERTY(EditAnywhere, Category="SineWave")
	float Offset;

	UPROPERTY(EditAnywhere, Category="SineWave")
	bool bAbsoluteValue;

	UPROPERTY(EditAnywhere, Category="SineWave")
	ESineWaveTarget MotionType;

};

UCLASS(BlueprintType)
class USinusoidalMotionUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SinusoidalMotionUpdateFunction")
	EMotionTarget TargetObject;

	UPROPERTY(EditAnywhere, Category="SinusoidalMotionUpdateFunction")
	TArray<FSineWave> SineWaves;

};

