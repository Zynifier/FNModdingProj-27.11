// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Creative/UI/ValkyriePerformanceHUDBase.h"

void UValkyriePerformanceHUDBase::HandleGameStateInitialized(AFortGameState* GameState)
{
}

void UValkyriePerformanceHUDBase::HandleSpatialLoadingStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext)
{
}

void UValkyriePerformanceHUDBase::OnMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode)
{
}

void UValkyriePerformanceHUDBase::OnPlayerEnteredSpatialGameplayActor(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& PlayerEnterSpatialActorContext)
{
}

void UValkyriePerformanceHUDBase::OnPlayerExitedSpatialGameplayActor(FEventMessageTag Channel, const FPlayerExitSpatialActorContext& PlayerExitSpatialActorContext)
{
}

void UValkyriePerformanceHUDBase::OnPlayspaceMemoryValueUpdated(int32 MemoryValue)
{
}
