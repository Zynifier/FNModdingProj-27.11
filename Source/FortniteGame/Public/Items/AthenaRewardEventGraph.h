// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "Items/FortPersistableItemDefinition.h"
#include "AthenaRewardEventGraph.generated.h"

class UAthenaRewardEventGraphCosmeticItemDefinition;
class UFortAccountItemDefinition;
class UFortAthenaRewardEventGraphPurchaseToken;
class UFortItemDefinition;
class UFortTokenType;

USTRUCT()
struct FRewardKeyData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RewardKeyData")
	TSoftObjectPtr<UFortTokenType> Key;

	UPROPERTY(EditAnywhere, Category="RewardKeyData")
	FGameplayTag NodeTagMatchReq;

	UPROPERTY(EditAnywhere, Category="RewardKeyData")
	int32 RewardKeyMaxCount;

	UPROPERTY(EditAnywhere, Category="RewardKeyData")
	int32 RewardKeyInitialCount;

	UPROPERTY(EditAnywhere, Category="Display", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UFortAccountItemDefinition> UnlockingItemDef;

	UPROPERTY(EditAnywhere, Category="Display")
	bool bUseUnlockingItemDisplayName;

};

USTRUCT()
struct FRewardNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	TSoftObjectPtr<UFortTokenType> RequiredKey;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	int32 KeyCount;

	UPROPERTY(VisibleDefaultsOnly, Category="RewardNode")
	int32 MinKeyCountToUnlock;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	int32 DaysFromEventStartToUnlock;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	FGameplayTagContainer ChildNodes;

	UPROPERTY(VisibleDefaultsOnly, Category="RewardNode")
	FGameplayTagContainer ParentNodes;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	FGameplayTag NodeTag;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	bool bGrantedAtGraphDestruction;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	bool bRequiredOwnership;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	TArray<FAthenaRewardItemReference> Rewards;

	UPROPERTY(EditAnywhere, Category="RewardNode")
	FString RewardOperation;

	UPROPERTY(EditAnywhere, Category="RewardNode")
	TSoftObjectPtr<UFortItemDefinition> RewardContextItem;

	UPROPERTY(EditDefaultsOnly, Category="RewardNode")
	TArray<FCosmeticVariantInfo> HardDefinedVisuals;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("FrontendPreview", "FortItemDefinition", "Functionality", "InventoryLimit", "Series", "Rating"))
class UAthenaRewardEventGraph : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph")
	FString CalendarEventName;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph")
	FString CalendarEventType;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph")
	TSoftObjectPtr<UFortAthenaRewardEventGraphPurchaseToken> PurchaseToken;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph", meta=(TitleProperty="Key"))
	TArray<FRewardKeyData> RewardKey;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph")
	bool bRewardKeysInternally;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph", meta=(TitleProperty="NodeTag"))
	TArray<FRewardNode> Rewards;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ItemsToCleanUpUponRemoval;

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardEventGraph")
	TObjectPtr<UAthenaRewardEventGraphCosmeticItemDefinition> CosmeticRandomnes;

};

