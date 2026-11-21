// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/AthenaRewardSchedule.h"
#include "AthenaPlayerMatchReport.h"
#include "CatalogTypes.h"
#include "FortItemQuantityPair.h"
#include "Items/FortCampsiteAccountItem.h"
#include "Items/FortPlayerAugmentsAccountItem.h"
#include "Items/FortVictoryCrownAccountItem.h"
#include "Items/RealitySaplingAccountItem.h"
#include "McpCommandContexts.h"
#include "McpSharedTypes.h"
#include "Online/FortMcpProfileSubgame.h"
#include "Quests/FortQuestTypes.h"
#include "SeasonItem/AthenaSeasonItemTypes.h"
#include "FortMcpProfileAthena.generated.h"

class UAthenaSeasonItemDefinition;
class UFortAccountItemDefinition;
class UFortItemDefinition;

UENUM(BlueprintType)
enum class EAthenaFilterDisplayType : uint8
{
	UseCategoryName = 0,
	ShowFilterString = 1,
};

USTRUCT()
struct FAthenaSeasonEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BookLevel;

	UPROPERTY()
	int32 BookXp;

	UPROPERTY()
	int32 NumHighBracket;

	UPROPERTY()
	int32 NumLowBracket;

	UPROPERTY()
	int32 NumWins;

	UPROPERTY()
	bool PurchasedVIP;

	UPROPERTY()
	int32 SeasonLevel;

	UPROPERTY()
	int32 SeasonNumber;

	UPROPERTY()
	int32 SeasonXp;

	UPROPERTY()
	int32 SurvivorTier;

	UPROPERTY()
	int32 SurvivorPrestige;

};

USTRUCT(BlueprintType)
struct FBattlePassOfferPurchaseRecord
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BattlePassOfferPurchaseRecord")
	FString OfferId;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassOfferPurchaseRecord")
	FDateTime PurchaseDate;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassOfferPurchaseRecord")
	TArray<FMcpLootEntry> LootResult;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassOfferPurchaseRecord")
	FPrimaryAssetId CurrencyType;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassOfferPurchaseRecord")
	int32 TotalCurrencyPaid;

};

USTRUCT()
struct FOfferVoteInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime FirstVoteAt;

	UPROPERTY()
	FDateTime LastVoteAt;

	UPROPERTY()
	int32 VoteCount;

};

USTRUCT()
struct FCommunityVoteInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ElectionId;

	UPROPERTY()
	TMap<FString, FOfferVoteInfo> VoteHistory;

	UPROPERTY()
	FDateTime LastVoteGranted;

	UPROPERTY()
	int32 VotesRemaining;

};

USTRUCT()
struct FCompetitiveIdentity
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime LastUpdated;

	UPROPERTY()
	FString RegionId;

};

USTRUCT(BlueprintType)
struct FFortAthenaConsumableRecord
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaConsumableRecord")
	TObjectPtr<UFortAccountItemDefinition> ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaConsumableRecord")
	int32 TotalQuantity;

};

USTRUCT(BlueprintType)
struct FFortAthenaItemCacheRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDef;

};

USTRUCT()
struct FFortAthenaPastSeasonStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BookLevel;

	UPROPERTY()
	int32 BookXp;

	UPROPERTY()
	int32 NumHighBracket;

	UPROPERTY()
	int32 NumLowBracket;

	UPROPERTY()
	int32 NumWins;

	UPROPERTY()
	int32 PurchasesVIP;

	UPROPERTY()
	int32 SeasonLevel;

	UPROPERTY()
	int32 SeasonNumber;

	UPROPERTY()
	int32 SeasonXp;

};

USTRUCT(BlueprintType)
struct FFortAthenaSeasonStats
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortAthenaSeasonStats")
	int32 NumWins;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaSeasonStats")
	int32 NumHighBracket;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaSeasonStats")
	int32 NumLowBracket;

};

USTRUCT(BlueprintType)
struct FFortEndBattleRoyaleGameAnalytics
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> CallStack;

};

USTRUCT(BlueprintType)
struct FFortInventorySnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FJsonObjectWrapper Stash;

};

USTRUCT()
struct FHardcoreModifierUpdate
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModifierId;

	UPROPERTY()
	bool bEnabled;

};

UCLASS(MinimalAPI)
class UFortMcpProfileAthena : public UFortMcpProfileSubgame
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void ApplyVote(const FString& OfferId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execApplyVote);

	UFUNCTION(BlueprintPure)
	bool CanPurchaseSeasonBook() const;

	UFUNCTION(ServiceRequest(MCP))
	void ChallengeBundleLevelUp(const FString& BundleIdToLevel, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execChallengeBundleLevelUp);

	UFUNCTION(ServiceRequest(MCP))
	void DeleteModularCosmeticLoadout(const FString& LoadoutType, const FString& PresetId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execDeleteModularCosmeticLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void EndBattleRoyaleGameV2(const TArray<FFortQuestObjectiveCompletion>& Advance, const FString& PlaylistId, const FAthenaMatchStats& MatchStats, int32 TotalXPAccum, int32 RestedXPAccum, int32 FriendshipXpBoost, int32 CosmeticXpBoost, float AntiAddictionPlayTimeMultiplier, bool ShouldAccumulateToProfileStats, bool ShouldSaveToRecentGameLists, const TArray<FString>& ShuffledLoadoutUsed, int32 ShuffledLockerUsedIndex, const TArray<FFortQuestDelete>& DeletedQuests, const TArray<FString>& GrantedQuestDefs, const TArray<FSecondaryXpGained>& SecondaryXp, const TArray<FFortCreateItemDetail>& GrantedItems, const TArray<FFortTransientQuestGrant>& GrantedQuests, const TArray<FFortTransientQuestGrant>& CompletedQuestsToClaim, const FString& PinnedSharedQuest, const TArray<FAthenaSeasonItemMCPState>& SeasonItemStates, const FCampsiteAccountData& CampsiteData, const FVictoryCrownAccountData& VictoryCrownData, const FRealitySaplingAccountData& RealitySaplingData, const FPlayerAugmentsPersistenceData& PlayerAugmentsPersistenceData, const TArray<FString>& PlayerAugmentsCollected, int32 PlayerTimeInMatchSec, const TArray<FFortQuestAnalyticEvent>& QuestAnalyticEvents, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execEndBattleRoyaleGameV2);

	UFUNCTION(ServiceRequest(MCP))
	void EquipModularCosmeticLoadoutPreset(const FString& LoadoutType, const FString& PresetId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execEquipModularCosmeticLoadoutPreset);

	UFUNCTION(ServiceRequest(MCP))
	void ExchangeGameCurrencyForBattlePassOffer(const TArray<FString>& OfferItemIdList, const FCatalogPurchaseAdditionalData& AdditionalData, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execExchangeGameCurrencyForBattlePassOffer);

	UFUNCTION(ServiceRequest(MCP))
	void ExchangeGiftToken(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execExchangeGiftToken);

	UFUNCTION(BlueprintPure)
	UAthenaSeasonItemDefinition* GetActiveSeasonDefinition() const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrencyTotal(const FString& CurrencyStatName) const;

	UFUNCTION(BlueprintPure)
	int32 GetSeasonBookLevel() const;

	UFUNCTION(BlueprintPure)
	int32 GetSeasonFriendMatchXpBoost() const;

	UFUNCTION(BlueprintPure)
	FAthenaSeasonRewardLevelInfo GetSeasonLevelInfo(const int32 SeasonLevel) const;

	UFUNCTION(BlueprintCallable)
	bool GetSeasonLevelUpReward(int32 SeasonLevel, FFortItemInstanceQuantityPair& Reward, int32& RewardLevel);

	UFUNCTION(BlueprintPure)
	int32 GetSeasonMatchXpBoost() const;

	UFUNCTION(BlueprintPure)
	int32 GetSeasonRestedXp() const;

	UFUNCTION(BlueprintPure)
	int32 GetSurvivorPrestige() const;

	UFUNCTION(BlueprintPure)
	int32 GetSurvivorTier() const;

	UFUNCTION(BlueprintPure)
	bool HasPurchasedSeasonBook() const;

	UFUNCTION(ServiceRequest(MCP))
	void PutModularCosmeticLoadout(const FString& LoadoutType, const FString& PresetId, const FString& LoadoutData, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPutModularCosmeticLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void RedeemSTWAccoladeTokens(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRedeemSTWAccoladeTokens);

	UFUNCTION(ServiceRequest(MCP))
	void ReportConsumableUsed(int32 UsedQuantity, const FString& ItemType, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execReportConsumableUsed);

	UFUNCTION(ServiceRequest(MCP))
	void RequestRestedStateIncrease(int32 timeToCompensateFor, int32 restedXpGenAccumulated, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRequestRestedStateIncrease);

	UFUNCTION(ServiceRequest(MCP))
	void SetHardcoreModifier(const TArray<FHardcoreModifierUpdate>& Updates, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetHardcoreModifier);

	UFUNCTION(ServiceRequest(MCP))
	void SetRewardGraphConfig(const TArray<FString>& state, const FString& rewardGraphId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetRewardGraphConfig);

	UFUNCTION(ServiceRequest(MCP))
	void ToggleQuestActiveState(const TArray<FString>& QuestIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execToggleQuestActiveState);

	UFUNCTION(ServiceRequest(MCP))
	void UnlockRewardNode(const FString& nodeId, const FString& rewardGraphId, const FString& rewardCfg, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUnlockRewardNode);

private:
	UFUNCTION(ServiceRequest(MCP))
	void AthenaPinQuest(const FString& PinnedQuest, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAthenaPinQuest);

	UFUNCTION()
	void HandleActiveEventFlagsChanged(const TArray<FString>& ActiveEventFlags);

	UPROPERTY(Config)
	float ClientQuestLoginTimerNoise;

};

