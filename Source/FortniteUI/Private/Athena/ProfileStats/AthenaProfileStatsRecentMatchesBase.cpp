// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ProfileStats/AthenaProfileStatsRecentMatchesBase.h"

TArray<UAthenaMatchStatView*> UAthenaProfileStatsRecentMatchesBase::GetRecentMatches() const
{
	return TArray<UAthenaMatchStatView*>();
}

FUniqueNetIdRepl UAthenaProfileStatsRecentMatchesBase::GetUniqueID() const
{
	return FUniqueNetIdRepl();
}

void UAthenaProfileStatsRecentMatchesBase::OnProfileLoaded(UFortMcpProfileAthenaStats* ProfileAthenaStats)
{
}

void UAthenaProfileStatsRecentMatchesBase::Setup(const FUniqueNetIdRepl& InUniqueId)
{
}
