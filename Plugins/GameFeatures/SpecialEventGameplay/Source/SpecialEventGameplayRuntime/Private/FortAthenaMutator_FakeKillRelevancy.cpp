// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMutator_FakeKillRelevancy.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_FakeKillRelevancy::EndWave(const int32 EndPhaseNum, const int32 WaveNum)
{
}

void AFortAthenaMutator_FakeKillRelevancy::ResetRelevancy()
{
}

void AFortAthenaMutator_FakeKillRelevancy::SetUpKillPhase(const int32 MaxPlayersRemaining, const FGameplayTag& Reason, const int32 NumWaves, const float RelevancyDelay)
{
}

void AFortAthenaMutator_FakeKillRelevancy::StartNextKillWave()
{
}

void AFortAthenaMutator_FakeKillRelevancy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_FakeKillRelevancy, RelevancyPhaseDataArray);
	DOREPLIFETIME(AFortAthenaMutator_FakeKillRelevancy, PhaseNum);
}

void UFortCheatManager_FakeKillRelevancy::FakeKillRelevancyDebug(const float TextScale)
{
}

void UFortCheatManager_FakeKillRelevancy::FakeKillRelevancyReset()
{
}

void UFortCheatManager_FakeKillRelevancy::FakeKillRelevancySetUpPhase(const int32 MaxPlayersRemaining, const FString& ReasonGameplayTagString, const int32 NumWaves, const float RelevancyDelay)
{
}

void UFortCheatManager_FakeKillRelevancy::FakeKillRelevancyStartNextWave()
{
}

void UFortCheatManager_FakeKillRelevancy::FakeKillRelevancyTestAlgorithm(const int32 NumPlayers, const FString& MaxPlayersRemainingAfterPhases, const int32 MinSquadSize, const int32 MaxSquadSize, const int32 Iterations, const int32 LogVerbosity)
{
}

FVector UFortControllerComponent_FakeKillRelevancy::GetDeathLocation(const AFortPlayerStateAthena* PlayerState) const
{
	return FVector();
}

void UFortControllerComponent_FakeKillRelevancy::OnKillEffectsPlayed(const AFortPlayerStateAthena* PlayerState)
{
}

void UFortControllerComponent_FakeKillRelevancy::OnRep_ResetCounter()
{
}

void UFortControllerComponent_FakeKillRelevancy::ResetRelevancy()
{
}

void UFortControllerComponent_FakeKillRelevancy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_FakeKillRelevancy, PlayerDataArray);
	DOREPLIFETIME(UFortControllerComponent_FakeKillRelevancy, ResetCounter);
	DOREPLIFETIME(UFortControllerComponent_FakeKillRelevancy, DebugSupergroupPlayerStates);
}
