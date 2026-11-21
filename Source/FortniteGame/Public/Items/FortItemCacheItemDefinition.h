// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortItemCacheItemDefinition.generated.h"

class UFortCardPackItemDefinition;

UCLASS(BlueprintType, HideCategories=("Functionality", "Attributes", "AutoEquip", "Disassembly", "Outpost", "InventoryLimit"))
class UFortItemCacheItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortItemCacheItemDefinition")
	TSoftObjectPtr<UFortCardPackItemDefinition> CardPackReward;

};

