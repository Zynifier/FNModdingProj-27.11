// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_LootChoice.generated.h"

class UDataTable;
enum class ECustomLootSelection : uint8;

UENUM(BlueprintType)
enum class ECustomLootSelection : uint8
{
	Default = 0,
	SolidGold = 1,
};

USTRUCT(BlueprintType)
struct FCustomLootOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	ECustomLootSelection CustomLootType;

	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	TObjectPtr<UDataTable> LootTierData;

	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	TObjectPtr<UDataTable> LootPackages;

	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	TObjectPtr<UDataTable> ExperimentalLootTierData;

	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	TObjectPtr<UDataTable> ExperimentalLootPackages;

	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	FGameplayTagContainer PlaylistContextTagsToAdd;

	UPROPERTY(EditDefaultsOnly, Category="CustomLootOverrideData")
	FGameplayTagContainer PlaylistContextTagsToRemove;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_LootChoice : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	ECustomLootSelection GetLootSelection();

	UFUNCTION(BlueprintCallable)
	void SetLootSelection(ECustomLootSelection NewSelection);

protected:
	UPROPERTY(EditAnywhere, Replicated, Category="FortAthenaMutator_LootChoice")
	ECustomLootSelection LootSelection;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_LootChoice")
	TArray<FCustomLootOverrideData> LootOverrideDataList;

	UPROPERTY(EditAnywhere, Replicated, Category="FortAthenaMutator_LootChoice")
	bool bUsingExperimentalTables;

};

