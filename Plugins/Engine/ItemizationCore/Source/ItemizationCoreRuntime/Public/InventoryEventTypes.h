// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryEventTypes.generated.h"

//Struct that represents a collection of information about an inventory item for inventory events (item removal for example).
//Used to represent an item's data if querying that item properly is not possible (like item was removed).
//Should not be used to represent a real item. Should not be replicated or serialized.

USTRUCT(BlueprintType)
struct FItemAggregatedData
{
	GENERATED_BODY()

};

