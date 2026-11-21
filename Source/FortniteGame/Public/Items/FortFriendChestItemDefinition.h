// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortAccountItemDefinition.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortFriendChestItemDefinition.generated.h"

class UFortAccoladeItemDefinition;
class UFortItemDefinition;
class UFriendChestInstancedDetail;

UENUM(BlueprintType)
enum class EFriendChestInstancedType : uint8
{
	/** Some item definition we want to wrap.  This is needed if there are grant period restrictions */
	ItemDefinition = 0,
	/** This is not granted to player visually, but is used to track if we are in Fresh or Drip conditions for Instanced Loot */
	FreshDripCounter = 1,
	/** To be used in future to grant XP */
	GrantXp = 2,
	Undefined = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFriendChestTimePeriod : uint8
{
	/** In sync with daily quests */
	Daily = 0,
	/** In sync with weekly quests */
	Weekly = 1,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "InventoryLimit", "Rating", "Functionality", "Frontend", "FrontendPreview", "Tooltips", "Series"))
class UFortFriendChestItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="FriendChest", meta=(ExpandByDefault))
	TObjectPtr<UFriendChestInstancedDetail> InstancedDetail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChest")
	EFriendChestTimePeriod TimePeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChest")
	int32 GrantsPerPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChest")
	int32 GrantsPerSeason;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChest")
	int32 CatchupBankSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChest")
	bool bAllowSeasonCatchup;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI)
class UFriendChestInstancedDetail : public UObject
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFriendChestInstancedDetail_FreshDripCounter : public UFriendChestInstancedDetail
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChestInstancedDetail_FreshDripCounter")
	FGameplayTag FreshTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChestInstancedDetail_FreshDripCounter")
	FGameplayTag DripTag;

};

UCLASS(MinimalAPI)
class UFriendChestInstancedDetail_GrantXp : public UFriendChestInstancedDetail
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChestInstancedDetail_GrantXp")
	TSoftObjectPtr<UFortAccoladeItemDefinition> Accolade;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChestInstancedDetail_GrantXp")
	EFortQuestObjectiveStatEvent AccoladeEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChestInstancedDetail_GrantXp")
	FGameplayTagContainer TargetTags;

};

UCLASS(MinimalAPI)
class UFriendChestInstancedDetail_ItemDefinition : public UFriendChestInstancedDetail
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FriendChestInstancedDetail_ItemDefinition")
	TSoftObjectPtr<UFortItemDefinition> InstancedItem;

};

