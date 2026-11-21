// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralScaleModifier.h"
#include "ProceduralScaleNoiseModifier.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralScaleNoiseModifier : public UProceduralScaleModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Scale Noise Modifier")
	float GetScaleMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Scale Noise Modifier")
	float GetScaleMin() const;

	UFUNCTION(BlueprintCallable, Category="Procedural Scale Noise Modifier")
	void SetScaleMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Scale Noise Modifier")
	void SetScaleMin(float InValue);

	/** Specifies the scale range. */
	UPROPERTY(EditAnywhere, Category="Modifier", meta=(ClampMax="1.0", ClampMin="0.001", UIMax="1.0", UIMin="0.001"))
	FFloatInterval Scale;

};

