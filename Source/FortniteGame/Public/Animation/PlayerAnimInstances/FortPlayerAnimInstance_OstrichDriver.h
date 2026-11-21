// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstance_OstrichOccupant.h"
#include "FortPlayerAnimInstance_OstrichDriver.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_OstrichDriver : public UFortPlayerAnimInstance_OstrichOccupant
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance_OstrichDriver")
	float BouncePlayRateValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance_OstrichDriver")
	float LegsBounceAlphaValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float LegsBounceAlphaWhenSkytubing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float LegsBounceAlphaNoSkytubing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeed")
	float LegsBounceAlphaInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_OstrichDriver")
	uint8 bIsSkyTubing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_OstrichDriver")
	uint8 bIsMechMoving2D : 1;

};

