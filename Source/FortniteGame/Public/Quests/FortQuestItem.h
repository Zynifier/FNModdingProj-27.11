// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "Misc/Timespan.h"
#include "FortItemQuantityPair.h"
#include "FortRarityEnum.h"
#include "FortTypes.h"
#include "Items/FortAccountItem.h"
#include "Missions/MissionTypes.h"
#include "Quests/FortQuestTypes.h"
#include "Quests/Processors/IQuestInstanceInterface.h"
#include "FortQuestItem.generated.h"

class AFortClientAnnouncement_Conversation;
class AFortPlayerController;
class UAthenaSeasonItemDefinition;
class UFortMissionConfigData;
class UFortQuestItem;
class UFortQuestItemComponent;
class UFortQuestItemDefinition;
class UFortQuestObjectiveInfo;
class UFortSoundSequence;
enum class EFortQuestState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestObjectiveCompleted, UFortQuestObjectiveInfo*, ObjectiveInstance);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestObjectiveReset, const UFortQuestItem*, QuestItem, const FName, ObjectiveName);

USTRUCT()
struct FCompletionCountEntry
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortXpRewards
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 TotalXp;

	UPROPERTY()
	int32 LevelUpXp;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortQuestItem : public UFortAccountItem, public IQuestInstanceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Quest")
	bool CanPinQuest() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool DoesQuestExpire() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	void GetAchievedCount(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount, int32& OutLastKnownAchievedCount, bool UseLastKnownMcp = true) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	void GetAchievedCountForCurrentStage(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	int32 GetBarsRewardValue() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	FString GetChallengeBundleId() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	FFortRewardInfo GetChallengeChainRewardInfo(bool bGetCurrentChainQuestOnly) const;

	UFUNCTION(BlueprintCallable, Category="Quest")
	UFortMissionConfigData* GetMissionConfigData(const FGameplayTagContainer& InContainer);

	UFUNCTION(BlueprintPure, Category="Quest")
	int32 GetNumObjectivesComplete() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	UFortQuestObjectiveInfo* GetObjectiveInfo(FDataTableRowHandle ObjectiveStatHandle) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	float GetPercentageComplete(const UFortQuestItemDefinition* KnownQuestDef = nullptr) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	TArray<FFortItemInstanceQuantityPair> GetPreviewAllSelectableRewards() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	TArray<FFortItemInstanceQuantityPair> GetPreviewRewards() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	TArray<FFortItemInstanceQuantityPair> GetPreviewSelectableRewards(int32 RewardIndex) const;

	UFUNCTION(BlueprintPure, Category="Quest", meta=(DisplayName="Get Quest Definition"))
	UFortQuestItemDefinition* GetQuestDefinitionBP() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	FString GetQuestPool() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	EFortQuestState GetQuestState() const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	FTimespan GetRemainingExpirationDuration(FDateTime UtcNow) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	FFortRewardInfo GetRewardInfo() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	float GetXpRewardScalar() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	int32 GetXpRewardValue(const UAthenaSeasonItemDefinition* SeasonDef, const AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedAllObjectives(const bool bCheckForTurnInObjective = false) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedObjective(FDataTableRowHandle ObjectiveStatHandle) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedObjectiveWithName(FName BackendName) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasCompletedQuest() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasQuestExpired(FDateTime UtcNow) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasVisibleRewards() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsIncludedInCategories() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsObjectiveInProgress(FDataTableRowHandle ObjectiveStatHandle) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsObjectiveWithNameInProgress(FName BackendName) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsQuestInProgress() const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsQuestPinned() const;

	UFUNCTION(BlueprintPure)
	bool IsVisibleToUser(const bool bAllowClaimedQuestsToBeVisible, const bool bAllowCompletedQuestsToBeVisible = true, const bool bAllowExpiredQuestsToBeVisible = false) const;

	UFUNCTION(BlueprintCallable, Category="Quest")
	void PlayIntroConversation(TSubclassOf<AFortClientAnnouncement_Conversation> QuestConversationClass);

	UFUNCTION(BlueprintPure, Category="QuestItemDefinition")
	bool ShouldDisplayOverallQuestInformation() const;

	UPROPERTY(BlueprintAssignable)
	FOnQuestObjectiveReset OnQuestObjectiveReset;

	UPROPERTY(BlueprintAssignable)
	FOnQuestObjectiveCompleted OnQuestObjectiveCompleted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Quest")
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> Objectives;

protected:
	UFUNCTION()
	void AdvanceSoundSequence();

	UFUNCTION()
	void PlayCurrentSoundSequenceData();

	UFUNCTION()
	void StartSoundSequenceDelay();

	UPROPERTY(BlueprintReadOnly, Category="FortQuestItem")
	EFortQuestState quest_state;

	UPROPERTY()
	bool sent_new_notification;

	UPROPERTY()
	EFortRarity quest_rarity;

	UPROPERTY(Transient)
	bool bIsMine;

	UPROPERTY()
	FDateTime last_state_change_time;

	UPROPERTY(Transient)
	TArray<FCompletionCountEntry> CompletionCounts;

	UPROPERTY(Transient)
	bool bSentCompleteNotification;

	UPROPERTY(Transient)
	bool bAllObjectivesComplete;

	UPROPERTY(Transient)
	bool bIsManuallyGrantedQuest;

	UPROPERTY(Transient)
	bool bIsQuestInTransientState;

	UPROPERTY(Transient)
	bool bIsBoundToQuestProp;

	UPROPERTY(Transient)
	bool bSoundSequenceMuted;

	UPROPERTY(Transient)
	bool bHasSetInitialNotifiedStates;

	UPROPERTY()
	FDateTime expiry_time;

	UPROPERTY()
	FString quest_pool;

	UPROPERTY(Transient)
	int32 CurrentStage;

	UPROPERTY()
	float xp_reward_scalar;

	UPROPERTY(Transient)
	FFortMissionInstancedConfigData InstancedConfigData;

	UPROPERTY(Transient)
	FString challenge_linked_quest_given;

	UPROPERTY(Transient)
	FString challenge_linked_quest_parent;

	UPROPERTY(Transient)
	FString challenge_bundle_id;

	UPROPERTY()
	TArray<FGuid> TrackedGuids;

	UPROPERTY()
	FString Bucket;

	UPROPERTY()
	TArray<FString> Playlists;

	UPROPERTY(Transient)
	int32 SoundSequenceIndex;

	UPROPERTY(Transient)
	TObjectPtr<UFortSoundSequence> ActiveSoundSequence;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItemComponent>> QuestItemComponents;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> UpdatingObjectives;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> ObjectivesToAddToUpdates;

};

