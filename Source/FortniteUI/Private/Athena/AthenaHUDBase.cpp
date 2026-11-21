// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaHUDBase.h"

void UAthenaHUDBase::BindVolumeEvents()
{
}

bool UAthenaHUDBase::GetZoneCompleted() const
{
	return false;
}

void UAthenaHUDBase::HandleCursorModeChanging(bool bCursorModeEnabled, FName ActionName)
{
}

void UAthenaHUDBase::HandleMinigameHideHUD(bool bLoading)
{
}

void UAthenaHUDBase::HandleMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode)
{
}

void UAthenaHUDBase::HandleNewPanelFromMutator(TSubclassOf<UUserWidget> PanelClass)
{
}

void UAthenaHUDBase::HandleOnMutatorAdded(AFortGameplayMutator* NewMutator)
{
}

void UAthenaHUDBase::HandleOnMutatorRemoved(AFortGameplayMutator* NewMutator)
{
}

void UAthenaHUDBase::HandlePickerOpenRequest(EFortPickerMode Mode, int32 InitialOption, bool bIgnoreFirstAccept)
{
}

void UAthenaHUDBase::HandleRecoverFromPostGame()
{
}

void UAthenaHUDBase::HandleUpdateMinigameUIExtensions(AFortMinigame* Minigame)
{
}

void UAthenaHUDBase::SetZoneCompleted(bool bValue)
{
}
