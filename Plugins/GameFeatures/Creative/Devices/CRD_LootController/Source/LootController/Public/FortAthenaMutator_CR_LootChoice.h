// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CR_LootChoice.generated.h"

class UDataTable;

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CR_LootChoice : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FGameplayTagContainer GetContextTagsToAdd() const;

	UFUNCTION(BlueprintNativeEvent)
	FGameplayTagContainer GetContextTagsToRemove() const;

	UFUNCTION(BlueprintNativeEvent)
	UDataTable* GetLootPackageTable() const;

	UFUNCTION(BlueprintNativeEvent)
	FString GetLootSelectionString() const;

	UFUNCTION(BlueprintNativeEvent)
	UDataTable* GetLootTierDataTable() const;

};

