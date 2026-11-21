// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralDataMap.h"
#include "ProceduralSurfaceSlopeAngleMap.generated.h"

/** Procedural Map that returns a normalized float [0, 1] of a slope angle between 2 vectors relative to a given range. */
UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"), AutoExpandCategories=("Source", "DataMapping"))
class UProceduralSurfaceSlopeAngleMap : public UProceduralFloatDataMap
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Surface Slope Angle Map")
	float GetSlopeAngleRangeMax() const;

	UFUNCTION(BlueprintPure, Category="Procedural Surface Slope Angle Map")
	float GetSlopeAngleRangeMin() const;

	UFUNCTION(BlueprintPure, Category="Procedural Surface Slope Angle Map")
	float GetValue(float InSlopeAngle) const;

	UFUNCTION(BlueprintCallable, Category="Procedural Surface Slope Angle Map")
	void SetSlopeAngleRangeMax(float InValue);

	UFUNCTION(BlueprintCallable, Category="Procedural Surface Slope Angle Map")
	void SetSlopeAngleRangeMin(float InValue);

	/** If disabled, map returns 1 if slope angle is inside the range. If enabled, map returns slope angle normalized inside the range. In all cases, map returns 0 if slope angle is outside of range. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	bool bNormalizedSlopeAngle;

	/** Specifies the slope angle range. */
	UPROPERTY(EditAnywhere, Category="Source", meta=(ClampMax="90", ClampMin="0", UIMax="90", UIMin="0"))
	FFloatInterval SlopeAngleRange;

};

