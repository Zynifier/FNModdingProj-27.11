// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_MatchCondition.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_MatchCondition::OnGamePhaseChanged(const EAthenaGamePhase NewPhase, const EAthenaGamePhase PreviousHighestGamePhaseProcessed)
{
}

void AFortAthenaMutator_MatchCondition::OnRep_bSatisfied()
{
}

void AFortAthenaMutator_MatchCondition::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_MatchCondition, MatchConditionManager);
	DOREPLIFETIME(AFortAthenaMutator_MatchCondition, bSatisfied);
	DOREPLIFETIME(AFortAthenaMutator_MatchCondition, bLocked);
	DOREPLIFETIME(AFortAthenaMutator_MatchCondition, bLockedPermanently);
	DOREPLIFETIME(AFortAthenaMutator_MatchCondition, TeamDataArray);
}
