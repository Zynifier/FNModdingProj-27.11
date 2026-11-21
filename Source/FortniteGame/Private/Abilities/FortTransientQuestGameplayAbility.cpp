// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortTransientQuestGameplayAbility.h"
#include "Net/UnrealNetwork.h"

void UFortTransientQuestGameplayAbility::CompleteQuest() const
{
}

void UFortTransientQuestGameplayAbility::FailQuest() const
{
}

void UFortTransientQuestGameplayAbility::StartUrgentQuestEvent(FUrgentQuestData UrgentQuestData)
{
}

void UFortTransientQuestGameplayAbility::StopUrgentQuestEvent(const FUrgentQuestData& UrgentQuestData)
{
}

void UFortTransientQuestGameplayAbility::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortTransientQuestGameplayAbility, QuestItemDefinition);
}
