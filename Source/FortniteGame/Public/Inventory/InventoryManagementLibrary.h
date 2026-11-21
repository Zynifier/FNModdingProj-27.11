// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Guid.h"
#include "FortItemAndCount.h"
#include "Items/FortItemEntry.h"
#include "InventoryManagementLibrary.generated.h"

class AFortPlayerController;
class IFortInventoryOwnerInterface;
class UFortControllerComponent_InventoryNetworkManagement;
class UFortItem;
class UFortItemDefinition;
class UFortWorldItem;
enum class EFortRarity : uint8;

UCLASS(MinimalAPI, meta=(ScriptName="InventoryManagementLibrary"))
class UInventoryManagementLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory Management")
	static UFortWorldItem* AddItem(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition, int32 Count, const bool bShouldFireCollectStatEvent = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory Management")
	static TArray<UFortWorldItem*> AddItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<FItemAndCount> Items);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static UFortItem* FindExistingItemForDefinition(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition, bool bInStorageVault = false);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static UFortControllerComponent_InventoryNetworkManagement* GetInventoryNetworkComponent(AFortPlayerController* Owner);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static int32 GetItemCountForItemDefinition(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static void GetItemsFromInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<UFortWorldItem*>& Items);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static void GetItemsFromInventoryOwnerForRarity(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<UFortWorldItem*>& Items, const EFortRarity RarityType);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static bool GiveItemEntryToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const FFortItemEntry& ItemInstance);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory Management")
	static bool RemoveItem(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, FGuid ItemGuid, int32 Count);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory Management")
	static void RemoveItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, TArray<FItemGuidAndCount> Items);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static bool SwapItem(TScriptInterface<IFortInventoryOwnerInterface> SourceOwner, TScriptInterface<IFortInventoryOwnerInterface> TargetOwner, FGuid ItemGuid, int32 Count);

	UFUNCTION(BlueprintCallable, Category="Inventory Management")
	static void SwapItems(TScriptInterface<IFortInventoryOwnerInterface> SourceOwner, TScriptInterface<IFortInventoryOwnerInterface> TargetOwner, TArray<FItemGuidAndCount> ItemGuids);

};

