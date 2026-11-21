// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Inventory/AthenaInventoryGroupBase.h"
#include "AthenaInventoryGroupCurrency.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaInventoryGroupCurrency : public UAthenaInventoryGroupBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryGroupCurrency")
	FGameplayTagContainer CurrencyItemTags;

};

