// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Inventory/AthenaInventoryGroupBase.h"
#include "AthenaInventoryGroupIngredients.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaInventoryGroupIngredients : public UAthenaInventoryGroupBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaInventoryGroupIngredients")
	FGameplayTagContainer IngredientItemTagContainer;

};

