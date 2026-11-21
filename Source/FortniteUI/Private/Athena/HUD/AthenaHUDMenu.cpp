// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/AthenaHUDMenu.h"

void UAthenaHUDMenu::ClearGameOverScreen()
{
}

UAthenaGameOverDisplay* UAthenaHUDMenu::CreateOrShowGameOverScreen()
{
	return nullptr;
}

void UAthenaHUDMenu::HandleLocalPlayerDied(const FFortPlayerDeathReport& DeathReport)
{
}

void UAthenaHUDMenu::HandleLocalPlayerLost(EEndOfMatchReason LostReason)
{
}

void UAthenaHUDMenu::HandleLocalPlayerOrTeamWon()
{
}

void UAthenaHUDMenu::HandleLocalPlayerRevived()
{
}

void UAthenaHUDMenu::HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState)
{
}

void UAthenaHUDMenu::HandleOverrideInventoryPanel(UUserWidget* Widget)
{
}

void UAthenaHUDMenu::HandlePreviewScreenshotCameraActivated(bool bActivated)
{
}

void UAthenaHUDMenu::HandleRecoverFromPostGame()
{
}

void UAthenaHUDMenu::HandleStartPostGame()
{
}

void UAthenaHUDMenu::NativeHandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget)
{
}

void UAthenaHUDMenu::PostBindCheckConditions()
{
}

void UAthenaHUDMenu::RecoverFromPostGame()
{
}

void UAthenaHUDMenu::SetInventoryPanelOverride(UUserWidget* InInventoryPanelOverride)
{
}

void UAthenaHUDMenu::StartPostGame()
{
}
