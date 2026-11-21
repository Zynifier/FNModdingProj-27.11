// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "AdjustCameraTransitionUpdateFunction.generated.h"

class UCurveVector;

USTRUCT(BlueprintType)
struct FFortInterpCurveOffsetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortInterpCurveOffsetData")
	float PitchAngle;

	UPROPERTY(EditAnywhere, Category="FortInterpCurveOffsetData")
	TObjectPtr<UCurveVector> OffsetCurve;

};

USTRUCT(BlueprintType)
struct FFortADSTransitionInterpCurveOffset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortADSTransitionInterpCurveOffset")
	TArray<FFortInterpCurveOffsetData> SampleCurves;

};

UCLASS(BlueprintType)
class UAdjustCameraTransitionUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AdjustCameraTransitionUpdateFunction")
	FFortADSTransitionInterpCurveOffset ADSInPathOffsetCurve;

	UPROPERTY(EditAnywhere, Category="AdjustCameraTransitionUpdateFunction")
	bool bADSOutHasSeparateCurve;

	UPROPERTY(EditAnywhere, Category="AdjustCameraTransitionUpdateFunction", meta=(EditCondition="bADSOutHasSeparateCurve", EditConditionHides))
	FFortADSTransitionInterpCurveOffset ADSOutPathOffsetCurve;

};

