// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ProfileStats/AthenaProfileStatsBase.h"

FText UAthenaProfileStatsBase::GetCurrentPlaylistName() const
{
	return FText();
}

UAthenaSeasonStats* UAthenaProfileStatsBase::GetCurrentStatSet() const
{
	return nullptr;
}

FUniqueNetIdRepl UAthenaProfileStatsBase::GetUniqueID() const
{
	return FUniqueNetIdRepl();
}

void UAthenaProfileStatsBase::NextPlaylist()
{
}

void UAthenaProfileStatsBase::NextStatSet()
{
}

int32 UAthenaProfileStatsBase::NumStatSets() const
{
	return int32();
}

void UAthenaProfileStatsBase::OnProfileLoaded(UFortMcpProfileAthenaStats* ProfileAthenaStats)
{
}

void UAthenaProfileStatsBase::PrevStatSet()
{
}

void UAthenaProfileStatsBase::Setup(const FUniqueNetIdRepl& InUniqueId)
{
}
