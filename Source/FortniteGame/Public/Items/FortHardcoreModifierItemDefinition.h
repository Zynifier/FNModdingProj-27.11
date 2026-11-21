// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Items/FortPersistableItemDefinition.h"
#include "FortHardcoreModifierItemDefinition.generated.h"

class UFortAbilitySet;
class UFortAccoladeItemDefinition;

UENUM(BlueprintType)
enum class EFortHardcoreModifierTier : uint8
{
	Bronze = 0,
	Silver = 1,
	Gold = 2,
	Platinum = 3,
	Diamond = 4,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "InventoryLimit", "Rating", "Functionality", "Frontend"))
class UFortHardcoreModifierItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Hardcore Modifier Data")
	TSoftObjectPtr<UFortAbilitySet> ModifierAbilitySet;

	UPROPERTY(EditAnywhere, Category="Hardcore Modifier Data")
	FGameplayTagContainer AdditionalSourceTagsToAdd;

	UPROPERTY(EditAnywhere, Category="Hardcore Modifier Data")
	TArray<TSoftObjectPtr<UFortAccoladeItemDefinition>> TierAccolades;

};

