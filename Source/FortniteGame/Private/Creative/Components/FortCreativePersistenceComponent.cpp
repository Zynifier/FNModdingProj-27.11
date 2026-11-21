// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortCreativePersistenceComponent.h"

void UFortCreativePersistenceComponent::ClearAllPlayersSpecificData(AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::ClearPlayerRelatedData(APlayerState* PlayerState, AFortMinigame* Minigame) const
{
}

void UFortCreativePersistenceComponent::ClearPlayerSpecificData(APlayerState* PlayerState, AFortMinigame* Minigame) const
{
}

void UFortCreativePersistenceComponent::DeinitializeAutoSave()
{
}

void UFortCreativePersistenceComponent::DisableAutoSave(AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::EnableAutoSave(AFortMinigame* Minigame)
{
}

float UFortCreativePersistenceComponent::GetAutoSaveInterval()
{
	return float();
}

TArray<UFortMinigameStatFilter*> UFortCreativePersistenceComponent::GetPersistentStatFilterList() const
{
	return TArray<UFortMinigameStatFilter*>();
}

void UFortCreativePersistenceComponent::InitializeAutoSave(AFortMinigame* Minigame, bool bShouldEnableAutoSave)
{
}

void UFortCreativePersistenceComponent::LoadPlayerDataNeededAfterSpawn(AFortPlayerState* FortPlayerState, AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::LoadPlayerDataNeededBeforeSpawn(AFortPlayerState* FortPlayerState, AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::LoadPlayerRelatedData(APlayerState* PlayerState, AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::LoadPlayersDataNeededAfterSpawn(AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::LoadPlayersDataNeededBeforeSpawn(AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::OnMinigameEnded(AFortMinigame* Minigame)
{
}

void UFortCreativePersistenceComponent::OnPlayerPawnFinishedTeleported(AFortPlayerPawn* FortPlayerPawn)
{
}

void UFortCreativePersistenceComponent::RemovePendingToApplyData(AFortPlayerState* FortPlayerState, bool bShowsLog)
{
}

void UFortCreativePersistenceComponent::StoreAllMinigamePlayersData(AFortMinigame* Minigame, bool bPostGameSave)
{
}

bool UFortCreativePersistenceComponent::StorePlayerRelatedData(APlayerState* PlayerState, AFortMinigame* Minigame, bool bPostGameSave)
{
	return false;
}
