// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IAudioMotorSim.h"
#include "FortMotorSimComponent_PatternPlayer.generated.h"

class UCurveVector;

USTRUCT(BlueprintType)
struct FFortMotorSimPatternState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	TArray<TObjectPtr<UCurveVector>> Curves;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float OnsetInterpSpeed;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float ThrottleThreshold;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float RpmFallRate;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float SpeedMin;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float SpeedMax;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float RpmOffsetMin;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	float RpmOffsetMax;

	UPROPERTY(EditAnywhere, Category="FortMotorSimPatternState")
	bool bLoopCurves;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class VEHICLEAUDIORUNTIME_API UFortMotorSimComponent_PatternPlayer : public UAudioMotorSimComponent
{
	GENERATED_BODY()

public:
	UFortMotorSimComponent_PatternPlayer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_PatternPlayer", meta=(ClampMin="0.000000"))
	float PatternResetCooldown;

	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_PatternPlayer")
	FFortMotorSimPatternState DriftState;

	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_PatternPlayer")
	FFortMotorSimPatternState AirState;

	UPROPERTY(EditAnywhere, Category="FortMotorSimComponent_PatternPlayer")
	FFortMotorSimPatternState StartlineState;

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortMotorSimComponent_PatternPlayer")
	TObjectPtr<UCurveVector> CurrentCurve;

};

