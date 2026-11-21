// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Challenges/AthenaChallengeNpcQuestCounter.h"

UAthenaChallengeNpcQuestCounter::UAthenaChallengeNpcQuestCounter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAthenaChallengeNpcQuestCounter::HandleQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool bDisplayStatusUpdate, bool bDisplayAnnouncementUpdate)
{
}

void UAthenaChallengeNpcQuestCounter::HandleTransientQuestRemoved(const UFortQuestItem* QuestItem)
{
}

void UAthenaChallengeNpcQuestCounter::HandleTransientQuestStarted(const UFortQuestItem* QuestItem, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena)
{
}

void UAthenaChallengeNpcQuestCounter::UpdateVisibility(const FGameplayTag& CurrentTabTag)
{
}
