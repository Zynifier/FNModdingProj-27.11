// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaLeaderboardScreenBase.h"

bool UAthenaLeaderboardScreenBase::CanShowFriendsOnlyLeaderboard() const
{
	return false;
}

void UAthenaLeaderboardScreenBase::OnActiveLeaderboardTabChanged(int32 ActiveWidgetIndex)
{
}

void UAthenaLeaderboardScreenBase::OnFriendsFilterChanged(int32 FriendsFilterIndex)
{
}

void UAthenaLeaderboardScreenBase::OnMatchTypeChanged(int32 MatchTypeIndex)
{
}

void UAthenaLeaderboardScreenBase::OnPlaylistChanged(const FName NewPlaylistName, const ECommonInputType NewInputType)
{
}
