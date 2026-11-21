// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameVolumeComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortMinigameVolumeComponent::HasReplicatedSettingsMachine() const
{
	return false;
}

void UFortMinigameVolumeComponent::OnClientEnterVolume(APlayerState* InPlayerState, AFortVolume* InVolume)
{
}

void UFortMinigameVolumeComponent::OnClientExitVolume(APlayerState* InPlayerState, AFortVolume* InVolume)
{
}

void UFortMinigameVolumeComponent::OnRep_CurrentMinigame()
{
}

void UFortMinigameVolumeComponent::OnRep_PublishedIslandCodeDisplay()
{
}

void UFortMinigameVolumeComponent::SetMinigameSettingsMachine(AFortMinigameSettingsBuilding* NewMinigameSettingsMachine)
{
}

void UFortMinigameVolumeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameVolumeComponent, MinigameClass);
	DOREPLIFETIME(UFortMinigameVolumeComponent, CurrentMinigame);
	DOREPLIFETIME(UFortMinigameVolumeComponent, PublishedIslandCodeDisplay);
}
