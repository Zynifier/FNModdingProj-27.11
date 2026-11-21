// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_FF2.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_FF2::OnRep_CurrentRound()
{
}

void AFortAthenaMutator_FF2::OnRep_EndOfLastRoundServerTime()
{
}

void AFortAthenaMutator_FF2::UpdateHealth()
{
}

void AFortAthenaMutator_FF2::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_FF2, FoundationsToWatch);
	DOREPLIFETIME(AFortAthenaMutator_FF2, CurrentRound);
	DOREPLIFETIME(AFortAthenaMutator_FF2, CurrentHealth);
	DOREPLIFETIME(AFortAthenaMutator_FF2, MaxHealth);
	DOREPLIFETIME(AFortAthenaMutator_FF2, EndOfLastRoundServerTime);
}
