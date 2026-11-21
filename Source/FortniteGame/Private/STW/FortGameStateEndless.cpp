// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortGameStateEndless.h"
#include "Net/UnrealNetwork.h"

int32 AFortGameStateEndless::GetWaveNumber()
{
	return int32();
}

void AFortGameStateEndless::SetWaveNumber(int32 NewWaveNumber)
{
}

void AFortGameStateEndless::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStateEndless, WaveNumber);
}
