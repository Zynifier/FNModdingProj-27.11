// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureData.h"
#include "MLDeformerGameFeatureData.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UMLDeformerGameFeatureData : public UFortGameFeatureData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ML Deformer")
	bool bDisableWhenOwnerIsNotViewTarget;

	UPROPERTY(EditDefaultsOnly, Category="ML Deformer", meta=(InlineEditConditionToggle))
	bool bShouldRampUpWeightWhenEnabled;

	UPROPERTY(EditDefaultsOnly, Category="ML Deformer", meta=(EditCondition="bShouldRampUpWeightWhenEnabled"))
	float WeightIncreasePerSecond;

};

