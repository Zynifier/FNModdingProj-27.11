// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "FortCheckPointCosmeticActor.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, NotPlaceable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCheckPointCosmeticActor : public ABuildingProp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortCheckPointCosmeticActor", meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> MidPointMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortCheckPointCosmeticActor", meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> EndPointMeshes;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIsEndPointChanged();

	UFUNCTION()
	void OnRep_bIsEndPoint();

	UPROPERTY(BlueprintReadWrite, Replicated, Category="FortCheckPointCosmeticActor")
	int32 CheckPointIndex;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Replicated, Category="FortCheckPointCosmeticActor")
	bool bIsEndPoint;

};

