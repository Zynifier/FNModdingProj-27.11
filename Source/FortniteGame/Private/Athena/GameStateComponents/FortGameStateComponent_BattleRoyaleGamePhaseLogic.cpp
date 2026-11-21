// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Net/UnrealNetwork.h"

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::DrawDebugSafeZoneHUD(AHUD* HUD, UCanvas* Canvas)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::FinishCurrentStormCircle(float TimeToShrink)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::FireServerPerformanceEvent()
{
}

UFortGameStateComponent_BattleRoyaleGamePhaseLogic* UFortGameStateComponent_BattleRoyaleGamePhaseLogic::Get(const UObject* WorldContextObject)
{
	return nullptr;
}

EAirCraftBehavior UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetAircraftBehavior() const
{
	return EAirCraftBehavior();
}

float UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetAircraftStartTime() const
{
	return float();
}

EAthenaGamePhase UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetGamePhase() const
{
	return EAthenaGamePhase();
}

EAthenaGamePhaseStep UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetGamePhaseStep() const
{
	return EAthenaGamePhaseStep();
}

float UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetGamePhaseStepTimeRemaining() const
{
	return float();
}

int32 UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetSafeZonePhaseForUI() const
{
	return int32();
}

int32 UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetSafeZonePhaseIndex() const
{
	return int32();
}

float UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetSafeZonesStartTime() const
{
	return float();
}

float UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetWarmupCountdownEndTime() const
{
	return float();
}

float UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetWarmupCountdownStartTime() const
{
	return float();
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandleEndGamePhaseStarted(const FFortEndGamePhaseStartedEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandleGamePhaseStepChanged(const EAthenaGamePhaseStep InGamePhaseStep)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandleGracefulShutdownInitiated(const FFortGracefulShutdownInitiatedEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandleMatchmakingAssigned(const FFortMatchmakingSessionAssignedEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandleMeshServerPerfEvent(const FFortMeshServerPerfEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandlePawnPossessed(const FFortPawnPossessed& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandlePawnUnpossessed(const FFortPawnUnpossessed& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandlePlayerRemovedFromAlivePlayers(const FFortPlayerRemovedFromAlivePlayersEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandlePlayersLeftChanged(const FFortPlayersLeftChangedEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandlePlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::HandleUpdateScoringLogic(const FFortUpdateScoringLogicEvent& Event)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::InitializeSafeZoneLocations()
{
}

bool UFortGameStateComponent_BattleRoyaleGamePhaseLogic::IsInCurrentSafeZone(const FVector& TestLocation, bool bClassicSafeZoneOnly) const
{
	return false;
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::JumpToSafeZonePhase()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnAircraftEnteredDropZone(AFortAthenaAircraft* FortAthenaAircraft)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnAircraftExitedDropZone(AFortAthenaAircraft* FortAthenaAircraft)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnAircraftFlightEnded(AFortAthenaAircraft* FortAthenaAircraft)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_Aircrafts()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_bPlaylistStoppedSafeZonePhases()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_GamePhase(const EAthenaGamePhase OldGamePhase)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_PlaylistEndTime()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_SafeZoneIndicator()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_StormCapState()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnRep_WarmupCountdownEndTime()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::OnSafeZonePhaseChanged()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::SetAircraftFlightPath(float StartDegrees, float OffsetFactor)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::SetAircrafts(const TArray<AFortAthenaAircraft*>& InAircrafts)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::SetRandomAircraftFlightPath()
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::SetSafeZonesStartTime(const float InValue)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::SetStormDamagePaused(bool bPause)
{
}

void UFortGameStateComponent_BattleRoyaleGamePhaseLogic::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, SafeZoneIndicator);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, Aircrafts_GameState);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, GamePhase);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, AirCraftBehavior);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, StormCapState);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, DamageForStormCapMarking);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, bPlaylistStoppedSafeZonePhases);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, bGameModeWillSkipAircraft);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, bAircraftIsLocked);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, bIsInCountdown);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, bIsInFinalCountdown);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, WarmupCountdownStartTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, WarmupCountdownEndTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, AircraftStartTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, AircraftRealStartTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, SafeZonesStartTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, SafeZonePauseTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, PlaylistEndTime);
	DOREPLIFETIME(UFortGameStateComponent_BattleRoyaleGamePhaseLogic, TotalFinalCountdownTime);
}
