// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "Camera/FortFirstPersonState.h"
#include "ApplyAnimatedMotionUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UApplyAnimatedMotionUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction")
	EMotionTarget Target;

	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction")
	FVector TranslationInheritRatios;

	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction")
	FRotator RotationInheritRatios;

	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction", meta=(ClampMax="1.0", ClampMin="0.0"))
	float MotionBlendRate;

	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction")
	bool bAnimationDataIsZeroed;

	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction", meta=(ClampMax="1.0", ClampMin="0.0", EditCondition="!bAnimationDataIsZeroed"))
	float MotionDecayRate;

	UPROPERTY(EditAnywhere, Category="ApplyAnimatedMotionUpdateFunction", meta=(ClampMax="5.0", ClampMin="0.0"))
	float MaxYawRate;

private:
	UPROPERTY(Transient)
	FTransform RawTransform;

	UPROPERTY(Transient)
	FTransform SmoothedTransform;

	UPROPERTY(Transient)
	int32 RootBoneIndex;

};

