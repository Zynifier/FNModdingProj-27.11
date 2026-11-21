// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionBlueprintLibrary.h"

void UFortMissionBlueprintLibrary::BindPlayerToObjective(const AFortPlayerController* PlayerController, const UFortQuestItemDefinition* QuestItemDefinition, const FName QuestObjectiveBackendName, FBPOnObjectiveUpdated OnObjectiveUpdatedDelegate)
{
}

void UFortMissionBlueprintLibrary::RemovePlayerCallbackFromObjective(const AFortPlayerController* PlayerController, const UFortQuestItemDefinition* QuestItemDefinition, const FName QuestObjectiveBackendName)
{
}

bool UFortMissionBlueprintLibrary::Skydive(bool bFromBus, AFortPlayerPawn* InPawn, const UAthenaGliderItemDefinition* GliderOverride)
{
	return false;
}

void UFortMissionBlueprintLibrary::SkydiveFromLocation(bool bFromBus, AFortPlayerPawn* InPawn, const FVector FallLocation, const UAthenaGliderItemDefinition* GliderOverride)
{
}
