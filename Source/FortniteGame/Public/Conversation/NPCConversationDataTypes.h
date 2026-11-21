// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "NPCConversationDataTypes.generated.h"

class UFortQuestItemDefinition_Athena;
class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FNPCChosenItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="NPCChosenItemData")
	TObjectPtr<UFortWorldItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="NPCChosenItemData")
	int32 StackSize;

	UPROPERTY(BlueprintReadOnly, Transient, Category="NPCChosenItemData")
	int32 AdditionalClips;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCChosenItemData", meta=(Categories="Tandem.FactionBenefit"))
	FGameplayTag AdditionalRequirementTag;

};

USTRUCT(BlueprintType)
struct FNPCConversationGiftRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCConversationGiftRow", meta=(Categories="AISpawnerData.Type.Tandem"))
	FGameplayTag NPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCConversationGiftRow", meta=(Categories="Athena.Quests.TandemGift"))
	FGameplayTag GiftTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCConversationGiftRow")
	FString AnalyticsEventName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCConversationGiftRow")
	float Weight;

};

USTRUCT(BlueprintType)
struct FNPCDiscountServicesRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDiscountServicesRow", meta=(Categories="Conversation"))
	FGameplayTag NPCConversationTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDiscountServicesRow")
	float DiscountMultiplier;

};

USTRUCT(BlueprintType)
struct FNPCDynamicServiceRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDynamicServiceRow")
	FGameplayTag NPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDynamicServiceRow")
	float Chance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDynamicServiceRow")
	FGameplayTag ServiceTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDynamicServiceRow")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDynamicServiceRow")
	FGameplayTag AdditionalRequirementTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCDynamicServiceRow", meta=(EditCondition="AdditionalRequirementTag.IsValid()"))
	bool bShowAsLockedIfUnavailable;

};

USTRUCT(BlueprintType)
struct FNPCGiftItemInventoryRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCGiftItemInventoryRow")
	FGameplayTag NPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCGiftItemInventoryRow")
	FName LootTier;

	UPROPERTY(EditAnywhere, Category="NPCGiftItemInventoryRow")
	int32 LootLevel;

	UPROPERTY(EditAnywhere, Category="NPCGiftItemInventoryRow")
	int32 OverrideNumDrops;

	UPROPERTY(EditAnywhere, Category="NPCGiftItemInventoryRow")
	FGameplayTagContainer LootTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCGiftItemInventoryRow")
	FGameplayTag AdditionalRequirementTag;

};

USTRUCT(BlueprintType)
struct FNPCQuestRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCQuestRow")
	FGameplayTag NPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCQuestRow")
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> Quest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCQuestRow")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCQuestRow")
	FGameplayTag OptionalFilterCategoryTag;

};

USTRUCT(BlueprintType)
struct FNPCSaleInventoryRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCSaleInventoryRow")
	FGameplayTag NPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCSaleInventoryRow")
	FName LootTier;

	UPROPERTY(EditAnywhere, Category="NPCSaleInventoryRow")
	int32 LootLevel;

	UPROPERTY(EditAnywhere, Category="NPCSaleInventoryRow")
	FGameplayTagContainer LootTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCSaleInventoryRow")
	FGameplayTag OptionalFilterCategoryTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCSaleInventoryRow")
	int32 Priority;

};

USTRUCT(BlueprintType)
struct FSupportedService : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SupportedService")
	FGameplayTag ServiceTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SupportedService", meta=(Categories="Tandem.FactionBenefit"))
	FGameplayTag AdditionalRequirementTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SupportedService")
	bool bShowAsLockedIfUnavailable;

};

