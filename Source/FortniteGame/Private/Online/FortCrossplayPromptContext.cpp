// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortCrossplayPromptContext.h"

bool UFortCrossplayPromptContext::IsCrossplayEnabled() const
{
	return false;
}

bool UFortCrossplayPromptContext::IsPlaylistLimitedPoolMatchmakingEnabled(const UFortPlaylistAthena* PlaylistData) const
{
	return false;
}
