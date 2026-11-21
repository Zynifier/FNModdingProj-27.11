// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Components/FortCreativeSplineModificationComponent.h"
#include "SplinePropInterface.generated.h"

class USceneComponent;
class USplineComponent;

UINTERFACE(MinimalAPI, BlueprintType)
class USplinePropInterface : public UInterface
{
	GENERATED_BODY()
};

class ISplinePropInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Spline Prop")
	TArray<FSplinePoint_Serializable> GetSavedSplinePoints() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Spline Prop")
	USplineComponent* GetSplineComponent() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Spline Prop")
	TArray<USceneComponent*> GetTransientSceneComponents() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Spline Prop")
	void OnSplinePointsChanged(int32 NumSplinePointsPreChange);

	UFUNCTION(BlueprintImplementableEvent, Category="Spline Prop")
	void SaveSplinePointData();

	UFUNCTION(BlueprintImplementableEvent, Category="Spline Prop")
	void SetSerializedSplinePoints(const TArray<FSplinePoint_Serializable>& SplinePoints);

	UFUNCTION(BlueprintImplementableEvent, Category="Spline Prop")
	void UpdateSplineMeshAtIndex(int32 SplineMeshIndex);

};

