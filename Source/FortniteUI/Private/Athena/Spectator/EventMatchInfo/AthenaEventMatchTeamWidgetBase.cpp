// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Spectator/EventMatchInfo/AthenaEventMatchTeamWidgetBase.h"

int32 UAthenaEventMatchTeamWidgetBase::GetTeamKills() const
{
	return int32();
}

bool UAthenaEventMatchTeamWidgetBase::IsTeamDead() const
{
	return false;
}

void UAthenaEventMatchTeamWidgetBase::OnPlayerDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDead)
{
}

void UAthenaEventMatchTeamWidgetBase::OnPlayerDisconnectedChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDisconnected)
{
}
