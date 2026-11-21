// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralScaleModifier.h"
#include "ProceduralScaleMapModifier.generated.h"

class UProceduralFloatDataMap;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralScaleMapModifier : public UProceduralScaleModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Scale Map Modifier")
	float GetRemapScaleMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Scale Map Modifier")
	float GetRemapScaleMin() const;

	UFUNCTION(BlueprintCallable, Category="Procedural Scale Map Modifier")
	void SetRemapScaleMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Scale Map Modifier")
	void SetRemapScaleMin(float InValue);

	/** Whether or not to remap scale value read from data map. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier", meta=(InlineEditConditionToggle))
	bool bRemapScale;

	/** Specifies the scale range. */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="1.0", ClampMin="0.001", EditCondition="bRemapScale", UIMax="1.0", UIMin="0.001"))
	FFloatInterval RemapScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Modifier")
	TObjectPtr<UProceduralFloatDataMap> Map;

};

