// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Items/FortPersistentTypes.h"
#include "Quests/FortQuestObjectiveStatXPTable.h"
#include "Quests/FortQuestTypes.h"
#include "Quests/QuestManagerComponents/FortQuestManagerComponent.h"
#include "FortQuestManagerComponent_Athena.generated.h"

class AFortPlayerController;
class AFortPlayerState;
class UAthenaQuestCategoryManager;
class UFortAccoladeItem;
class UFortChallengeBundleItem;
class UFortFeatItemDefinition;
class UFortHardcoreModifierItem;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestItemDefinition_Athena;
enum class EFortQuestObjectiveStatEvent : uint8;

UENUM(BlueprintType)
enum class EAthenaChallengeTimerState : uint8
{
	Hidden = 0,
	WeeksRemaining = 1,
	DaysRemaining = 2,
	HoursRemaining = 3,
	MinutesRemaining = 4,
	Urgent = 5,
};

USTRUCT(BlueprintType)
struct FSharedQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SharedQuestData")
	TArray<TObjectPtr<UFortQuestItem>> SharedQuests;

	UPROPERTY(BlueprintReadOnly, Category="SharedQuestData")
	TObjectPtr<UFortQuestItem> PinnedQuest;

};

USTRUCT()
struct FSharedQuestRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="SharedQuestRow")
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> Quest;

	UPROPERTY(VisibleAnywhere, Category="SharedQuestRow")
	FString Bucket;

	UPROPERTY(VisibleAnywhere, Category="SharedQuestRow")
	float Weight;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortQuestManagerComponent_Athena : public UFortQuestManagerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveStatXPGranted, const FXPEventInfo&, XPEvent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuestVOMuteHoldEnded);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestVOMuteHoldStarted, const float, Duration);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestVOMuteStateChanged, const bool, bIsMuted);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestVOPlayStateChanged, const bool, bIsPlaying);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSharedQuestChanged, const FUniqueNetIdRepl&, PlayerId, const UFortQuestItem*, QuestToPin);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransientQuestAdded, const UFortQuestItem*, AddedQuestItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransientQuestRemoved, const UFortQuestItem*, TransientQuestItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTransientQuestStarted, const UFortQuestItem*, TransientQuestItem, const UFortQuestItemDefinition_Athena*, PreceedingQuestDefAthena);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUrgentTransientQuestCompleted, const UFortQuestItem*, TransientQuestItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUrgentTransientQuestFailed, const UFortQuestItem*, TransientQuestItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUrgentTransientQuestStarted, const UFortQuestItem*, TransientQuestItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnXpDeltasUpdated, int32, CombatXp, int32, ServivalXp, int32, MedalBonusXP, int32, ChallengeXp, int32, MatchXp, int32, TotalXp);

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Quest", meta=(AutoCreateRefTerm="SourceTags,ContextTags,TargetTags"))
	void AppendTemporaryRelevancyTags(const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, const FGameplayTagContainer& TargetTags);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortChallengeBundleItem>> CurrentChallengeBundles;

	UPROPERTY(Transient)
	bool bHasSentMatchStarted;

	UPROPERTY(Transient)
	TArray<FFortDisplayQuestUpdateData> DisplayQuestUpdateData;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnTransientQuestStarted OnTransientQuestStarted;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnTransientQuestAdded OnTransientQuestAdded;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnTransientQuestRemoved OnTransientQuestRemoved;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnUrgentTransientQuestStarted OnUrgentTransientQuestStarted;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnUrgentTransientQuestCompleted OnUrgentTransientQuestCompleted;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnUrgentTransientQuestFailed OnUrgentTransientQuestFailed;

private:
	UFUNCTION()
	void HandleQuestObjectiveUpdated(AFortPlayerController* QuestOwner, const UFortQuestItemDefinition* QuestDef, FName BackendName, int32 CompletionCount, int32 DeltaChange, const AFortPlayerState* AssistingPlayer, EFortQuestObjectiveStatEvent StatEvent);

	UPROPERTY()
	TArray<TObjectPtr<UFortAccoladeItem>> CurrentAccolades;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> CurrentFeats;

	UPROPERTY(Transient)
	TSet<TObjectPtr<UFortFeatItemDefinition>> FeatsCompletedThisSession;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> ActiveTransientQuests;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> CompletedQuests;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> RemovedTransientQuests;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> ActiveMilestoneQuests;

	UPROPERTY(Transient)
	TArray<FFortQuestAnalyticEvent> McpQuestAnalyticEvents;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, FSharedQuestData> SquadSharedQuestData;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaQuestCategoryManager> QuestCategoryManager;

	UPROPERTY(Transient)
	TSet<TObjectPtr<UFortQuestItem>> ActiveQuestVO;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortHardcoreModifierItem>> HardcoreModifiersToUse;

	UPROPERTY()
	TArray<TObjectPtr<UFortHardcoreModifierItem>> CurrentHardcoreModifiers;

	UPROPERTY()
	FGameplayTagContainer CurrentHardcoreModifierSrcTags;

	UPROPERTY(Config)
	bool bBlockAthenaQuestCompletion;

	UPROPERTY(Config)
	bool bBlockAthenaQuestCompletionInCompetitive;

	UPROPERTY(Config)
	bool bAllowAthenaMCPNotifyOnComplete;

	UPROPERTY(Config)
	bool bBlockPartyAssist;

	UPROPERTY(Config)
	bool bUseSquadForPartyAssist;

	UPROPERTY(Config)
	bool bBlockBRXPWhenDead;

	UPROPERTY(Config)
	bool bBlockXPEventsInAnyAAState;

	UPROPERTY(Config)
	bool bBlockAthenaFeatsCompletionInCompetitive;

	UPROPERTY(Config)
	TArray<FString> TransientQuestsToAutoComplete;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> PostBRWarmupQuests;

};

