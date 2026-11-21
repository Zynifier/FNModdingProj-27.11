// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "ScalableFloat.h"
#include "FortAIDataProvider_FloatCurveOverGameDifficulty.generated.h"

UCLASS(AutoExpandCategories=("Provider"), meta=(DisplayName="Float Curve Over Game Difficulty"))
class UFortAIDataProvider_FloatCurveOverGameDifficulty : public UAIDataProvider
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Provider", meta=(AllowPrivateAccess="TRUE", DisplayName="CurveFloat By Game Difficulty"))
	FScalableFloat ScalableFloat;

	UPROPERTY()
	float FloatValue;

};

