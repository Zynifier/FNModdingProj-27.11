// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortItemAndCount.h"
#include "FortAthenaAISpawnerDataComponent_InventoryBase.generated.h"

USTRUCT()
struct FAILootInfoRowEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Loot")
	FGameplayTagQuery OptionalTagQuery;

	UPROPERTY(EditAnywhere, Category="Loot")
	uint8 bShouldDropInventoryOnDeath : 1;

	UPROPERTY(EditAnywhere, Category="Loot")
	uint8 bShouldDropLootOnDeath : 1;

	UPROPERTY(EditAnywhere, Category="Loot")
	uint8 bShouldGrantLootOnSpawn : 1;

	UPROPERTY(EditAnywhere, Category="Loot", meta=(EditCondition="bShouldDropLootOnDeath || bShouldGrantLootOnSpawn"))
	TArray<FName> LootTiers;

};

USTRUCT()
struct FFortAthenaAILootInfoDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Loot")
	TArray<FAILootInfoRowEntry> LootDroppingBehaviors;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaAIRuntimeParameters_Inventory : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FDataTableRowHandle LootInfo;

private:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAIRuntimeParameters_Inventory", meta=(AllowPrivateAccess="true"))
	uint8 bShouldDropCurrencyOnDeath : 1;

	UPROPERTY(Transient)
	uint8 bDefaultInventoryIgnoresRestrictions : 1;

	UPROPERTY(Transient)
	uint8 bSkipInventoryInitialization : 1;

	UPROPERTY(Transient)
	uint8 bAddStartingItemsToInventory : 1;

	UPROPERTY(Transient)
	uint8 bRemoveAllItemsOnInitialization : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAIRuntimeParameters_Inventory", meta=(AllowPrivateAccess="true"))
	uint8 bIgnoreItemSupportRestrictions : 1;

	UPROPERTY(Transient)
	FName CurrencyPayoutRowName;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAIRuntimeParameters_Inventory", meta=(AllowPrivateAccess="true"))
	uint8 bDeathTagsCanBlockLootDrop : 1;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_InventoryBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetInventoryItems(TArray<FItemAndCount>& OutList);

	UFUNCTION(BlueprintCallable)
	virtual void SetInventoryItems(const TArray<FItemAndCount>& InItems);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	TArray<FItemAndCount> Items;

private:
	UPROPERTY(EditAnywhere, Category="Currency", meta=(AllowPrivateAccess="true"))
	FScalableFloat ShouldDropCurrencyOnDeath;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefaultInventoryIgnoresRestrictions;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FScalableFloat IgnoreItemSupportRestrictions;

	UPROPERTY(EditAnywhere, Category="Currency", meta=(AllowPrivateAccess="true"))
	FName CurrencyPayoutRowName;

	UPROPERTY(EditAnywhere, Category="Loot", meta=(AllowPrivateAccess="true"))
	FDataTableRowHandle LootInfo;

	UPROPERTY(EditAnywhere, Category="Loot", meta=(AllowPrivateAccess="true"))
	bool bDeathTagsCanBlockLootDrop;

	UPROPERTY(EditAnywhere, Category="Loot", meta=(AllowPrivateAccess="true"))
	bool bAddStartingItemsToInventory;

	UPROPERTY(EditAnywhere, Category="Loot", meta=(AllowPrivateAccess="true"))
	bool bRemoveAllItemsOnInitialization;

	UPROPERTY(EditAnywhere, Category="AIPawn", meta=(AllowPrivateAccess="true"))
	bool bUseDefenderInventoryManagement;

};

