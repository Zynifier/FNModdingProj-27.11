// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingContainer.h"
#include "FortItemQuantityPair.h"
#include "BuildingCustomizableSpawnContainer.generated.h"

UCLASS(HideCategories=("ForKismetOnly", "Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTimeOfDayLightsActorClassData)
class ABuildingCustomizableSpawnContainer : public ABuildingContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Replicated, Category="Creative")
	TArray<FFortItemQuantityPair> SpawnItems;

protected:
	UFUNCTION(BlueprintCallable)
	void ValidateSpawnItems();

};

