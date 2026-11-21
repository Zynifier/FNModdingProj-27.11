// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActivityBrowser/FortActivityLobbyTile.h"

FText UFortActivityLobbyTile::GetChildActivityDisplayName() const
{
	return FText();
}

bool UFortActivityLobbyTile::IsActivityEpicCreated() const
{
	return false;
}

bool UFortActivityLobbyTile::IsModeSetActivity() const
{
	return false;
}

void UFortActivityLobbyTile::ShowModeSetSelectionModal()
{
}

void UFortActivityLobbyTile::TrySendFirstTimeNotification()
{
}
