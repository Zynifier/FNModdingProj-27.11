// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeStormShield.h"
#include "Net/UnrealNetwork.h"

float AFortCreativeStormShield::GetServerTime() const
{
	return float();
}

void AFortCreativeStormShield::OnGamePhaseStepChanged()
{
}

void AFortCreativeStormShield::OnRep_GamePhaseStep()
{
}

void AFortCreativeStormShield::SetGamePhaseStep(const EAthenaGamePhaseStep NewGamePhaseStep)
{
}

void AFortCreativeStormShield::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCreativeStormShield, GamePhaseStep);
	DOREPLIFETIME(AFortCreativeStormShield, NextTargetRadius);
	DOREPLIFETIME(AFortCreativeStormShield, NextTargetLocation);
	DOREPLIFETIME(AFortCreativeStormShield, NextNextTargetRadius);
	DOREPLIFETIME(AFortCreativeStormShield, NextNextTargetLocation);
	DOREPLIFETIME(AFortCreativeStormShield, InstancedServerTime);
}
