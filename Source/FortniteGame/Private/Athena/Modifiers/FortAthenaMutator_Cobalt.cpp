// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Cobalt.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_Cobalt::AudioFadeChangeEvent(bool bFadeOut, float FadeTime)
{
}

void AFortAthenaMutator_Cobalt::ClientCobaltRoundTimerComplete()
{
}

const int32 AFortAthenaMutator_Cobalt::GetFinalRoundIndex() const
{
	return int32();
}

void AFortAthenaMutator_Cobalt::HandlePlayerStateTeleportComplete(AFortPlayerStateAthena* FortPlayerState)
{
}

void AFortAthenaMutator_Cobalt::HandleTeleportComplete()
{
}

void AFortAthenaMutator_Cobalt::OnRep_ActiveRound()
{
}

void AFortAthenaMutator_Cobalt::OnRep_bClientPlaylistTimerStarted()
{
}

void AFortAthenaMutator_Cobalt::OnRep_bIsFinishedDisplayingRoundEndUI()
{
}

void AFortAthenaMutator_Cobalt::OnRep_CombatStormShieldArray()
{
}

void AFortAthenaMutator_Cobalt::OnRep_RoundStartWidgetSequenceRunning()
{
}

void AFortAthenaMutator_Cobalt::OnRep_TeamWinners()
{
}

void AFortAthenaMutator_Cobalt::OnRep_TeleportComplete()
{
}

void AFortAthenaMutator_Cobalt::OnRep_WidgetRoundData()
{
}

void AFortAthenaMutator_Cobalt::TeleportPlayerLoadComplete(AFortPlayerPawn* FortPlayerPawn)
{
}

void AFortAthenaMutator_Cobalt::UpdateStormEyeVisuals()
{
}

void AFortAthenaMutator_Cobalt::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, bTeleportComplete);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, bRoundStartWidgetSequenceRunning);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, CombatStormShieldArray);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, ActiveRound);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, bIsCobaltFinished);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, FirstRound);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, TeamWinners);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, TeamLosers);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, bClientPlaylistTimerStarted);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, WidgetRoundData);
	DOREPLIFETIME(AFortAthenaMutator_Cobalt, bIsFinishedDisplayingRoundEndUI);
}

void UFortCheatManager_Cobalt::AwardCobaltTeamPoints(uint8 TeamToAward, int32 PointsToAward)
{
}

void UFortCheatManager_Cobalt::EndCobaltRound()
{
}

void UFortCheatManager_Cobalt::SimulateFullCobaltMatch(bool bSimulate)
{
}
