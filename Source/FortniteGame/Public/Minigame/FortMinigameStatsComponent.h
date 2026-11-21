// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Minigame/FortMinigameStats.h"
#include "Minigame/FortMinigameTimeAliveStartPoint.h"
#include "Minigame/FortMinigameTypes.h"
#include "FortMinigameStatsComponent.generated.h"

class AController;
class AFortPlayerController;
class AFortPlayerState;
class UFortMinigamePlayerDefinedStatFilter;
class UFortMinigameStatFilter;
class UObject;
enum class EFortMinigameTimeAliveStartPoint : uint8;
enum class EFortMinigameTimeAliveTeamTrackingMethod : uint8;
enum class EFortQuestObjectiveStatEvent : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScoreboardColumnOrderUpdatedDelegate);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AccumulateStatForGroup(UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AccumulateStatForPlayer(const AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AccumulateStatForPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AccumulateStatForPlayerId(const FUniqueNetIdRepl& InPlayerID, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AddStatToGroup(UFortMinigameStatFilter* InFilter, int32 InValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AddStatToPlayer(AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, int32 InValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void AddStatToPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, int32 InValue);

	UFUNCTION(BlueprintPure)
	UFortMinigameStatFilter* GetLoadedStatFromClass(const TSubclassOf<UFortMinigameStatFilter> InFilterClass) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	void GetScoreboardColumnOrder(TArray<int32>& OutScoreboardColumnOrder) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	int32 GetStatForGroup(UFortMinigameStatFilter* InFilter, bool bGameTotal = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	int32 GetStatForPlayer(const AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, bool bGameTotal = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	int32 GetStatForPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, bool bGameTotal = false, bool bIncludeInactivePlayers = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	int32 GetStatForPlayerId(const FUniqueNetIdRepl& PlayerId, UFortMinigameStatFilter* InFilter, bool bGameTotal = false) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	UFortMinigameStatFilter* GetStatFromName(const FString& StatNameToFind);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	const FGameplayTagContainer& GetTargetTagsFromNamedStat(const FString& StatNameToFind);

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	EFortMinigameTimeAliveStartPoint GetTimeAliveStartPoint() const;

	UFUNCTION(BlueprintPure)
	UFortMinigameStatFilter* GetTrackedStat(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32& OutIndex);

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	void GetTrackedStatsForScoreboardColumns(TArray<UFortMinigameStatFilter*>& OutScoreboardColumnSortedTrackedStats, bool bOnlyPersistentStats = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	bool IsStatPersistent(const TSubclassOf<UFortMinigameStatFilter> InFilterClass) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void NotifyStatEvent(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count);

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	void SetPersistentStatList(UPARAM(ref) TArray<UFortMinigameStatFilter*>& InPersistentStatList);

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	void SetScoreboardColumnOrder(UPARAM(ref) TArray<int32>& InScoreboardColumnOrder);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void SetStatForGroup(UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void SetStatForPlayer(const AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void SetStatForPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void SetStatForPlayerId(const FUniqueNetIdRepl& InPlayerID, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal = false);

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	void SetTimeAliveStartPoint(const EFortMinigameTimeAliveStartPoint& InTimeAliveStartPoint);

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	void SetTimeAliveTeamTrackingMethod(UPARAM(ref) EFortMinigameTimeAliveTeamTrackingMethod& InTimeAliveTeamTrackingMethod);

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	void SetTrackedStats(UPARAM(ref) TArray<TSubclassOf<UFortMinigameStatFilter>>& InTrackedStats);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Minigame | Stats")
	TArray<TSubclassOf<UFortMinigameStatFilter>> AvailableStats;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Minigame | Stats")
	TArray<TObjectPtr<UFortMinigameStatFilter>> LoadedStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame | Stats")
	TArray<TSubclassOf<UFortMinigameStatFilter>> TrackedStats;

	UPROPERTY(EditAnywhere, Category="Minigame | Stats")
	TArray<TSubclassOf<UFortMinigameStatFilter>> ScoreboardStats;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Minigame | Stats")
	TArray<TObjectPtr<UFortMinigameStatFilter>> TrackedStatObjects;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Minigame | Stats")
	TArray<TObjectPtr<UFortMinigameStatFilter>> ScoreboardStatObjects;

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="Minigame | Stats")
	TArray<TObjectPtr<UFortMinigameStatFilter>> PersistentStatList;

	UPROPERTY(EditAnywhere, Replicated, Category="Minigame | Stats")
	TArray<int32> ScoreboardColumnOrder;

	UPROPERTY(EditAnywhere, Replicated, Category="Minigame | Stats")
	EFortMinigameTimeAliveTeamTrackingMethod TimeAliveTeamTrackingMethod;

	UPROPERTY(VisibleInstanceOnly, Transient, ReplicatedUsing=OnRep_StatsChanged, Category="Minigame | Stats")
	FFortMinigameStatCollection RoundStats;

	UPROPERTY(VisibleInstanceOnly, Transient, ReplicatedUsing=OnRep_StatsChanged, Category="Minigame | Stats")
	FFortMinigameStatCollection GameStats;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Stats")
	FScoreboardColumnOrderUpdatedDelegate OnScoreboardColumnOrderUpdated;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Minigame | Stats")
	TArray<FString> StatNamesInUse;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Minigame | Stats")
	TArray<FGameplayTag> PlayerDefinedStatGameplayTagsInUse;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Minigame | Stats")
	FPlayerDefinedStatFilterArray PlayerDefinedStatEntries;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMinigameStatsComponent")
	TArray<TObjectPtr<UFortMinigamePlayerDefinedStatFilter>> PlayerDefinedStatInstances;

protected:
	UFUNCTION()
	void OnRep_StatsChanged();

	UPROPERTY(EditDefaultsOnly, Category="Minigame | Stats")
	EFortMinigameTimeAliveStartPoint TimeAliveStartPoint;

private:
	UFUNCTION()
	void BroadcastStatsChangedDelegate();

};

