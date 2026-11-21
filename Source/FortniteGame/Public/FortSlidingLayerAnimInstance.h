// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortSlidingLayerAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortSlidingLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Entry")
	bool bBypassEntry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	bool bIsKneeSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	bool bTransitionToKneeSlide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	FVector KneeSlideLowerBodyInitialVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	FVector KneeSlideLowerBodyInitialVectorSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	float KneeSlideSlopeYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	float KneeSlideRootYawOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	float KneeSlideSlopeYawMinusRootRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	float KneeSlideSlopeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Knee Slide")
	float KneeSlideForwardVectorVelocityDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Knee Slide")
	bool bFastPathNotInitiatedSlideUpHillAndTransitionToKneeSlide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding|Spine Tweak")
	float SpineTweakLean;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding")
	bool bInitiatedSlideUpHill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Sliding")
	float VelocityAimYawDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float KneeSlideAngleSlopeLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float KneeSlideRootYawOffsetClampValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float KneeSlideRootYawOffsetMaxRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float SpineTweakAccelerationLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float SpineTweakValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float KneeSlideLowerBodyInitialRotSmoothingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float MinKneeSlideSlopeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float MaxKneeSlideForwardVectorVelocityDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Sliding|Magic Number")
	float DirectionVectorPlaneChangeThreshold;

};

