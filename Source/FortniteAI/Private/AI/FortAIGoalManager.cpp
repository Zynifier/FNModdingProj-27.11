// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIGoalManager.h"

void AFortAIGoalManager::AddGoal(AActor* GoalActor, UFortAIAssignmentSettings* GoalSettings)
{
}

void AFortAIGoalManager::AddGoalActorToAssignment(UFortAIAssignment* Assignment, AActor* GoalActor)
{
}

void AFortAIGoalManager::AddGoalsToWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const TArray<FFortAIGoalInfo>& GoalInfos)
{
}

void AFortAIGoalManager::AddGoalToWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const FFortAIGoalInfo& GoalInfo)
{
}

UFortAIAssignment* AFortAIGoalManager::AddWorldAssignment(UFortAIAssignmentSettings* AssignmentSettings, AActor* GoalActor)
{
	return nullptr;
}

void AFortAIGoalManager::ClearGoalDiscouragementFromActor(AFortAIController* AI, const AActor* Actor)
{
}

void AFortAIGoalManager::CreateWorldAssignment(UObject* WorldContextObject, FFortAIAssignmentIdentifier WorldAssignmentIdentifier, UFortAIAssignmentSettings* AssignmentSettings, TSubclassOf<UFortAIGoalProvider> GoalProvider, FFortAIAssignmentIdentifier& AssignmentIdentifier, EAssignmentCreationResult& CreationResult)
{
}

bool AFortAIGoalManager::IsDiscouragedFromActor(AFortAIController* AI, const AActor* Actor)
{
	return false;
}

void AFortAIGoalManager::MakeGoalFromActor(FFortAIGoalInfo& Goal, const UObject* WorldContextObject, AActor* GoalActor, bool bActorAlwaysPerceived, bool bGoalActorAllowsUndermining)
{
}

void AFortAIGoalManager::MakeGoalFromLocation(FFortAIGoalInfo& Goal, const UObject* WorldContextObject, const FVector& GoalLocation)
{
}

void AFortAIGoalManager::MakeGoalsFromActors(TArray<FFortAIGoalInfo>& Goals, const UObject* WorldContextObject, const TArray<AActor*>& GoalActors, bool bActorsAlwaysPerceived, bool bGoalActorsAllowUndermining)
{
}

void AFortAIGoalManager::MakeGoalsFromLocations(TArray<FFortAIGoalInfo>& Goals, const UObject* WorldContextObject, const TArray<FVector>& GoalLocations)
{
}

void AFortAIGoalManager::MakeGoalsFromLocationsAndActor(TArray<FFortAIGoalInfo>& Goals, const UObject* WorldContextObject, const TArray<FVector>& GoalLocations, const AActor* GoalActor)
{
}

void AFortAIGoalManager::RemoveGoalFromWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const FFortAIGoalInfo& GoalInfo)
{
}

void AFortAIGoalManager::RemoveGoalsFromWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const TArray<FFortAIGoalInfo>& GoalInfos)
{
}

void AFortAIGoalManager::RemoveWorldAssignment(const UObject* WorldContextObject, FFortAIAssignmentIdentifier AssignmentIdentifier)
{
}

void AFortAIGoalManager::SetCurrentGoalDiscouragement(UObject* WorldContext, AFortAIController* AI)
{
}
