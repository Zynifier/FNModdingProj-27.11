// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingProp_CreaturePlacer.h"

USkeletalMeshComponent* ABuildingProp_CreaturePlacer::GetCreatureSkeletalMeshComponent() const
{
	return nullptr;
}

void ABuildingProp_CreaturePlacer::MinigameStateChanged_Implementation(AFortMinigame* Minigame, EFortMinigameState NewMinigameState)
{
}

void ABuildingProp_CreaturePlacer::OnTurnOffReceived(AController* TriggerInstigator)
{
}

void ABuildingProp_CreaturePlacer::OnTurnOnReceived(AController* TriggerInstigator)
{
}

void ABuildingProp_CreaturePlacer::UpdateCreatureVisuals()
{
}
