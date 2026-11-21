// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Inventory/AthenaInventoryGroupBase.h"
#include "AthenaInventoryGroupResources.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaInventoryGroupResources : public UAthenaInventoryGroupBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryGroupResources")
	FGameplayTagContainer CurrencyItemTags;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryGroupResources")
	FGameplayTagContainer IngredientItemTags;

};

