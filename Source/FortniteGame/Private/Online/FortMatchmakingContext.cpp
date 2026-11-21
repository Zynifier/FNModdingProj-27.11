// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMatchmakingContext.h"

void UFortMatchmakingContext::CancelMatchmaking()
{
}

void UFortMatchmakingContext::CheckRejoinStatus()
{
}

void UFortMatchmakingContext::DisconnectFromLobby()
{
}

void UFortMatchmakingContext::DisplayAntiTaxiError()
{
}

void UFortMatchmakingContext::EnterOutpost()
{
}

void UFortMatchmakingContext::ForceTeamFill(const bool bForcedTeamFillValue) const
{
}

EFortSTWMatchmakingPrivacyType UFortMatchmakingContext::GetCurrentStwMatchmakingPrivacy() const
{
	return EFortSTWMatchmakingPrivacyType();
}

FString UFortMatchmakingContext::GetCustomMatchmakingKey() const
{
	return FString();
}

ECommonInputType UFortMatchmakingContext::GetInputBasedMatchmakingPool(bool& bIsDefaultPool, bool& bEntirePartyUsingTargetPoolInput) const
{
	return ECommonInputType();
}

FText UFortMatchmakingContext::GetLegacyNonInputBasedPlayAgainstText()
{
	return FText();
}

AFortLobbyBeaconClient* UFortMatchmakingContext::GetLobbyBeaconClient() const
{
	return nullptr;
}

float UFortMatchmakingContext::GetLobbyWaitForPlayersTimeRemaining()
{
	return float();
}

FText UFortMatchmakingContext::GetMatchmakingFillText(bool bDesiredFill) const
{
	return FText();
}

bool UFortMatchmakingContext::HasBroadcasterToken() const
{
	return false;
}

bool UFortMatchmakingContext::IsConnectedToGame() const
{
	return false;
}

bool UFortMatchmakingContext::IsCustomMatchmakingKeyEnabled() const
{
	return false;
}

bool UFortMatchmakingContext::IsInLobby() const
{
	return false;
}

bool UFortMatchmakingContext::IsInputBasedMatchmakingEnabled() const
{
	return false;
}

bool UFortMatchmakingContext::IsJoinableGameAvailable()
{
	return false;
}

bool UFortMatchmakingContext::IsMatchmakingFlowActive() const
{
	return false;
}

bool UFortMatchmakingContext::IsMatchmakingLocal() const
{
	return false;
}

bool UFortMatchmakingContext::IsMatchmakingRegionEnabled() const
{
	return false;
}

bool UFortMatchmakingContext::IsOutpostPermitted() const
{
	return false;
}

bool UFortMatchmakingContext::IsWaitingOnUpdateManager()
{
	return false;
}

bool UFortMatchmakingContext::IsWorldRecordLoaded()
{
	return false;
}

bool UFortMatchmakingContext::JoinFromLobby()
{
	return false;
}

bool UFortMatchmakingContext::NeedToCheckRejoinStatus()
{
	return false;
}

void UFortMatchmakingContext::ReadyUp()
{
}

void UFortMatchmakingContext::RequestUtilityToCancelMatchmaking()
{
}

void UFortMatchmakingContext::RequestUtilityToMatchmake()
{
}

void UFortMatchmakingContext::RequestUtilityToToggleMatchmaking()
{
}

void UFortMatchmakingContext::SetCustomMatchmakingKey(const FString& Key)
{
}

void UFortMatchmakingContext::SetMatchmakingFlowActive(bool InFlow)
{
}

void UFortMatchmakingContext::StartCriticalMission(float MinMissionDifficulty, float MaxMissionDifficulty)
{
}

void UFortMatchmakingContext::StartMatchmaking()
{
}

bool UFortMatchmakingContext::StartOnboardingMission()
{
	return false;
}

void UFortMatchmakingContext::StartQuickPlay(float MinMissionDifficulty, float MaxMissionDifficulty)
{
}

void UFortMatchmakingContext::StartStormShieldExpansionAssist(float MinMissionDifficulty, float MaxMissionDifficulty)
{
}

void UFortMatchmakingContext::StartWargameSimulationAssist(float MinMissionDifficulty, float MaxMissionDifficulty)
{
}
