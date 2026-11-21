// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemEntry.h"
#include "FortSpawnableItemInterface.generated.h"

class ABuildingActor;
class UFortGameplayTagContainer;

UINTERFACE(MinimalAPI, BlueprintType)
class UFortSpawnableItemInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortSpawnableItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SpawnableItemInterface")
	bool CanBeAddedToSpawnList() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SpawnableItemInterface")
	bool CanBeSpawned(const UFortGameplayTagContainer* InvalidGameplayTagContainer, ABuildingActor* InBuildingActor) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SpawnableItemInterface")
	TArray<FFortItemEntry> GetSpawnItemEntries(const UFortGameplayTagContainer* InvalidGameplayTagContainer) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SpawnableItemInterface")
	void OnAddedToSpawnList();

};

