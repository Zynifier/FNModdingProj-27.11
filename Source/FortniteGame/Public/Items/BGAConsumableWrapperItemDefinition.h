// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Items/FortItemDefinition.h"
#include "BGAConsumableWrapperItemDefinition.generated.h"

class ABuildingGameplayActorConsumable;

UCLASS(BlueprintType, HideCategories=("FrontendPreview", "Display", "Functionality", "Series", "InventoryLimit", "OwnedTags", "Tooltips", "Rating"))
class UBGAConsumableWrapperItemDefinition : public UFortItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	TSoftClassPtr<ABuildingGameplayActorConsumable> ConsumableClass;

	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	FScalableFloat MinNumberConsumablesToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	FScalableFloat MaxNumberConsumablesToSpawn;

};

