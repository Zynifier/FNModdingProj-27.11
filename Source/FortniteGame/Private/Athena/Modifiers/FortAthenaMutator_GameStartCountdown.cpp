// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_GameStartCountdown.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_GameStartCountdown::OnRep_CountdownTimerRunning()
{
}

void AFortAthenaMutator_GameStartCountdown::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_GameStartCountdown, bCountdownTimerRunning);
}
