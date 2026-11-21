// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_Rounds.h"
#include "Net/UnrealNetwork.h"

int32 AFortAthenaMutator_Rounds::GetLastCompletedRoundNum() const
{
	return int32();
}

EAthenaRoundsMutatorPhase AFortAthenaMutator_Rounds::GetPhase() const
{
	return EAthenaRoundsMutatorPhase();
}

int32 AFortAthenaMutator_Rounds::GetRoundNum() const
{
	return int32();
}

void AFortAthenaMutator_Rounds::OnMatchConditionTimingSatisfied(const EMatchConditionMutatorTimingType TimingType)
{
}

void AFortAthenaMutator_Rounds::OnRep_CurrentRoundNum()
{
}

void AFortAthenaMutator_Rounds::OnRep_RoundPhase(const EAthenaRoundsMutatorPhase OldRoundPhase)
{
}

void AFortAthenaMutator_Rounds::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Rounds, RoundPhase);
	DOREPLIFETIME(AFortAthenaMutator_Rounds, CurrentRoundNum);
}

void UFortCheatManager_RoundsMutator::RoundsMutatorDebug(const float TextScale)
{
}
