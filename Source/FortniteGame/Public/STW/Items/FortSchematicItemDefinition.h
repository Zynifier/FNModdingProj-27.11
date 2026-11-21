// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortTypes.h"
#include "STW/Items/FortAlterableItemDefinition.h"
#include "FortSchematicItemDefinition.generated.h"

class AFortPlayerPawn;
class UFortWorldItemDefinition;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType)
class UFortSchematicItemDefinition : public UFortAlterableItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Crafting")
	bool DoesResultWorldItemDisassembleRecipeMatchExactly() const;

	UFUNCTION(BlueprintPure, Category="Crafting")
	USoundBase* GetCraftingSuccessSound() const;

	UFUNCTION(BlueprintPure, Category="Item")
	float GetCraftingTime(int32 Level) const;

	UFUNCTION(BlueprintPure, Category="Item")
	float GetCraftingTimeForCharacter(int32 Level, const AFortPlayerPawn* FortPawn) const;

	UFUNCTION(BlueprintPure, Category="Crafting")
	int32 GetQuantityProduced() const;

	UFUNCTION(BlueprintPure, Category="Crafting")
	FRecipe GetRecipe() const;

	UFUNCTION(BlueprintPure, Category="Crafting")
	UFortWorldItemDefinition* GetResultWorldItemDefinition() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootLevel")
	FDataTableCategoryHandle LootLevelData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Crafting")
	FName CraftingTimeRowName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	bool bUseSchematicDisplayName;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Crafting")
	FDataTableRowHandle CraftingRecipe;

	UPROPERTY(EditAnywhere, Category="Crafting")
	TSoftObjectPtr<USoundBase> CraftingSuccessSound;

	UPROPERTY()
	TWeakObjectPtr<UFortWorldItemDefinition> CachedResultWorldItemDefinition;

};

