// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_BasicLimitedLives.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_BasicLimitedLives::OnRep_LiveData()
{
}

void AFortAthenaMutator_BasicLimitedLives::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_BasicLimitedLives, LiveData);
}
