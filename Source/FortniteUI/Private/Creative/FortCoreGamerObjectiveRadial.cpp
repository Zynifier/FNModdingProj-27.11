// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCoreGamerObjectiveRadial.h"

UFortCoreGamerObjectiveRadial::UFortCoreGamerObjectiveRadial(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

AFortMinigame* UFortCoreGamerObjectiveRadial::GetMinigame() const
{
	return nullptr;
}

float UFortCoreGamerObjectiveRadial::GetNormalizedDistanceFromScreenCenter()
{
	return float();
}

UFortMinigameObjectiveTrackerComponent* UFortCoreGamerObjectiveRadial::GetObjectiveTracker() const
{
	return nullptr;
}

void UFortCoreGamerObjectiveRadial::HandleTrackedObjectiveTeamUpdated(int32 InTrackedIndex)
{
}

void UFortCoreGamerObjectiveRadial::HandleTrackedObjectiveUpdated(int32 InTrackedIndex)
{
}

bool UFortCoreGamerObjectiveRadial::IsUsingGameCamera() const
{
	return false;
}

void UFortCoreGamerObjectiveRadial::UpdateCaptureState(const ECaptureState NewCaptureState, const ECaptureState OldCaptureState, const uint8 TrackedStateOwnerTeam, const float Progress)
{
}
