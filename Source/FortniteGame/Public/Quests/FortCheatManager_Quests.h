// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "Quests/FortQuestObjectiveStatXPTable.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "Quests/QuestTypes.h"
#include "FortCheatManager_Quests.generated.h"

enum class EGameplayDebugState : uint8;
enum class EQuestParticipationScope : uint8;

UCLASS()
class UFortCheatManager_Quests : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void CheckObjectiveStatUsage();

	UFUNCTION(Exec)
	void CheckQuestProcessorLoads() const;

	UFUNCTION(Exec)
	void CompleteAccoladesByDisplayName(const FString DisplayNameSearchString);

	UFUNCTION(Exec)
	void CompleteAllQuestsByName(FString& QuestPartialName);

	UFUNCTION(Exec)
	void CompleteAllSquadMemberQuestsByName(FString& QuestPartialName);

	UFUNCTION(Exec)
	void CompleteQuestAndForceVictory(FString& QuestName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CompleteQuestObjective(const FString ObjectiveName);

	UFUNCTION(Exec)
	void DebugDistanceTraveled(const EGameplayDebugState DebugState = EGameplayDebugState::Unset, const float InDelay = 0.200000f, const bool bShowAll = false) const;

	UFUNCTION(Exec)
	void DebugGameplayEvents(const EGameplayDebugState DebugState = EGameplayDebugState::Unset) const;

	UFUNCTION(Exec)
	void DisableQuestStateLogging();

	UFUNCTION(Exec)
	void EnableQuestStateLogging();

	UFUNCTION(Exec)
	void ForceCompleteAccolades(float TimerDelay = 3.000000f, bool bSkipAcknowledgements = false);

	UFUNCTION(Exec)
	void GiveAthenaXp(const float XpAmount);

	UFUNCTION(Exec)
	void GiveAthenaXpAtLocation(const float XpAmount, const FString DesiredPriority);

	UFUNCTION(Exec)
	void GrantAccolade(const FString& AccoladeName, const int32 AccoladeIndex);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GrantAndPinQuest(const FString QuestName, const EQuestParticipationScope QuestParticipationScope = EQuestParticipationScope::None) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GrantQuest(const FString QuestName, const EQuestParticipationScope QuestParticipationScope = EQuestParticipationScope::None) const;

	UFUNCTION(Exec)
	void ListActiveQuestContextTags();

	UFUNCTION(Exec)
	void ListChallenges(const FString& Filter) const;

	UFUNCTION(Exec)
	void LogActiveTransientQuests();

	UFUNCTION(Exec)
	void LogCurrentQuests();

	UFUNCTION(Exec)
	void LogPinnedQuest();

	UFUNCTION(Exec)
	void LogQuestInfo(const FString& QuestName);

	UFUNCTION(Exec)
	void LogQuestManagerState(const EQuestParticipationScope ManagerScope = EQuestParticipationScope::Personal);

	UFUNCTION(Exec)
	void LogRebootData();

	UFUNCTION(Exec)
	void LogSquadSharedQuestData() const;

	UFUNCTION(Exec)
	void LogWorldReactions();

	UFUNCTION(Exec)
	void LogWorldStats();

	UFUNCTION(Exec, BlueprintCosmetic)
	void PinQuest(const FString& QuestName);

	UFUNCTION(Exec)
	void ProgressAllQuestsByName(FString& QuestPartialName, int32 Count = 1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ProgressQuestObjective(const FString ObjectiveName, const int32 Count);

	UFUNCTION(Exec)
	void QueryRebootData();

	UFUNCTION(Exec)
	void SendQuestEvent(FName Type, FString& TargetTag, FString& SourceTag, FString& ContextTag, int32 Count = 1);

	UFUNCTION(Exec)
	void SetWorldStatCount(const FString& WorldStatName, const uint32 NewCount);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToBountyTarget();

	UFUNCTION(Exec)
	void TriggerWorldReactions(const FString& RowName);

	UFUNCTION(Exec, BlueprintCosmetic)
	void UnpinQuest();

private:
	UFUNCTION()
	void OnXpEvent(const FXPEventInfo& XpEvent);

};

