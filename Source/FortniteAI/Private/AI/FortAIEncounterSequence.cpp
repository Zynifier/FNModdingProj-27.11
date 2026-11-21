// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIEncounterSequence.h"

bool UFortAIEncounterSequence::EncounterBelongsToSequence(UFortAIEncounterInfo* InEncounter) const
{
	return false;
}

UFortAIEncounterInfo* UFortAIEncounterSequence::GetCurrentEncounter() const
{
	return nullptr;
}

int32 UFortAIEncounterSequence::GetEncounterIndexInSequence() const
{
	return int32();
}

int32 UFortAIEncounterSequence::GetNumEncountersInSequence() const
{
	return int32();
}

bool UFortAIEncounterSequence::HasEncounter() const
{
	return false;
}

bool UFortAIEncounterSequence::IsOnFinalIndexInSequence() const
{
	return false;
}

EFortEncounterSequenceResult UFortAIEncounterSequence::Last()
{
	return EFortEncounterSequenceResult();
}

EFortEncounterSequenceResult UFortAIEncounterSequence::Next()
{
	return EFortEncounterSequenceResult();
}

EFortEncounterSequenceResult UFortAIEncounterSequence::Previous()
{
	return EFortEncounterSequenceResult();
}

void UFortAIEncounterSequence::SetEncounterStartingData(const TArray<AActor*>& InTargetActors, UFortAIAssignmentSettings* InAssignmentSettings, FEncounterEnvironmentQueryInfo InOverrideEnvironmentQueryInfo, AActor* InOptionalQueryActor, FGameplayTagContainer InInjectedTags, FFortEncounterSettings InEncounterSettings)
{
}

UFortAIEncounterInfo* UFortAIEncounterSequence::StartCurrentEncounter(EFortEncounterSequenceResult& OutRequestResult, const TArray<AActor*>& InTargetActors, UFortAIAssignmentSettings* InAssignmentSettings, FEncounterEnvironmentQueryInfo InOverrideEnvironmentQueryInfo, AActor* InOptionalQueryActor, FGameplayTagContainer InInjectedTags, FFortEncounterSettings InEncounterSettings, int32 ActivationDelay)
{
	return nullptr;
}

UFortAIEncounterInfo* UFortAIEncounterSequence::StartCurrentEncounterWithSavedData(EFortEncounterSequenceResult& OutRequestResult, int32 ActivationDelay)
{
	return nullptr;
}

void UFortAIEncounterSequence::StopCurrentEncounter()
{
}
