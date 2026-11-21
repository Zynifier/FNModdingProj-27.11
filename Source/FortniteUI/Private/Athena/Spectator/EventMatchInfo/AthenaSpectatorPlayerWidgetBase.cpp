// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Spectator/EventMatchInfo/AthenaSpectatorPlayerWidgetBase.h"

UAthenaRemotePlayerViewData* UAthenaSpectatorPlayerWidgetBase::GetPlayerData() const
{
	return nullptr;
}

void UAthenaSpectatorPlayerWidgetBase::HandleBeingRevivedStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsBeingRevived)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleDBNOStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDBNO)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDead)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleDisconnectedChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDisconnected)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleHealthDamaged(UAthenaRemotePlayerViewData* InPlayerData, float Health, float MaxHealth)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleHealthHealed(UAthenaRemotePlayerViewData* InPlayerData, float Health, float MaxHealth)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleIsFollowedPlayerChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsFollowedPlayer)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleIsInRelevancyChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsInRelevancy)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleIsReplayRelevancyPlayerChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsReplayRelevancyPlayer)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleKillScoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 KillScore)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleMaterialCountChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 MaterialCount)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandlePlaceChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 Place)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandlePlayerNameChanged(UAthenaRemotePlayerViewData* InPlayerData, const FString& PlayerName)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandlePlayerStateChanged(UAthenaRemotePlayerViewData* InPlayerData, AFortPlayerStateAthena* PlayerState)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleShieldDamaged(UAthenaRemotePlayerViewData* InPlayerData, float Shield, float MaxShield)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleShieldHealed(UAthenaRemotePlayerViewData* InPlayerData, float Shield, float MaxShield)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleSquadIdChanged(UAthenaRemotePlayerViewData* InPlayerData, uint8 SquadId)
{
}

void UAthenaSpectatorPlayerWidgetBase::HandleTeamColorChanged(UAthenaRemotePlayerViewData* InPlayerData, FLinearColor TeamColor)
{
}

void UAthenaSpectatorPlayerWidgetBase::SetPlayerData(UAthenaRemotePlayerViewData* InPlayerData, bool bForceUpdate)
{
}
