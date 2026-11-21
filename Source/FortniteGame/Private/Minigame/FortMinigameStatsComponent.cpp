// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameStatsComponent.h"
#include "Net/UnrealNetwork.h"

void UFortMinigameStatsComponent::AccumulateStatForGroup(UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::AccumulateStatForPlayer(const AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::AccumulateStatForPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::AccumulateStatForPlayerId(const FUniqueNetIdRepl& InPlayerID, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::AddStatToGroup(UFortMinigameStatFilter* InFilter, int32 InValue)
{
}

void UFortMinigameStatsComponent::AddStatToPlayer(AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, int32 InValue)
{
}

void UFortMinigameStatsComponent::AddStatToPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, int32 InValue)
{
}

void UFortMinigameStatsComponent::BroadcastStatsChangedDelegate()
{
}

UFortMinigameStatFilter* UFortMinigameStatsComponent::GetLoadedStatFromClass(const TSubclassOf<UFortMinigameStatFilter> InFilterClass) const
{
	return nullptr;
}

void UFortMinigameStatsComponent::GetScoreboardColumnOrder(TArray<int32>& OutScoreboardColumnOrder) const
{
}

int32 UFortMinigameStatsComponent::GetStatForGroup(UFortMinigameStatFilter* InFilter, bool bGameTotal) const
{
	return int32();
}

int32 UFortMinigameStatsComponent::GetStatForPlayer(const AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, bool bGameTotal) const
{
	return int32();
}

int32 UFortMinigameStatsComponent::GetStatForPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, bool bGameTotal, bool bIncludeInactivePlayers) const
{
	return int32();
}

int32 UFortMinigameStatsComponent::GetStatForPlayerId(const FUniqueNetIdRepl& PlayerId, UFortMinigameStatFilter* InFilter, bool bGameTotal) const
{
	return int32();
}

UFortMinigameStatFilter* UFortMinigameStatsComponent::GetStatFromName(const FString& StatNameToFind)
{
	return nullptr;
}

const FGameplayTagContainer& UFortMinigameStatsComponent::GetTargetTagsFromNamedStat(const FString& StatNameToFind)
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

EFortMinigameTimeAliveStartPoint UFortMinigameStatsComponent::GetTimeAliveStartPoint() const
{
	return EFortMinigameTimeAliveStartPoint();
}

UFortMinigameStatFilter* UFortMinigameStatsComponent::GetTrackedStat(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32& OutIndex)
{
	return nullptr;
}

void UFortMinigameStatsComponent::GetTrackedStatsForScoreboardColumns(TArray<UFortMinigameStatFilter*>& OutScoreboardColumnSortedTrackedStats, bool bOnlyPersistentStats) const
{
}

bool UFortMinigameStatsComponent::IsStatPersistent(const TSubclassOf<UFortMinigameStatFilter> InFilterClass) const
{
	return false;
}

void UFortMinigameStatsComponent::NotifyStatEvent(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count)
{
}

void UFortMinigameStatsComponent::OnRep_StatsChanged()
{
}

void UFortMinigameStatsComponent::SetPersistentStatList(TArray<UFortMinigameStatFilter*>& InPersistentStatList)
{
}

void UFortMinigameStatsComponent::SetScoreboardColumnOrder(TArray<int32>& InScoreboardColumnOrder)
{
}

void UFortMinigameStatsComponent::SetStatForGroup(UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::SetStatForPlayer(const AFortPlayerState* InPlayer, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::SetStatForPlayerBucket(int32 BucketIndex, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::SetStatForPlayerId(const FUniqueNetIdRepl& InPlayerID, UFortMinigameStatFilter* InFilter, int32 InValue, bool bGameTotal)
{
}

void UFortMinigameStatsComponent::SetTimeAliveStartPoint(const EFortMinigameTimeAliveStartPoint& InTimeAliveStartPoint)
{
}

void UFortMinigameStatsComponent::SetTimeAliveTeamTrackingMethod(EFortMinigameTimeAliveTeamTrackingMethod& InTimeAliveTeamTrackingMethod)
{
}

void UFortMinigameStatsComponent::SetTrackedStats(TArray<TSubclassOf<UFortMinigameStatFilter>>& InTrackedStats)
{
}

void UFortMinigameStatsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameStatsComponent, AvailableStats);
	DOREPLIFETIME(UFortMinigameStatsComponent, LoadedStats);
	DOREPLIFETIME(UFortMinigameStatsComponent, TrackedStats);
	DOREPLIFETIME(UFortMinigameStatsComponent, TrackedStatObjects);
	DOREPLIFETIME(UFortMinigameStatsComponent, ScoreboardStatObjects);
	DOREPLIFETIME(UFortMinigameStatsComponent, PersistentStatList);
	DOREPLIFETIME(UFortMinigameStatsComponent, ScoreboardColumnOrder);
	DOREPLIFETIME(UFortMinigameStatsComponent, TimeAliveTeamTrackingMethod);
	DOREPLIFETIME(UFortMinigameStatsComponent, RoundStats);
	DOREPLIFETIME(UFortMinigameStatsComponent, GameStats);
	DOREPLIFETIME(UFortMinigameStatsComponent, StatNamesInUse);
	DOREPLIFETIME(UFortMinigameStatsComponent, PlayerDefinedStatGameplayTagsInUse);
	DOREPLIFETIME(UFortMinigameStatsComponent, PlayerDefinedStatEntries);
}
