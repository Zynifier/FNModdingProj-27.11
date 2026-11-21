// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortQuestManager.h"

bool UFortQuestManager::CanProgressQuestInCurrentZone(const UFortQuestItemDefinition* QuestItemDefinition) const
{
	return false;
}

void UFortQuestManager::ForceTriggerQuestsUpdated()
{
}

void UFortQuestManager::GetCompletedQuests(TArray<UFortQuestItem*>& OutCompletedQuests)
{
}

void UFortQuestManager::GetCurrentQuests(TArray<UFortQuestItem*>& OutCurrentQuests) const
{
}

int32 UFortQuestManager::GetNumCompletedObjectives(const UFortQuestItemDefinition* Definition)
{
	return int32();
}

int32 UFortQuestManager::GetObjectiveCompletionCount(const UFortQuestItemDefinition* Definition, FName BackendName) const
{
	return int32();
}

AFortPlayerController* UFortQuestManager::GetPlayerControllerBP() const
{
	return nullptr;
}

UFortQuestManagerComponent* UFortQuestManager::GetQuestManagerComponent(TSubclassOf<UFortQuestManagerComponent> QuestManagerComponentClass) const
{
	return nullptr;
}

UFortQuestItem* UFortQuestManager::GetQuestWithDefinition(const UFortQuestItemDefinition* Definition) const
{
	return nullptr;
}

void UFortQuestManager::GetSourceAndContextTags(FGameplayTagContainer& OutSourceTags, FGameplayTagContainer& OutContextTags) const
{
}

bool UFortQuestManager::HasCompletedObjective(const UFortQuestItemDefinition* Definition, FDataTableRowHandle ObjectiveStatHandle) const
{
	return false;
}

bool UFortQuestManager::HasCompletedObjectiveWithName(const UFortQuestItemDefinition* Definition, FName BackendName) const
{
	return false;
}

bool UFortQuestManager::HasCompletedQuest(const UFortQuestItemDefinition* Definition) const
{
	return false;
}

void UFortQuestManager::InitializeQuestAbilities(APawn* PlayerPawn)
{
}

bool UFortQuestManager::IsObjectiveInProgress(const UFortQuestItemDefinition* Definition, FDataTableRowHandle ObjectiveStatHandle) const
{
	return false;
}

bool UFortQuestManager::IsObjectiveWithNameInProgress(const UFortQuestItemDefinition* Definition, FName BackendName) const
{
	return false;
}

bool UFortQuestManager::IsQuestInProgress(const UFortQuestItemDefinition* Definition) const
{
	return false;
}

bool UFortQuestManager::IsQuestObjectiveActive(FName ObjectiveName) const
{
	return false;
}

void UFortQuestManager::SendComplexCustomStatEvent(UObject* TargetObject, FGameplayTagContainer AdditionalSourceTags, FGameplayTagContainer TargetTags, int32 Count)
{
}

void UFortQuestManager::SendCustomStatEvent(FDataTableRowHandle ObjectiveStat, int32 Count)
{
}

void UFortQuestManager::SendCustomStatEventDirect(FName ObjectiveBackendName, UFortQuestItem* QuestItem, int32 Count)
{
}

void UFortQuestManager::SendCustomStatEventWithTags(EFortQuestObjectiveStatEvent Type, FGameplayTagContainer AdditionalSourceTags, FGameplayTagContainer TargetTags, int32 Count)
{
}
