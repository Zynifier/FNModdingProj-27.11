// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "SlidingCameraModifier.generated.h"

UCLASS()
class USlidingCameraModifier : public UCameraModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float RightOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float HeightOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float CameraOffsetBlendInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float CameraOffsetAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	bool bBlendIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float MinAdditionalFOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float MaxAdditionalFOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	FScalableFloat MaxSlideSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	FScalableFloat MinSlideSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float CameraOffsetBlendOutSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float FovOffsetAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float FovOffsetBlendOutSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float FovOffsetBlendInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float ForwardOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float TargetingAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float TargetingBlendInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingCameraModifier")
	float TargetingBlendOutSeconds;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float CameraOffsetAlpha_ClampMin;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float CameraOffsetAlpha_ClampMax;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float FovOffsetAlpha_ClampMin;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float FovOffsetAlpha_ClampMax;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float TargetingAlpha_ClampMin;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float TargetingAlpha_ClampMax;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float Velocity_ClampMin;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	float Velocity_ClampMax;

	UPROPERTY(EditDefaultsOnly, Category="Constant")
	FGameplayTag TargetingTag;

};

