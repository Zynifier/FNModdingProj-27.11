// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventScript.h"
#include "Net/UnrealNetwork.h"

void ASpecialEventScript::AttemptFinishPhase(FGameplayTag PhaseTag)
{
}

void ASpecialEventScript::AttemptStartNextPhase(FGameplayTag CurrentPhaseTag)
{
}

int32 ASpecialEventScript::GetActivePhaseIndex() const
{
	return int32();
}

void ASpecialEventScript::OnRep_ReplicatedActivePhaseIndex()
{
}

void ASpecialEventScript::SetLocalPlayersSignificantForSpecialEventSequence(const bool bIsSignificant) const
{
}

void ASpecialEventScript::StartEventAtIndex(const int32 InStartingIndex, const float SequenceTimeOffset)
{
}

void ASpecialEventScript::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASpecialEventScript, ReplicatedActivePhaseIndex);
}
