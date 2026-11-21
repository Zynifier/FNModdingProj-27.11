// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameObjectiveTrackerComponent.h"
#include "Net/UnrealNetwork.h"

void UFortMinigameObjectiveTrackerComponent::ClearTrackedObjectives()
{
}

bool UFortMinigameObjectiveTrackerComponent::GetTrackedObjective(int32 TrackedIndex, FTrackedObjective& TrackedObjective) const
{
	return false;
}

bool UFortMinigameObjectiveTrackerComponent::GetTrackedObjectivesByQuery(TArray<FTrackedObjective>& TrackedObjectives, uint8 TeamIndex, ETrackedObjectiveQuery QueryType) const
{
	return false;
}

void UFortMinigameObjectiveTrackerComponent::HandleMinigameEnded()
{
}

void UFortMinigameObjectiveTrackerComponent::SetIsInteractionAllowed(UFortMinigameObjectiveComponent* Objective)
{
}

void UFortMinigameObjectiveTrackerComponent::SetTrackedState(UFortMinigameObjectiveComponent* Objective)
{
}

int32 UFortMinigameObjectiveTrackerComponent::StartTrackingObjective(UFortMinigameObjectiveComponent* Objective, int32 IndicatorPresetIndex)
{
	return int32();
}

void UFortMinigameObjectiveTrackerComponent::StopTrackingObjective(UFortMinigameObjectiveComponent* Objective, bool bPurgeHistory)
{
}

void UFortMinigameObjectiveTrackerComponent::UpdateTrackedProgress(UFortMinigameObjectiveComponent* Objective)
{
}

void UFortMinigameObjectiveTrackerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameObjectiveTrackerComponent, ObjectiveArray);
}
