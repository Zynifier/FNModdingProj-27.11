// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryDefinition.generated.h"

class UInventoryRestriction;

UCLASS(BlueprintType)
class ITEMIZATIONCORERUNTIME_API UInventoryDefinition : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition")
	FText Description;

	/** The maximum number of item slots which this inventory can contain. By default, items stack so each slot may contain more than one of that item type. This can be changed with 'bEnableItemStacking'. */// 65535 (MAX_uint16) is used to represent an invalid index so we can't use it.

	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition", meta=(ClampMax="65534", ClampMin="1"))
	uint16 Slots;

	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition", meta=(ClampMax="200", ClampMin="1"))
	uint8 PickupPriority;

	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition")
	TObjectPtr<UInventoryRestriction> InventoryRestriction;

	/** If false, all items in this inventory will only be allowed a maximum stack size of one (and thus occupy a single slot each), regardless of other settings. */
	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition")
	bool bEnableItemStacking;

	/** If true, this inventory will only allow one stack per given unique item definition. */
	UPROPERTY(EditDefaultsOnly, Category="Inventory Definition")
	bool bRequireUniqueItemDefinitionPerStack;

};

