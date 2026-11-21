// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortItemQuantityPair.h"
#include "STW/CollectionBook/FortCollectionBookTypes.h"
#include "FortCollectionBookManager.generated.h"

class UFortAccountItem;
class UFortCollectionBookManager;
class UFortCollectionBookPage;
class UFortItem;
class UFortItemDefinition;
class UFortMcpProfileCollectionBook;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortCollectionBookClaimRewardCompleteDelegate, FFortCollectionBookRewards, RewardClaimed, bool, bSuccess, const TArray<FFortItemInstanceQuantityPair>&, ActualRewards);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortCollectionBookInventoryUpdatedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortCollectionBookResearchItemOperationCompleteDelegate, const UFortAccountItem*, NewItem, FString, TemplateId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortCollectionBookSlottedItemOperationCompleteDelegate, const UFortAccountItem*, ItemSlotted, FName, SlotId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortCollectionBookUnslottedItemOperationCompleteDelegate, const UFortAccountItem*, UnslottedItem, const UFortAccountItem*, OldItem, FName, SlotId);

USTRUCT()
struct FFortCollectionBookStat
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MaxBookXpLevelAchieved;

};

USTRUCT()
struct FFortPendingSlottedItemOperation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SlottedItemId;

	UPROPERTY()
	FName SlotRowName;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortCollectionBookManager : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPagesChanged, UFortCollectionBookManager*, CollectionBookManager);

public:
	UFUNCTION(BlueprintPure, Category="CollectionBook")
	int32 CalculateBookXp() const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	int32 CalculatePageXp(FName PageId) const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	bool CanSlotItem(const UFortAccountItem* AccountItem, bool bOnlyAllowIfSlotEmpty, UPARAM(ref) FName& OutSlotId) const;

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	void ClaimReward(const FFortCollectionBookRewards& RewardToClaim, int32 RewardIndex);

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	bool DoesItemSlotExistInCollectionBook(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	int32 GetBookTotalXPToNextLevel(int32 CurrentLevel) const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	float GetBookXPPercentToNextLevel(int32 CurrentLevel, int32 NewXP) const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	UFortItem* GetItemInSlot(FName SlotId) const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	bool IsItemMissingFromCollectionBook(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	void PopulateCollectionBookRewards(TArray<FFortCollectionBookRewards>& OutAvailableRewards);

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	bool PurchaseItem(const UFortAccountItem* Item);

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	bool SlotItem(const UFortAccountItem* Item, FName SlotId);

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	bool UnSlotItem(const UFortAccountItem* Item);

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FOnPagesChanged OnPagesChanged;

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FFortCollectionBookSlottedItemOperationCompleteDelegate OnSlottedItemOperationComplete;

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FFortCollectionBookSlottedItemOperationCompleteDelegate OnSlotItemComplete;

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FFortCollectionBookInventoryUpdatedDelegate OnInventoryUpdated;

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FFortCollectionBookClaimRewardCompleteDelegate OnRewardClaimed;

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FFortCollectionBookUnslottedItemOperationCompleteDelegate OnUnslotItemComplete;

	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FFortCollectionBookResearchItemOperationCompleteDelegate OnResearchItemComplete;

private:
	UPROPERTY(Transient)
	TArray<FFortPendingSlottedItemOperation> PendingSlottedItems;

	UPROPERTY(Transient)
	TArray<FFortPendingSlottedItemOperation> PendingUpdatedItems;

	UPROPERTY(Transient)
	TMap<FName, TObjectPtr<UFortMcpProfileCollectionBook>> ProfileTable;

	UPROPERTY(Transient)
	TMap<FString, TObjectPtr<UFortCollectionBookPage>> PageTable;

	UPROPERTY(Transient)
	TSet<FString> TemporaryPageTemplateIds;

};

