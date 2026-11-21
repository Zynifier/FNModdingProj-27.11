// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_DadBro.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_DadBro::DespawnPickupsForAoE(float InstantDespawnRange, float MaxDespawnRange, float DespawnTravelSpeed)
{
}

void AFortAthenaMutator_DadBro::DoDebugSphereForImpulse_Implementation()
{
}

FRotator AFortAthenaMutator_DadBro::GetDesiredDadBroRotation() const
{
	return FRotator();
}

float AFortAthenaMutator_DadBro::GetTimeSinceDadBroStart() const
{
	return float();
}

void AFortAthenaMutator_DadBro::HandleAIDied(UFortAIEncounterInfo* Encounter, AFortAIPawn* DyingEnemy)
{
}

void AFortAthenaMutator_DadBro::HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy)
{
}

void AFortAthenaMutator_DadBro::HandleNewTimeOfDayManager(TScriptInterface<IFortTimeOfDayManagerInterface> NewTodManager) const
{
}

void AFortAthenaMutator_DadBro::ListenedPawnLanded(const FHitResult& Hit)
{
}

void AFortAthenaMutator_DadBro::OnRep_DadBroCodeState()
{
}

void AFortAthenaMutator_DadBro::OnRep_DadBroPawn()
{
}

void AFortAthenaMutator_DadBro::ResetBackToStartSafeZone()
{
}

void AFortAthenaMutator_DadBro::StartNextSafeZonePhase()
{
}

void AFortAthenaMutator_DadBro::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_DadBro, DadBroPawn);
	DOREPLIFETIME(AFortAthenaMutator_DadBro, DadBroCodeState);
	DOREPLIFETIME(AFortAthenaMutator_DadBro, ServerTimeDadBroStarted);
	DOREPLIFETIME(AFortAthenaMutator_DadBro, TimeTakenToDefeatDadBro);
}
