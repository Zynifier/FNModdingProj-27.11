// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_MatchConditionManager.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_MatchConditionManager::OnSatisfied(const AFortAthenaMutator_MatchCondition* MatchConditionMutator, const bool bSatisfied)
{
}

void AFortAthenaMutator_MatchConditionManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_MatchConditionManager, TeamNums);
	DOREPLIFETIME(AFortAthenaMutator_MatchConditionManager, MatchConditionMutators);
}

void UFortCheatManager_MatchConditionManagerMutator::MatchConditionManagerMutatorDebug(const float TextScale)
{
}
