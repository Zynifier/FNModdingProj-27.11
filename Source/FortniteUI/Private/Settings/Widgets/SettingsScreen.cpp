// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/Widgets/SettingsScreen.h"

bool USettingsScreen::AttemptToPopNavigation()
{
	return false;
}

void USettingsScreen::CloseSettings()
{
}

bool USettingsScreen::HaveSettingsBeenChanged() const
{
	return false;
}

void USettingsScreen::NavigateToSettings(TArray<FName> SettingsCollectionNames)
{
}

void USettingsScreen::ResetSettings()
{
}

void USettingsScreen::SaveSettings()
{
}
