// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortClientSettingsRecord.h"
#include "FortItemQuantityPair.h"
#include "Quests/FortQuestItemDefinitionTypes.h"
#include "Quests/QuestManagerComponents/FortQuestManagerComponent.h"
#include "FortQuestManagerComponent_Campaign.generated.h"

class AFortPlayerController;
class AFortPlayerState;
class UDataTable;
class UFortQuestCategory;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestObjectiveInfo;
enum class EFortQuestObjectiveStatEvent : uint8;
enum class EFortQuestType : uint8;
enum class EQuestMapScreenMode : uint8;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FBPOnObjectiveUpdated, const int32, ArchivedCount, AFortPlayerController*, PlayerController);

USTRUCT()
struct FObjectiveUpdateCallback
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortQuestItem> QuestItem;

};

USTRUCT()
struct FPrimaryMissionQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> PrimaryMissionObjectives;

};

USTRUCT()
struct FUpdatingQuestsByObjectiveInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> QuestList;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortQuestCategory : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quests")
	int32 GetUnseenQuestCount();

	UFUNCTION(BlueprintCallable, Category="Quests")
	bool HasUnseenQuests();

	UPROPERTY(BlueprintReadOnly, Category="Quests")
	FText Name;

	UPROPERTY(BlueprintReadOnly, Category="Quests")
	TArray<TObjectPtr<UFortQuestItem>> CurrentQuests;

	UPROPERTY(BlueprintReadWrite, Category="Quests")
	bool bExpanded;

private:
	UPROPERTY()
	FFortCategoryTableRow CategoryInfo;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortQuestManagerComponent_Campaign : public UFortQuestManagerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDailyQuestRerolled, const UFortQuestItem*, NewQuest);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestRewardClaimed, const UFortQuestItem*, Quest, const TArray<FFortItemInstanceQuantityPair>&, Rewards);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestSeen, const UFortQuestItem*, Quest);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleDynamicMulticastDelegate);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Quests")
	void ClaimQuestReward(const UFortQuestItem* Quest) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Quests")
	void ClaimSelectedQuestReward(const UFortQuestItem* Quest, int32 RewardIndex) const;

	UFUNCTION(BlueprintPure, Category="Quests")
	void GetCurrentQuestsCategories(TArray<UFortQuestCategory*>& Categories);

	UFUNCTION(BlueprintPure, Category="Quests")
	UFortQuestItem* GetMainQuest() const;

	UFUNCTION(BlueprintCallable, Category="Quests")
	UFortQuestItem* GetNextUnseenQuest(EFortQuestType QuestType);

	UFUNCTION(BlueprintCallable, Category="Quests")
	void GetPinnedQuests(TArray<UFortQuestItem*>& OutPinnedQuestItems);

	UFUNCTION(BlueprintPure, Category="Quests")
	const UFortQuestCategory* GetQuestCategory(UFortQuestItem* QuestItem);

	UFUNCTION(BlueprintPure)
	EQuestMapScreenMode GetQuestMapMode() const;

	UFUNCTION(BlueprintPure, Category="Quests")
	void GetQuestsFromCategory(UFortQuestCategory* Category, TArray<UFortQuestItem*>& QuestList);

	UFUNCTION(BlueprintPure, Category="Quests")
	int32 GetRemainingDailyQuestRerolls() const;

	UFUNCTION(BlueprintPure, Category="Quests")
	int32 GetRemainingQuestPoolRerolls(const FString& PoolName) const;

	UFUNCTION(BlueprintCallable, Category="Quests")
	int32 GetUnseenQuestCount();

	UFUNCTION(BlueprintCallable, Category="Quests")
	void GrantFirstDailyQuest();

	UFUNCTION(BlueprintPure, Category="Quests")
	bool HasQuestBeenSeenLocally(const UFortQuestItem* Quest) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool HasUnsavedPrimaryMissionProgress() const;

	UFUNCTION(BlueprintCallable, Category="Quests")
	bool HasUnseenQuests();

	UFUNCTION(BlueprintPure, Category="Quests")
	bool IsMainQuest(UFortQuestItem* Quest) const;

	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsPendingFeatureUnlockNotification() const;

	UFUNCTION(BlueprintPure)
	bool IsThisAnEventQuest(const UFortQuestItemDefinition* QuestDefinition, const FString& MatchQuestEventFlag, UDataTable* QuestTable = nullptr) const;

	UFUNCTION(BlueprintCallable, Category="Quests")
	void MarkQuestSeen(UFortQuestItem* Quest);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Quests")
	void MarkQuestsSeen(bool bOnlyMarkPendingSeenQuests = false) const;

	UFUNCTION(BlueprintCallable, Category="Quest")
	FString PopNextPendingFeatureUnlock();

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Quests")
	void RerollDailyQuest(const UFortQuestItem* QuestToDiscard) const;

	UFUNCTION()
	void SetQuestMapMode(EQuestMapScreenMode NewQuestMapMode);

	UFUNCTION(BlueprintCallable, Category="Quests")
	bool SetQuestPinned(UFortQuestItem* Quest, bool bEnabled);

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnDailyQuestRerolled OnDailyQuestRerolled;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnQuestSeen OnQuestSeen;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate OnPinnedQuestsChanged;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnQuestRewardClaimed OnQuestRewardClaimed;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FSimpleDynamicMulticastDelegate OnNoQuestRewardsToClaim;

private:
	UFUNCTION()
	void HandleQuestObjectiveUpdated(AFortPlayerController* QuestOwner, const UFortQuestItemDefinition* QuestDef, FName BackendName, int32 CompletionCount, int32 DeltaChange, const AFortPlayerState* AssistingPlayer, const EFortQuestObjectiveStatEvent StatEvent);

	UPROPERTY()
	TMap<FName, TObjectPtr<UFortQuestCategory>> CurrentCategorizedQuestsMap;

	UPROPERTY()
	EQuestMapScreenMode QuestMapMode;

	UPROPERTY()
	TArray<TObjectPtr<UDataTable>> EventQuestDataTables;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> UncategorizedQuests;

	UPROPERTY(Config)
	bool bBlockStWQuestCompletion;

	UPROPERTY()
	TMap<FName, FUpdatingQuestsByObjectiveInfo> UpdatingQuestsByObjective;

	UPROPERTY()
	TArray<FPrimaryMissionQuestData> PrimaryMissionObjectives;

	UPROPERTY()
	TArray<FObjectiveUpdateCallback> ObjectiveCallbacks;

};

