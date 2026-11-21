// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Animation/FortDefenderAnimInstance.h"
#include "CreativeSentryAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCreativeSentryAnimInstance : public UFortDefenderAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	float RotateAimAnimationPitch;

	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	float CounterRotateAimAnimationPitch;

	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	bool bIsRelaxedLevel1OrNotTargeting;

	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	float RightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	float OneMinusLeftHandFK;

	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	float LeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Category="CreativeSentryAnimInstance")
	float RetargetHandIKBonesToFKPositionWeight;

};

