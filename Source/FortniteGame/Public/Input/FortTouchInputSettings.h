// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortTouchInputSettings.generated.h"

class UCurveFloat;

USTRUCT()
struct FFortTouchAimAssistSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AssistReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AssistReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AutoFireReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AutoFireReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	FVector2D AutofireTargetSizeReduction;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AutoFireTrackingReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AutoFireTrackingReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float TargetingReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float TargetingReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float TargetRange;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	TObjectPtr<UCurveFloat> TargetWeightCurve;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	TObjectPtr<UCurveFloat> PullStrengthYawCurve;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	TObjectPtr<UCurveFloat> PullStrengthPitchCurve;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings", meta=(ClampMin="0.0", UIMin="0.0"))
	float PullMaxRate;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float AutoTrackDuration;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float AutoTrackPullStrength;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float ProjectileMinSpeedForAssist;

	UPROPERTY(EditAnywhere, Category="FortTouchAimAssistSettings")
	float ProjectileMaxLookAheadTime;

};

UCLASS()
class UFortTouchInputSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortTouchInputSettings")
	TObjectPtr<UCurveFloat> LookSensitivityCurve;

	UPROPERTY(EditAnywhere, Category="FortTouchInputSettings")
	TObjectPtr<UCurveFloat> LookVelocityScaleCurve;

	UPROPERTY(EditAnywhere, Category="FortTouchInputSettings")
	TObjectPtr<UCurveFloat> MovementCurve;

	UPROPERTY(EditAnywhere, Category="Aim Assist")
	FFortTouchAimAssistSettings TouchAimAssist;

};

