// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionStormShield.h"
#include "Net/UnrealNetwork.h"

void AFortMissionStormShield::DestroyStormShield()
{
}

void AFortMissionStormShield::GetSafeZones(TArray<AFortMissionStormSafeZone*>& OutSafeZones)
{
}

void AFortMissionStormShield::InitializeRadiusValue(const float InRadius)
{
}

bool AFortMissionStormShield::IsInStormShield(FVector TestLocation) const
{
	return false;
}

void AFortMissionStormShield::OnRep_RadiusGrowthData()
{
}

void AFortMissionStormShield::OnRep_ReplicatedRadius()
{
}

void AFortMissionStormShield::PauseStormShield()
{
}

bool AFortMissionStormShield::RemoveAndDestroySafeArea(AFortMissionStormSafeZone* AreaToRemove)
{
	return false;
}

void AFortMissionStormShield::SetCurrentPhase(const int32 InCurrentPhase)
{
}

void AFortMissionStormShield::SetNumPhases(const int32 InNumPhases)
{
}

void AFortMissionStormShield::SetRadiusOfShield(const float InRadius)
{
}

void AFortMissionStormShield::SetTargetLocationToMoveTo(const FVector InTargetLocation, const float InMoveRate)
{
}

void AFortMissionStormShield::SetTargetRadiusSizeChangeOverGrowthRate(const float InTargetRadius, const float InGrowthRate, bool bUseGrowthRateDirectly)
{
}

AFortMissionStormSafeZone* AFortMissionStormShield::SpawnSafeAreaAtLocation(const FVector& InLocation, const float InRadius)
{
	return nullptr;
}

void AFortMissionStormShield::UpdateRadiusVisuals_Implementation()
{
}

void AFortMissionStormShield::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMissionStormShield, ReplicatedRadius);
	DOREPLIFETIME(AFortMissionStormShield, RadiusGrowthData);
	DOREPLIFETIME(AFortMissionStormShield, MoveData);
	DOREPLIFETIME(AFortMissionStormShield, UseGrowthRateDirectly);
	DOREPLIFETIME(AFortMissionStormShield, bAntiStormShield);
	DOREPLIFETIME(AFortMissionStormShield, NumPhases);
	DOREPLIFETIME(AFortMissionStormShield, CurrentPhase);
	DOREPLIFETIME(AFortMissionStormShield, SafeAreas);
}
