// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortInventory.h"
#include "FortInventoryOutpost.generated.h"

class UFortWorldItem;

UCLASS(MinimalAPI)
class AFortInventoryOutpost : public AFortInventory
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortWorldItem>> UnavailableItemInstances;

	UPROPERTY(Replicated)
	bool bHasUnavailableItems;

};

