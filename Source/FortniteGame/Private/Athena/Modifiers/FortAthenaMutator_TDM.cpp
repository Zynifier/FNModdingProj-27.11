// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_TDM.h"

TArray<FTDMPlayerStandingInfo> AFortAthenaMutator_TDM::GetPlayerStandings() const
{
	return TArray<FTDMPlayerStandingInfo>();
}

void AFortAthenaMutator_TDM::OnMutatorGenericIntegerUpdated(int32 GenericIntegerIndex, int32 NewIntegerValue)
{
}

void AFortAthenaMutator_TDM::OnPlayerKillScoreChanged(AFortPlayerStateAthena* PlayerState, const int32 NewKillScore)
{
}

void AFortAthenaMutator_TDM::OnPlayerStateAdded(APlayerState* AddedPlayerState)
{
}

void AFortAthenaMutator_TDM::OnPlayerStateRemoved(APlayerState* RemovedPlayerState)
{
}
