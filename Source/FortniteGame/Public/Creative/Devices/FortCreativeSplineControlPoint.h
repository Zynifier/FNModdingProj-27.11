// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Creative/FortCreativeDeviceProp.h"
#include "FortCreativeSplineControlPoint.generated.h"

class ABuildingActor;
class AFortCreativeSplineControlPoint;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeSplineControlPoint : public AFortCreativeDeviceProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CacheTangentIntensity(float ArriveTangentIntensity, float LeaveTangentIntensity);

	UFUNCTION(BlueprintNativeEvent)
	float GetArriveTangentIntensity() const;

	UFUNCTION(BlueprintNativeEvent)
	float GetLeaveTangentIntensity() const;

	UFUNCTION(BlueprintNativeEvent)
	ESplinePointType::Type GetSplinePointType() const;

	UFUNCTION(BlueprintCallable)
	void OnPropertiesUpdated();

protected:
	UPROPERTY(EditAnywhere, SaveGame, Replicated, Category="FortCreativeSplineControlPoint")
	int32 SplineIndex;

	UPROPERTY(EditAnywhere, SaveGame, Replicated, Category="FortCreativeSplineControlPoint")
	bool bInitializedFromOwningSplineProp;

	UPROPERTY(EditAnywhere, SaveGame, Replicated, Category="FortCreativeSplineControlPoint")
	ABuildingActor* OwningSplineProp;

	UPROPERTY(EditAnywhere, SaveGame, Replicated, Category="FortCreativeSplineControlPoint")
	AFortCreativeSplineControlPoint* CopiedFrom;

	UPROPERTY(EditAnywhere, SaveGame, Replicated, Category="FortCreativeSplineControlPoint")
	AFortCreativeSplineControlPoint* CopiedFromCut;

};

