// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_RespawnWave.h"
#include "Net/UnrealNetwork.h"

int32 AFortAthenaMutator_RespawnWave::GetNextWavePlayerCount(const AFortPlayerStateAthena* PlayerState)
{
	return int32();
}

void AFortAthenaMutator_RespawnWave::GetNextWavePlayerStates(const AFortPlayerStateAthena* PlayerState, TArray<AFortPlayerStateAthena*>& OutPlayerStates)
{
}

float AFortAthenaMutator_RespawnWave::GetTimeUntilNextWave(const AFortPlayerStateAthena* PlayerState)
{
	return float();
}

float AFortAthenaMutator_RespawnWave::GetWaveTime_Implementation(uint8 Team) const
{
	return float();
}

void AFortAthenaMutator_RespawnWave::OnRep_WaveDataArray()
{
}

void AFortAthenaMutator_RespawnWave::OnWaveLaunched()
{
}

void AFortAthenaMutator_RespawnWave::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_RespawnWave, WaveDataArray);
}
