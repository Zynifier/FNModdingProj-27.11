// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMatchmakingWidget.h"

FGameSelectionButtonInfo UFortAthenaMatchmakingWidgetLegacy::GetButtonModeSetTextFromIslandExtension() const
{
	return FGameSelectionButtonInfo();
}

FText UFortAthenaMatchmakingWidgetLegacy::GetButtonPrivateMatchText_Implementation() const
{
	return FText();
}

FText UFortAthenaMatchmakingWidgetLegacy::GetButtonPublicMatchText_Implementation() const
{
	return FText();
}

FText UFortAthenaMatchmakingWidgetLegacy::GetCreativeModeSelectText() const
{
	return FText();
}

FText UFortAthenaMatchmakingWidgetLegacy::GetFillStatusText() const
{
	return FText();
}

FText UFortAthenaMatchmakingWidgetLegacy::GetPrivateMatchText() const
{
	return FText();
}

FText UFortAthenaMatchmakingWidgetLegacy::GetSinglePlayerMatchText() const
{
	return FText();
}

void UFortAthenaMatchmakingWidgetLegacy::HandleMatchMakingModeCalled(const FString& IslandMnemonic, const FName InPlaylistName)
{
}

void UFortAthenaMatchmakingWidgetLegacy::HandlePrivateMatchClicked()
{
}

void UFortAthenaMatchmakingWidgetLegacy::HandleSquadFillClicked()
{
}

bool UFortAthenaMatchmakingWidgetLegacy::IsAnyCreativeModeSelectActivity() const
{
	return false;
}

bool UFortAthenaMatchmakingWidgetLegacy::IsPrivateMatchEnabled() const
{
	return false;
}

bool UFortAthenaMatchmakingWidgetLegacy::IsSinglePlayerActivity() const
{
	return false;
}

bool UFortAthenaMatchmakingWidgetLegacy::IsSquadFillEnabled() const
{
	return false;
}

void UFortAthenaMatchmakingWidgetLegacy::OnCancelClicked()
{
}

void UFortAthenaMatchmakingWidgetLegacy::OnMatchmakingModeButtonClicked()
{
}

void UFortAthenaMatchmakingWidgetLegacy::OnPlayClicked()
{
}

void UFortAthenaMatchmakingWidgetLegacy::OnStartMatchClicked()
{
}

void UFortAthenaMatchmakingWidgetLegacy::RequestPlay()
{
}

void UFortAthenaMatchmakingWidgetLegacy::ShowSelectedActivityDetailsPage()
{
}
