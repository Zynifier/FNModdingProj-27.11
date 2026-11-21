// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "ItemAttributeEntry.h"
#include "ItemEntry.h"
#include "Inventory.generated.h"

class AInventoryCollection;
class UInventoryDefinition;
class UItemComponentStorageManager;

// Item state lets the item react to being added/removed, un/equipped e.g. generate VFX, change animation, ...

UENUM()
enum class EItemState : uint8
{
	NotInInventory = 0,
	// the item is not in an inventory

	InInventory = 1,
	// the item is in an inventory, but not equipped

	Equipped = 2,
	// the item is in an inventory, and is equipped and active

	NumStates = 3 UMETA(Hidden),
};

/*
 * Component that contains items and attribute data. 
 */
UCLASS()
class ITEMIZATIONCORERUNTIME_API UInventory : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_InventoryID();

	UFUNCTION()
	void OnRep_InventoryMaxStackSizeOverride();

	UFUNCTION()
	void OnRep_InventoryTotalSlotsOverride();

	//No previous copy of the structs is necessary, we'll mark within the structs what has changed if necessary.

	UFUNCTION()
	void OnRep_ItemData();

	UPROPERTY(Transient)
	TObjectPtr<AInventoryCollection> OwningInventoryCollection;

	UPROPERTY(Replicated)
	TObjectPtr<UInventoryDefinition> InventoryDefinition;

	UPROPERTY(ReplicatedUsing=OnRep_InventoryID)
	FGuid InventoryID;

	UPROPERTY(ReplicatedUsing=OnRep_ItemData)
	FItemEntryList ItemEntryData;

	UPROPERTY(ReplicatedUsing=OnRep_ItemData)
	FVkAttributeList AttributeData;

	UPROPERTY(ReplicatedUsing=OnRep_InventoryTotalSlotsOverride)
	uint16 InventoryTotalSlotsOverride;

	UPROPERTY(ReplicatedUsing=OnRep_InventoryMaxStackSizeOverride)
	int64 InventoryMaxStackSizeOverride;

	UPROPERTY()
	TArray<uint8> InventoryMaxStackSizeOverrideAttributeData;

	// Runtime storage of local working data for item components

	UPROPERTY()
	TObjectPtr<UItemComponentStorageManager> ItemComponentStorageManager;

};

