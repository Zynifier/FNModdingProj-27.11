// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bacchus/FortBacchusControlsDiagram.h"

UFortBacchusControlsDiagram::UFortBacchusControlsDiagram(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortBacchusControlsDiagram::GetIsDisplayingCombatMode() const
{
	return false;
}

void UFortBacchusControlsDiagram::HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortBacchusControlsDiagram::ToggleDisplayedControlMode(bool bShouldDisplayCombatControls)
{
}
