// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Spectator/AthenaRemoteSquadViewData.h"

bool UAthenaRemoteSquadViewData::GetIsEliminated() const
{
	return false;
}

int32 UAthenaRemoteSquadViewData::GetKillScore() const
{
	return int32();
}

const UFortMinigameTeamIdentification* UAthenaRemoteSquadViewData::GetMinigameTeamId() const
{
	return nullptr;
}

int32 UAthenaRemoteSquadViewData::GetPlace() const
{
	return int32();
}

const TArray<UAthenaRemotePlayerViewData*>& UAthenaRemoteSquadViewData::GetPlayerDatas() const
{
	static TArray<UAthenaRemotePlayerViewData*> Dummy;
	return Dummy;
}

FLinearColor UAthenaRemoteSquadViewData::GetSquadColor() const
{
	return FLinearColor();
}

int32 UAthenaRemoteSquadViewData::GetSquadId() const
{
	return int32();
}

int32 UAthenaRemoteSquadViewData::GetSquadSessionRank() const
{
	return int32();
}

void UAthenaRemoteSquadViewData::HandlePlayerDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool InEliminated)
{
}

void UAthenaRemoteSquadViewData::HandlePlayerKillscoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InKillScore)
{
}

void UAthenaRemoteSquadViewData::HandlePlayerPlaceChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InPlace)
{
}

void UAthenaRemoteSquadViewData::HandleSessionRankChanged(UAthenaRemotePlayerViewData* InPlayerData, const int32 InSessionRank)
{
}
