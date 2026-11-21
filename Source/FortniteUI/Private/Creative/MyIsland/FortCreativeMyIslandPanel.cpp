// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/MyIsland/FortCreativeMyIslandPanel.h"

AFortMinigameSettingsBuilding* UFortCreativeMyIslandPanel::GetMinigameSettingsMachine() const
{
	return nullptr;
}

UFortMinigameVolumeComponent* UFortCreativeMyIslandPanel::GetMinigameVolumeComponent() const
{
	return nullptr;
}

void UFortCreativeMyIslandPanel::HandleCreativePermissionsChanged()
{
}

void UFortCreativeMyIslandPanel::HandleMinigameSettingsMachineChanged(UFortMinigameVolumeComponent* MinigameVolumeComponent, AFortMinigameSettingsBuilding* MinigameSettings)
{
}

void UFortCreativeMyIslandPanel::HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState)
{
}

bool UFortCreativeMyIslandPanel::IsOwnerOfCurrentExperience() const
{
	return false;
}

bool UFortCreativeMyIslandPanel::IsUpdatingTabVisibilities() const
{
	return false;
}

void UFortCreativeMyIslandPanel::UpdateStartEndMinigameInput(const AFortMinigame* Minigame)
{
}
