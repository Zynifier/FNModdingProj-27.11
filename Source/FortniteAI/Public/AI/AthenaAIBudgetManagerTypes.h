// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "AthenaAIBudgetManagerTypes.generated.h"

USTRUCT()
struct FClientAILODMovementCompOptimizationConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration")
	FScalableFloat bEnable;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration")
	FScalableFloat bEnableSimulationDataOptimizations;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinDistanceToApplyFrameSkippingWhenVisible;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrameSkippingOnLOD1;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration")
	FScalableFloat bRequireHittingPawnThresholdForLOD1;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrameSkippingOnLOD2;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration")
	FScalableFloat bRequireHittingPawnThresholdForLOD2;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrameSkippingOnLowestLOD;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrameSkippingOnLowestLODWithSmallViewAngleRendered;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrameSkippingOnLowestLODWithSmallViewAngleNotRendered;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrameSkippingInvisible;

	UPROPERTY(EditAnywhere, Category="ClientAILODMovementCompOptimizationConfiguration")
	FScalableFloat bForceInvisibleValueWhenNotRenderedForThreshold;

};

USTRUCT(BlueprintType)
struct FClientAILODSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FScalableFloat ScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FScalableFloat PreloadingPriorityOverride;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FScalableFloat bSupportCharacterMovementOptimization;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FClientAILODMovementCompOptimizationConfiguration MovementCompOptimizationConfiguration;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FScalableFloat bAIPawnOnlyTickMeshWhenRendered;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	FScalableFloat bAIPawnApplyEffectOptimizations;

};

