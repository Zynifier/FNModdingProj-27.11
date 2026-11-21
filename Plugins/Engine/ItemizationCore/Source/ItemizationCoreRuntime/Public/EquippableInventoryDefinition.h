// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryDefinition.h"
#include "EquippableInventoryDefinition.generated.h"

class UItemDefinitionBase;

/** Defines what happens when too many of a group of items are equipped. */
UENUM()
enum class EEquipItemLimitHitBehaviour : uint8
{
	/** Unequip the least recently used items until the limit is satisfied. */
	UnequipLeastRecentlyUsed = 0,
	/** Prevent this action occuring if the limit is hit. */
	Block = 1,
};

/** Helper to choose only particular items. */
USTRUCT()
struct FEquipItemFilter
{
	GENERATED_BODY()

protected:
	/** Should this apply to all items? */
	UPROPERTY(EditDefaultsOnly, Category="Item Filter")
	bool bAppliesToAllItems;

	/** The item definitions this applies to. */
	UPROPERTY(EditDefaultsOnly, Category="Item Filter", meta=(EditCondition="!bAppliesToAllItems"))
	TArray<TSoftObjectPtr<UItemDefinitionBase>> ItemDefinitions;

};

USTRUCT()
struct FEquipItemCondition : public FEquipItemFilter
{
	GENERATED_BODY()

};

USTRUCT()
struct FEquipItemRestriction : public FEquipItemFilter
{
	GENERATED_BODY()

private:
	/** The limit on the number of items (covered by this restriction) which can be equipped (= active) at the same time. */
	UPROPERTY(EditDefaultsOnly, Category="Restriction")
	int64 ActiveLimit;

	/** Defines what happens if the limit is hit. */
	UPROPERTY(EditDefaultsOnly, Category="Restriction")
	EEquipItemLimitHitBehaviour LimitHitBehaviour;

};

/** An inventory holding items which may become (but are not necessarily) equipped i.e. active. */
UCLASS(BlueprintType, Blueprintable)
class ITEMIZATIONCORERUNTIME_API UEquippableInventoryDefinition : public UInventoryDefinition
{
	GENERATED_BODY()

protected:
	/** Set restrictions on how many and which items in this inventory can be equipped at the same time. */
	UPROPERTY(EditDefaultsOnly, Category="Restriction")
	TArray<FEquipItemRestriction> EquipRestrictions;

	/** Conditions under which items entering this inventory will be automatically equipped. */
	UPROPERTY(EditDefaultsOnly, Category="Condition")
	TArray<FEquipItemCondition> EquipConditions;

};

/** Holds multiple items but only one can be active at a time. */
UCLASS(BlueprintType, Blueprintable)
class ITEMIZATIONCORERUNTIME_API UEquipmentHotBar : public UEquippableInventoryDefinition
{
	GENERATED_BODY()

};

/** Simple inventory container holding a single item which will be automatically equipped i.e. made active. */
UCLASS(BlueprintType, Blueprintable)
class ITEMIZATIONCORERUNTIME_API UEquipmentSlot : public UEquippableInventoryDefinition
{
	GENERATED_BODY()

};

