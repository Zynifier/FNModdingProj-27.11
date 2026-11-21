// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralDataMap.h"
#include "ProceduralSurfaceHeightMap.generated.h"

/** Procedural Map that returns a normalized float [0, 1] of a height value inside a given range. */
UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"), AutoExpandCategories=("Source", "DataMapping"))
class UProceduralSurfaceHeightMap : public UProceduralFloatDataMap
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Surface Height Map")
	float GetHeightRangeMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Surface Height Map")
	float GetHeightRangeMin() const;

	UFUNCTION(BlueprintPure, Category="Procedural Surface Height Map")
	float GetValue(float InHeight) const;

	UFUNCTION(BlueprintCallable, Category="Procedural Surface Height Map")
	void SetHeightRangeMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Surface Height Map")
	void SetHeightRangeMin(float InValue);

	/** If disabled, map returns 1 if height is inside the range. If enabled, map returns height normalized inside the range. In all cases, map returns 0 if height is outside of range. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	bool bNormalizedHeight;

	/** Specifies the height range. Map returns 1 if inside range, else 0. */
	UPROPERTY(EditAnywhere, Category="Source")
	FFloatInterval HeightRange;

};

