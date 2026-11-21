// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Infiltration.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_Infiltration::FinishRoundIntro(AFortAthenaMutator_ShowPlacard* ShowPlacardMutator)
{
}

uint8 AFortAthenaMutator_Infiltration::GetAttackingTeam(const AFortPlayerControllerAthena* PlayerController) const
{
	return uint8();
}

uint8 AFortAthenaMutator_Infiltration::GetDefendingTeam(const AFortPlayerControllerAthena* PlayerController) const
{
	return uint8();
}

void AFortAthenaMutator_Infiltration::OnRep_ModeState(FInfiltrationModeState OldState)
{
}

void AFortAthenaMutator_Infiltration::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, InfiltrationTeamInfos);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, ModeState);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, CurrentSpawnPoint);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, CurrentCapturePoint);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, POIInfo);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, CachedRoundHelper);
	DOREPLIFETIME(AFortAthenaMutator_Infiltration, IntelLocation);
}

void UFortCheatManager_Infiltration::ForceCaptureIntel()
{
}

void UFortCheatManager_Infiltration::ForceDefendIntel()
{
}
