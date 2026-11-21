// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAnimInput_STWHoverboard.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FFortAnimInput_STWHoverBoard
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hoverboard")
	TObjectPtr<UCurveFloat> HoverCycleVelocityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hoverboard")
	TObjectPtr<UCurveFloat> HoverHeightCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hoverboard")
	TObjectPtr<UCurveFloat> HoverLeanCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hoverboard")
	TObjectPtr<UCurveFloat> HoverPitchCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Hoverboard")
	FRotator HoverTransformRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Hoverboard")
	FVector HoverTransformTranslation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverTransformAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverCycle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverLeanAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverPitchAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverYawCurrent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	float HoverIdleLeanAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Hoverboard")
	bool bIsUsingHoverboard;

};

