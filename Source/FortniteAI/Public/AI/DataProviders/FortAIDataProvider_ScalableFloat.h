// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "ScalableFloat.h"
#include "FortAIDataProvider_ScalableFloat.generated.h"

UCLASS(AutoExpandCategories=("Provider"), meta=(DisplayName="Scalable Float Data Provider"))
class UFortAIDataProvider_ScalableFloat : public UAIDataProvider
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Provider")
	FScalableFloat ScalableFloat;

	UPROPERTY()
	float FloatValue;

	UPROPERTY()
	int32 IntValue;

	UPROPERTY()
	bool BoolValue;

};

