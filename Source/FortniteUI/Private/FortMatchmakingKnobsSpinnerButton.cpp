// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMatchmakingKnobsSpinnerButton.h"

FText UFortMatchmakingKnobsSpinnerButton::GetDescription() const
{
	return FText();
}

FText UFortMatchmakingKnobsSpinnerButton::GetTitleText() const
{
	return FText();
}

bool UFortMatchmakingKnobsSpinnerButton::HasMatchingTags(FGameplayTagContainer Tags) const
{
	return false;
}

void UFortMatchmakingKnobsSpinnerButton::OnLocalPlayerExperienceStateChanged(FEventMessageTag Channel, const FSpatialGameplayActorLoadingStateUpdatedPlayerContext& StateContext)
{
}

void UFortMatchmakingKnobsSpinnerButton::OnMinigameVolumeEntered(FEventMessageTag Channel, const FPlayerEnterSpatialActorContextLegacyMinigame& PlayerEnteredVolumeContext)
{
}
