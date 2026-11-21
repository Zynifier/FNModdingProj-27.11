// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "FortAimAssistSettings.generated.h"

class UCurveFloat;

USTRUCT()
struct FFortAimAssist2D_Settings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat AssistInnerReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat AssistInnerReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat AssistOuterReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat AssistOuterReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat TargetingReticleWidth;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat TargetingReticleHeight;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat TargetRange;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	TObjectPtr<UCurveFloat> TargetWeightCurve;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat TargetWeightDBNOScale;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FFortTargetFilter TargetFilter;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullInnerStrengthHip;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullOuterStrengthHip;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullInnerStrengthAds;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullOuterStrengthAds;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullLerpInRate;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullLerpOutRate;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat PullMaxRotationRate;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowInnerStrengthHip;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowOuterStrengthHip;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowInnerStrengthAds;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowOuterStrengthAds;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowLerpInRate;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowLerpOutRate;

	UPROPERTY(EditAnywhere, Category="FortAimAssist2D_Settings")
	FScalableFloat SlowMinRotationRate;

};

