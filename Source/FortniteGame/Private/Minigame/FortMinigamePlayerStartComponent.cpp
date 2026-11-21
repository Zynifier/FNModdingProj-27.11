// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigamePlayerStartComponent.h"

bool UFortMinigamePlayerStartComponent::GetPlayerCheckpointLastUsedTime(APlayerState* Player, FDateTime& OutTime) const
{
	return false;
}

bool UFortMinigamePlayerStartComponent::HasAnyCheckpointValue() const
{
	return false;
}

void UFortMinigamePlayerStartComponent::StorePlayerCheckpoint(APlayerState* Player)
{
}
