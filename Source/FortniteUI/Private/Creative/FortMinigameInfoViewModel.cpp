// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortMinigameInfoViewModel.h"

AFortMinigame* UFortMinigameInfoViewModel::GetMinigame() const
{
	return nullptr;
}

AFortMinigameSettingsBuilding* UFortMinigameInfoViewModel::GetMinigameSettings() const
{
	return nullptr;
}

EFortMinigameState UFortMinigameInfoViewModel::GetMinigameState() const
{
	return EFortMinigameState();
}

UFortMinigameVolumeComponent* UFortMinigameInfoViewModel::GetMinigameVolumeComponent() const
{
	return nullptr;
}

void UFortMinigameInfoViewModel::HandleMinigameSettingsMachineChanged(UFortMinigameVolumeComponent* MinigameVolumeComponent, AFortMinigameSettingsBuilding* MinigameSettings)
{
}

void UFortMinigameInfoViewModel::HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState)
{
}

void UFortMinigameInfoViewModel::InitializeViewModel()
{
}

void UFortMinigameInfoViewModel::UnbindViewModel()
{
}
