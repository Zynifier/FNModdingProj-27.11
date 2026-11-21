// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Misc/Guid.h"
#include "InventoryCollection.generated.h"

class UInventory;
class UInventoryDefinition;
class UItemAttribute_Int;
class UItemDefinitionBase;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ITEMIZATIONCORERUNTIME_API AInventoryCollection : public AInfo
{
	GENERATED_BODY()

public:
	/** Returns true if the item was equipped. Items can only be equipped (= made active) inside a VkEquippableInventory or subclass. */
	UFUNCTION(BlueprintCallable, Category="Inventory Collection")
	bool EquipItem(const FGuid& ItemEntryID);

	/** Outputs all inventories contained in this collection. Returns true if any inventories were found. */
	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	bool GetAllInventoriesInCollection(TArray<FGuid>& OutInventoryIDList) const;

	/** Returns true if any items were found. */
	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	bool GetAllItemsInInventory(const FGuid& TargetInventoryID, TArray<FGuid>& OutItemEntryIDList) const;

	/** Returns all inventory IDs in this collection which are using this inventory definition. */
	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	TArray<FGuid> GetInventoriesWithInventoryDefinition(const UInventoryDefinition* InventoryDefinition) const;

	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	const UInventoryDefinition* GetInventoryDefinition(const FGuid& TargetInventoryID) const;

	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	const FText& GetInventoryName(const FGuid& TargetInventoryID) const;

	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	int64 GetItemAmount(const UItemDefinitionBase* ItemDefinition) const;

	/** Gets the total number of items matching the input ItemDefinition from the input TargetInventoryID. */
	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	int64 GetItemAmountFromInventory(const UItemDefinitionBase* ItemDefinition, const FGuid& TargetInventoryID) const;

	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	const UItemDefinitionBase* GetItemDefinition(const FGuid& TargetInventoryID, const FGuid& ItemEntryID) const;

	//This should be maintainable - for programmers, it may be easier to use ItemAttribute.h global static template functions.

	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	int64 GetItemIntAttribute(const FGuid& TargetInventoryID, const FGuid& ItemEntryID, const TSubclassOf<UItemAttribute_Int>& Attribute) const;

	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	int32 GetItemSlotNumber(const FGuid& TargetInventoryID, const FGuid& ItemEntryID) const;

	/** Returns true if the item is currently equipped (= active). Items can only be equipped inside an EquippableInventory class. */
	UFUNCTION(BlueprintPure, Category="Inventory Collection")
	bool IsItemEquipped(const FGuid& ItemEntryID) const;

	/** Returns true if the item was unequipped. Items can only be unequipped (= made inactive) inside an EquippableInventory class. */
	UFUNCTION(BlueprintCallable, Category="Inventory Collection")
	bool UnequipItem(const FGuid& ItemEntryID);

protected:
	//List of inventories within this collection.

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UInventory>> InventoryList;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FGuid, TObjectPtr<UInventory>> InventoryMap;

	//Map used to speed up looking for an item entry's owning inventory during queries.

	UPROPERTY(Transient)
	TMap<FGuid, FGuid> ItemInventoryMap;

};

