// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortSafeZoneIndicator.h"
#include "Net/UnrealNetwork.h"

bool AFortSafeZoneIndicator::ConstructMapDefaultPhase(const int32 PhaseToConstruct, FFortSafeZonePhaseInfo& OutConstructedPhase) const
{
	return false;
}

AFortSafeZoneIndicator* AFortSafeZoneIndicator::Get(const UObject* WorldContextObject)
{
	return nullptr;
}

void AFortSafeZoneIndicator::GetClockTickingAudioCurveValues(float Time, float& VolumeModValue, float& PitchModValue) const
{
}

const FFortSafeZoneDamageInfo& AFortSafeZoneIndicator::GetCurrentDamageInfo() const
{
	static FFortSafeZoneDamageInfo Dummy;
	return Dummy;
}

int32 AFortSafeZoneIndicator::GetCurrentPhaseIndex() const
{
	return int32();
}

void AFortSafeZoneIndicator::GetMovementAudioCurveValues(float Time, float& CrossfadeValue, float& PitchModValue) const
{
}

int32 AFortSafeZoneIndicator::GetPhaseCount() const
{
	return int32();
}

bool AFortSafeZoneIndicator::GetPhaseInfo(FFortSafeZonePhaseInfo& OutSafeZonePhase, const int32 InPhaseToGet) const
{
	return false;
}

FVector AFortSafeZoneIndicator::GetSafeZoneCenter() const
{
	return FVector();
}

float AFortSafeZoneIndicator::GetSafeZoneFinishShrinkTime() const
{
	return float();
}

bool AFortSafeZoneIndicator::GetSafeZonePausedForPreview()
{
	return false;
}

const TArray<FFortSafeZonePhaseInfo>& AFortSafeZoneIndicator::GetSafeZonePhases() const
{
	static TArray<FFortSafeZonePhaseInfo> Dummy;
	return Dummy;
}

float AFortSafeZoneIndicator::GetSafeZoneRadius() const
{
	return float();
}

float AFortSafeZoneIndicator::GetSafeZoneShrinkSpeed()
{
	return float();
}

float AFortSafeZoneIndicator::GetSafeZoneShrinkSpeedRelativeTo(float DistanceToTravel)
{
	return float();
}

float AFortSafeZoneIndicator::GetSafeZoneStartShrinkTime() const
{
	return float();
}

EFortSafeZoneState AFortSafeZoneIndicator::GetSafeZoneState() const
{
	return EFortSafeZoneState();
}

float AFortSafeZoneIndicator::GetTimeSinceSafeZonesStart() const
{
	return float();
}

void AFortSafeZoneIndicator::InitializeWithMapDefaultPhases()
{
}

void AFortSafeZoneIndicator::MegaStormMinTimerExpired()
{
}

void AFortSafeZoneIndicator::ModifyPhase(const int32 PhaseToModify, const FFortSafeZonePhaseInfo& NewPhase)
{
}

void AFortSafeZoneIndicator::OnBeginStartingStateEffects()
{
}

void AFortSafeZoneIndicator::OnRep_CurrentDamageInfo()
{
}

void AFortSafeZoneIndicator::OnRep_CurrentPhase()
{
}

void AFortSafeZoneIndicator::OnRep_CurrentTravelSplineComponent()
{
}

void AFortSafeZoneIndicator::OnRep_NumActiveMegaStormCircles(int32 PrevNumActiveMegaStormCircles)
{
}

void AFortSafeZoneIndicator::OnRep_PhaseCount()
{
}

void AFortSafeZoneIndicator::PauseAndPreviewPhase(const int32 PhaseToPreview)
{
}

void AFortSafeZoneIndicator::SetPhaseInfoRadius(FFortSafeZonePhaseInfo& InOutPhase, const float InRadius, const int32 PhaseIndex, const AFortAthenaMapInfo* MapInfo) const
{
}

void AFortSafeZoneIndicator::SetSafeZoneHeight(float NewWaterHeight)
{
}

void AFortSafeZoneIndicator::SetSafeZonePausedForPreview(bool bSetTo)
{
}

void AFortSafeZoneIndicator::SetSafeZonePhases(const TArray<FFortSafeZonePhaseInfo>& InPhases)
{
}

void AFortSafeZoneIndicator::SetSafeZoneRadius(const float InRadius)
{
}

void AFortSafeZoneIndicator::SetSafeZoneRadiusAndCenter(float InRadius, FVector InLocation)
{
}

void AFortSafeZoneIndicator::SetShowWarmupPreview(const bool bNewPreviewDuringWarmup)
{
}

bool AFortSafeZoneIndicator::ShouldShowWarmupPreview() const
{
	return false;
}

void AFortSafeZoneIndicator::StartPhase(const int32 InPhaseIndex)
{
}

void AFortSafeZoneIndicator::StopPreviewingPhase()
{
}

void AFortSafeZoneIndicator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSafeZoneIndicator, PreviousRadius);
	DOREPLIFETIME(AFortSafeZoneIndicator, NextRadius);
	DOREPLIFETIME(AFortSafeZoneIndicator, PreviousCenter);
	DOREPLIFETIME(AFortSafeZoneIndicator, NextCenter);
	DOREPLIFETIME(AFortSafeZoneIndicator, CurrentTravelSplineComponent);
	DOREPLIFETIME(AFortSafeZoneIndicator, bSafezoneEventDriven);
	DOREPLIFETIME(AFortSafeZoneIndicator, bPaused);
	DOREPLIFETIME(AFortSafeZoneIndicator, bPausedForPreview);
	DOREPLIFETIME(AFortSafeZoneIndicator, NextNextMegaStormGridCellThickness);
	DOREPLIFETIME(AFortSafeZoneIndicator, NextMegaStormGridCellThickness);
	DOREPLIFETIME(AFortSafeZoneIndicator, MegaStormDelayTimeBeforeDestruction);
	DOREPLIFETIME(AFortSafeZoneIndicator, NumActiveMegaStormCircles);
	DOREPLIFETIME(AFortSafeZoneIndicator, ActiveMegaStormCircleGridCellCountFromEdge);
	DOREPLIFETIME(AFortSafeZoneIndicator, SafeZonePhases);
	DOREPLIFETIME(AFortSafeZoneIndicator, CurrentPhase);
	DOREPLIFETIME(AFortSafeZoneIndicator, CurrentDamageInfo);
	DOREPLIFETIME(AFortSafeZoneIndicator, PhaseCount);
	DOREPLIFETIME(AFortSafeZoneIndicator, SafeZoneStartShrinkTime);
	DOREPLIFETIME(AFortSafeZoneIndicator, SafeZoneFinishShrinkTime);
	DOREPLIFETIME(AFortSafeZoneIndicator, Radius);
	DOREPLIFETIME(AFortSafeZoneIndicator, bPreviewDuringWarmup);
	DOREPLIFETIME(AFortSafeZoneIndicator, TimeRemainingWhenPhasePaused);
	DOREPLIFETIME(AFortSafeZoneIndicator, ForceUpdateCount);
}
