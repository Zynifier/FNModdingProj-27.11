// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "McpSharedTypes.h"
#include "FortMcpProfileAccountTypes.generated.h"

USTRUCT()
struct FCardPackResultNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMcpLootResult LootGranted;

	UPROPERTY()
	int32 DisplayLevel;

};

USTRUCT()
struct FFortClaimedDifficultyIncreaseRewardNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMcpLootResult LootGranted;

};

USTRUCT()
struct FFortCollectedResourceNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMcpLootResult Loot;

};

USTRUCT()
struct FFortCollectionBookClaimRewardNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMcpLootResult Loot;

	UPROPERTY()
	FString Page;

	UPROPERTY()
	FString Section;

};

USTRUCT()
struct FFortCollectionBookResearchItemNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ResearchedItemId;

	UPROPERTY()
	FString ResearchedTemplateId;

};

USTRUCT()
struct FFortCollectionBookSlotItemNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SlottedItemId;

};

USTRUCT()
struct FFortCollectionBookUnslotItemNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString UnslottedItemId;

};

USTRUCT()
struct FFortConversionResultNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMcpLootEntry> ItemsGranted;

};

USTRUCT()
struct FFortCraftingResultNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMcpLootEntry> ItemsCrafted;

};

USTRUCT()
struct FFortDailyQuestRerollNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString NewQuestId;

};

USTRUCT()
struct FFortDifficultyIncreaseRewardEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 DifficultyIncreaseTier;

	UPROPERTY()
	FMcpLootResult DifficultyIncreaseMissionRewards;

};

USTRUCT()
struct FFortDifficultyIncreaseRewardRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortDifficultyIncreaseRewardEntry> PendingRewards;

};

USTRUCT()
struct FFortEarnScoreNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BaseXPEarned;

	UPROPERTY()
	int32 BonusXPEarned;

	UPROPERTY()
	int32 BoostXPEarned;

	UPROPERTY()
	int32 BoostXPMissed;

	UPROPERTY()
	int32 RestXPEarned;

	UPROPERTY()
	int32 GroupBoostXPEarned;

};

USTRUCT()
struct FFortEndMatchScoreNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FFortEarnScoreNotification> scoreNotifications;

};

USTRUCT()
struct FFortEventFlagsNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> EventFlags;

	UPROPERTY()
	FDateTime RefreshTime;

};

USTRUCT()
struct FFortExpeditionResultNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bExpeditionSucceeded;

	UPROPERTY()
	TArray<FMcpLootEntry> ExpeditionRewards;

};

USTRUCT()
struct FFortGetMcpTimeForPlayerNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime McpTime;

};

USTRUCT()
struct FFortIslandCreatedNotification_PurgedIsland
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PlotId;

	UPROPERTY()
	FString VkProjectId;

};

USTRUCT()
struct FFortIslandCreatedNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PlotId;

	UPROPERTY()
	TArray<FFortIslandCreatedNotification_PurgedIsland> PurgedIslands;

};

USTRUCT()
struct FFortLootNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LootSource;

	UPROPERTY()
	FString LootSourceInstance;

	UPROPERTY()
	FMcpLootResult LootGranted;

};

USTRUCT()
struct FFortMissionAlertClaimData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString MissionAlertId;

	UPROPERTY()
	FDateTime RedemptionDateUtc;

	UPROPERTY()
	FDateTime EvictClaimDataAfterUtc;

};

USTRUCT()
struct FFortMissionAlertCompleteNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMcpLootResult LootGranted;

};

USTRUCT()
struct FFortMissionAlertRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortMissionAlertClaimData> ClaimData;

	UPROPERTY()
	FMcpLootResult PendingMissionAlertRewards;

};

USTRUCT()
struct FFortMissionCompletionNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bWasCritical;

	UPROPERTY()
	FString MissionName;

	UPROPERTY()
	FMcpLootResult LootGranted;

};

USTRUCT()
struct FFortNotificationLevelUp
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Level;

	UPROPERTY()
	FString HeroId;

	UPROPERTY()
	FFortLootNotification Loot;

};

USTRUCT()
struct FFortNotificationPurchaseCatalogEntry
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortPhoenixLevelUpNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Level;

	UPROPERTY()
	FFortLootNotification Loot;

};

USTRUCT()
struct FFortQuestRewardData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString QuestId;

	UPROPERTY()
	FMcpLootResult Loot;

};

USTRUCT()
struct FFortQuestRewardNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString QuestId;

	UPROPERTY()
	FMcpLootResult Loot;

	UPROPERTY()
	TArray<FFortQuestRewardData> QuestsAndRewards;

};

USTRUCT()
struct FFortReceivedGiftedBoostXpNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 AmountBoostXpGifted;

	UPROPERTY()
	FString GifterAccountId;

};

USTRUCT()
struct FFortTransmogResultNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMcpLootEntry> TransmoggedItems;

	UPROPERTY()
	TArray<FMcpLootEntry> RecycledItems;

};

USTRUCT()
struct FFortUpgradeItemRarityNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMcpLootEntry> ItemsGranted;

};

USTRUCT()
struct FFriendCodeIssuedNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Code;

	UPROPERTY()
	FString CodeType;

};

USTRUCT()
struct FImportFriendsRewardNotification
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Items")
	TArray<FMcpLootEntry> LootGranted;

};

