// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortEndZoneScoreAndAwards.h"
#include "FortGameMode.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "Items/FortPersistentGameplayStatValue.h"
#include "McpCommandContexts.h"
#include "McpProfileRequestTypes.h"
#include "Online/FortMcpProfileSubgame.h"
#include "Quests/FortQuestTypes.h"
#include "STW/Items/FortOutpostItemDefinition.h"
#include "FortMcpProfileCampaign.generated.h"

class UFortCampaignHeroLoadoutItem;
class UFortMcpProfileCampaign;
enum class ECampaignCustomizationCategory : uint8;

UENUM(BlueprintType)
enum class ECampaignCustomizationCategory : uint8
{
	None = 0,
	PersonalVehicle = 1,
};

USTRUCT()
struct FAccountIdAndMatchEndData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	TArray<FFortQuestObjectiveCompletion> Advance;

	UPROPERTY()
	TArray<FFortQuestEarnedBadgeData> EarnedBadgeData;

	UPROPERTY()
	TArray<FString> EarnedItemCaches;

	UPROPERTY()
	int32 TotalScore;

	UPROPERTY()
	bool bCriticalMatchBonus;

	UPROPERTY()
	bool bDidLeech;

	UPROPERTY()
	int32 NumMissionPoints;

	UPROPERTY()
	TArray<FString> ShuffledLoadoutUsed;

	UPROPERTY()
	int32 ShuffledLockerUsedIndex;

	UPROPERTY()
	TArray<FString> UsedCosmetics;

	UPROPERTY()
	int32 TheaterNum;

	UPROPERTY()
	FMcpProfileChangeRequest TheaterItemUpdate;

	UPROPERTY()
	int32 OutpostNum;

	UPROPERTY()
	FMcpProfileChangeRequest OutpostItemUpdate;

	UPROPERTY()
	FString OutpostId;

	UPROPERTY()
	FFortOutpostCoreInfo OutpostInfo;

	UPROPERTY()
	FString DeployableBaseItemId;

	UPROPERTY()
	FFortCloudSaveInfo CloudSaveInfo;

	UPROPERTY()
	FString LockCode;

	UPROPERTY()
	bool bAbandoning;

	UPROPERTY()
	EAthenaRebootEligiblityStatus EligibilityStatus;

	UPROPERTY()
	float MissionLeechScaling;

	UPROPERTY()
	int32 TotalSecondsInMatch;

};

UCLASS(MinimalAPI)
class UFortMcpProfileCampaign : public UFortMcpProfileSubgame
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDifferentHeroLoadoutActivated, UFortMcpProfileCampaign*, Profile);

public:
	UFUNCTION(ServiceRequest(MCP))
	void AbandonExpedition(const FString& ExpeditionId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAbandonExpedition);

	UFUNCTION(ServiceRequest(MCP))
	void ActivateConsumable(const FString& TargetItemId, const FString& TargetAccountId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execActivateConsumable);

	UFUNCTION(ServiceRequest(MCP))
	void ApplyAlteration(const FString& TargetItemId, const FString& AlterationItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execApplyAlteration);

	UFUNCTION(ServiceRequest(MCP))
	void AssignGadgetToLoadout(const FString& GadgetId, const FString& LoadoutId, int32 SlotIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAssignGadgetToLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void AssignHeroToLoadout(const FString& HeroId, const FString& LoadoutId, const FString& SlotName, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAssignHeroToLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void AssignTeamPerkToLoadout(const FString& TeamPerkId, const FString& LoadoutId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAssignTeamPerkToLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void AssignWorkerToSquad(const FString& CharacterId, const FString& SquadId, int32 SlotIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAssignWorkerToSquad);

	UFUNCTION(ServiceRequest(MCP))
	void AssignWorkerToSquadBatch(const TArray<FString>& CharacterIds, const TArray<FString>& SquadIds, const TArray<int32>& SlotIndices, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execAssignWorkerToSquadBatch);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimCollectedResources(const TArray<FString>& CollectorsToClaim, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimCollectedResources);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimCollectionBookRewards(int32 RequiredXp, int32 SelectedRewardIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimCollectionBookRewards);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimDifficultyIncreaseRewards(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimDifficultyIncreaseRewards);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimLoginReward(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimLoginReward);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimMissionAlertRewards(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimMissionAlertRewards);

	UFUNCTION(ServiceRequest(MCP))
	void ClearHeroLoadout(const FString& LoadoutId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClearHeroLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void CollectExpedition(const FString& ExpeditionTemplate, const FString& ExpeditionId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execCollectExpedition);

	UFUNCTION(ServiceRequest(MCP))
	void ConsumeItems(const TArray<FString>& ItemsToConsumeIds, const TArray<int32>& ItemCountsToConsume, const FString& ConsumeReason, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execConsumeItems);

	UFUNCTION(ServiceRequest(MCP))
	void ConvertItem(const FString& TargetItemId, int32 ConversionIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execConvertItem);

	UFUNCTION(ServiceRequest(MCP))
	void ConvertLegacyAlterations(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execConvertLegacyAlterations);

	UFUNCTION(ServiceRequest(MCP))
	void EarnScore(const TArray<FAccountIdAndScore>& PlayersAndScores, const FString& MatchmakingSessionId, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execEarnScore);

	UFUNCTION(ServiceRequest(MCP))
	void EndMatch(const TArray<FAccountIdAndMatchEndData>& PlayersAndMatchEndData, const FString& MatchmakingSessionId, const FString& MissionName, const FString& MissionStatus, int32 DifficultyIncreaseTier, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execEndMatch);

	UFUNCTION(ServiceRequest(MCP))
	void EndPrimaryMission(const TArray<FFortQuestObjectiveCompletion>& Advance, const FString& MatchmakingSessionId, const FString& MissionName, const FString& MissionStatus, const TArray<FFortQuestEarnedBadgeData>& EarnedBadgeData, const TArray<FString>& EarnedItemCaches, int32 DifficultyIncreaseTier, int32 NumMissionPoints, bool bCriticalMatchBonus, const TArray<FString>& ShuffledLoadoutUsed, int32 ShuffledLockerUsedIndex, int32 TotalSecondsInMatch, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execEndPrimaryMission);

	UFUNCTION(ServiceRequest(MCP))
	void EquipCampaignCustomization(ECampaignCustomizationCategory SlotName, const FString& ItemToSlot, int32 IndexWithinSlot, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execEquipCampaignCustomization);

	UFUNCTION(ServiceRequest(MCP))
	void FailsafeSaveMissionResults(const FEndZoneScoreAndAwards& PlayerScoreData, const FString& MatchmakingSessionId, const FString& MissionName, const FString& MissionStatus, int32 DifficultyIncreaseTier, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execFailsafeSaveMissionResults);

	UFUNCTION(BlueprintPure, Category="HeroLoadout")
	void GetCurrentHeroLoadoutItem(UFortCampaignHeroLoadoutItem*& OutCampaignHeroLoadoutItem) const;

	UFUNCTION(BlueprintPure, Category="HeroLoadout")
	TArray<UFortCampaignHeroLoadoutItem*> GetOrderedHeroLoadoutItems();

	UFUNCTION(ServiceRequest(MCP))
	void ModifyMission(const FString& MatchmakingSessionId, const FString& Difficulty, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execModifyMission);

	UFUNCTION(ServiceRequest(MCP))
	void OpenCardPack(const FString& CardPackItemId, int32 SelectionIdx, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execOpenCardPack);

	UFUNCTION(ServiceRequest(MCP))
	void OpenCardPackBatch(const TArray<FString>& CardPackItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execOpenCardPackBatch);

	UFUNCTION(ServiceRequest(MCP))
	void OverrideMissionRewardLootLevel(const FString& MatchmakingSessionId, int32 OverrideLootLevel, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execOverrideMissionRewardLootLevel);

	UFUNCTION(ServiceRequest(MCP))
	void OverrideMissionRewardLootTierGroup(const FString& MatchmakingSessionId, const FString& OverrideRewardTag, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execOverrideMissionRewardLootTierGroup);

	UFUNCTION(ServiceRequest(MCP))
	void PopulatePrerolledOffers(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPopulatePrerolledOffers);

	UFUNCTION(ServiceRequest(MCP))
	void PromoteItem(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPromoteItem);

	UFUNCTION(ServiceRequest(MCP))
	void PurchaseOrUpgradeHomebaseNode(const FString& NodeId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPurchaseOrUpgradeHomebaseNode);

	UFUNCTION(ServiceRequest(MCP))
	void PurchaseResearchStatUpgrade(const FString& StatId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPurchaseResearchStatUpgrade);

	UFUNCTION(ServiceRequest(MCP))
	void RecycleItem(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRecycleItem);

	UFUNCTION(ServiceRequest(MCP))
	void RecycleItemBatch(const TArray<FString>& TargetItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRecycleItemBatch);

	UFUNCTION(ServiceRequest(MCP))
	void RefreshExpeditions(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRefreshExpeditions);

	UFUNCTION(ServiceRequest(MCP))
	void RefundItem(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRefundItem);

	UFUNCTION(ServiceRequest(MCP))
	void ResearchItemFromCollectionBook(const FString& TemplateId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execResearchItemFromCollectionBook);

	UFUNCTION(ServiceRequest(MCP))
	void RespecAlteration(const FString& TargetItemId, int32 AlterationSlot, const FString& AlterationId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRespecAlteration);

	UFUNCTION(ServiceRequest(MCP))
	void RespecResearch(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRespecResearch);

	UFUNCTION(ServiceRequest(MCP))
	void RespecUpgrades(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRespecUpgrades);

	UFUNCTION(ServiceRequest(MCP))
	void SetActiveHeroLoadout(const FString& SelectedLoadout, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetActiveHeroLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void SetGameplayStats(const TArray<FFortPersistentGameplayStatValue>& GameplayStats, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetGameplayStats);

	UFUNCTION(ServiceRequest(MCP))
	void SetHeroCosmeticVariants(const FString& HeroItem, const TArray<FMcpVariantReader>& OutfitVariants, const TArray<FMcpVariantReader>& BackblingVariants, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetHeroCosmeticVariants);

	UFUNCTION(ServiceRequest(MCP))
	void SetLoadoutName(const FString& LoadoutName, const FString& LoadoutId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetLoadoutName);

	UFUNCTION(ServiceRequest(MCP))
	void SkipTutorial(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSkipTutorial);

	UFUNCTION(ServiceRequest(MCP))
	void SlotItemInCollectionBook(const FString& ItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSlotItemInCollectionBook);

	UFUNCTION(ServiceRequest(MCP))
	void StartExpedition(const FString& ExpeditionId, const FString& SquadId, const TArray<FString>& ItemIds, const TArray<int32>& SlotIndices, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execStartExpedition);

	UFUNCTION(ServiceRequest(MCP))
	void StartPrimaryMission(const TArray<FFortQuestObjectiveCompletion>& Advance, const FString& MatchmakingSessionId, const FString& MissionName, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execStartPrimaryMission);

	UFUNCTION(ServiceRequest(MCP))
	void TransmogItem(const FString& TransmogKeyTemplateId, const TArray<FString>& SacrificeItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execTransmogItem);

	UFUNCTION(ServiceRequest(MCP))
	void UnassignAllSquads(const TArray<FString>& SquadIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUnassignAllSquads);

	UFUNCTION(ServiceRequest(MCP))
	void UnloadWarehouse(const TArray<FString>& ResourceTypes, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUnloadWarehouse);

	UFUNCTION(ServiceRequest(MCP))
	void UnslotAllWorkers(const TArray<FString>& BuildingIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUnslotAllWorkers);

	UFUNCTION(ServiceRequest(MCP))
	void UnslotItemFromCollectionBook(const FString& ItemId, const FString& Specific, const FString& TemplateId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUnslotItemFromCollectionBook);

	UFUNCTION(ServiceRequest(MCP))
	void UpdateBuildingLevelAndRating(const FString& BuildingId, int32 LastBuildingLevel, int32 LastBuildingRating, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpdateBuildingLevelAndRating);

	UFUNCTION(ServiceRequest(MCP))
	void UpgradeAlteration(const FString& TargetItemId, int32 AlterationSlot, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpgradeAlteration);

	UFUNCTION(ServiceRequest(MCP))
	void UpgradeItem(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpgradeItem);

	UFUNCTION(ServiceRequest(MCP))
	void UpgradeItemBulk(const FString& TargetItemId, int32 DesiredLevel, const FString& DesiredTier, int32 ConversionRecipeIndexChoice, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpgradeItemBulk);

	UFUNCTION(ServiceRequest(MCP))
	void UpgradeItemRarity(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpgradeItemRarity);

	UPROPERTY(BlueprintAssignable, Category="HeroLoadout")
	FOnDifferentHeroLoadoutActivated OnDifferentHeroLoadoutActivated;

private:
	UPROPERTY(Config)
	bool bEnableHeroLoadoutMocking;

	UPROPERTY(Config)
	float HeroLoadoutCommandDelaySeconds;

};

