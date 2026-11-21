// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIDirector.h"

void AFortAIDirector::Activate()
{
}

TArray<TEnumAsByte<EFortEncounterDirection::Type>> AFortAIDirector::ConvertInvalidDirectionsToValidDirections(TArray<TEnumAsByte<EFortEncounterDirection::Type>> InvalidDirections)
{
	return TArray<TEnumAsByte<EFortEncounterDirection::Type>>();
}

void AFortAIDirector::Deactivate()
{
}

void AFortAIDirector::GetAmbientThreatEncounterSpawnLocations(TArray<FVector>& AmbientThreatEncounterSpawnLocations) const
{
}

EFortEncounterDirection::Type AFortAIDirector::GetEncounterDirectionFromVector(FVector DirectionVector)
{
	return EFortEncounterDirection::Type();
}

int32 AFortAIDirector::GetNumActiveEncounters()
{
	return int32();
}

int32 AFortAIDirector::GetNumPlayers() const
{
	return int32();
}

int32 AFortAIDirector::GetPlayerPawnsInRange(const FVector& Origin, const float Radius, TArray<AFortPlayerPawn*>& OutPawns) const
{
	return int32();
}

TArray<ABuildingRift*> AFortAIDirector::GetRiftsFromClosestActiveEncounterTo(AActor* Target) const
{
	return TArray<ABuildingRift*>();
}

FVector AFortAIDirector::GetVectorFromEncounterDirection(EFortEncounterDirection::Type Direction)
{
	return FVector();
}

bool AFortAIDirector::IsAnyActiveEncounterRelevantToDefender(AFortAIPawn* Defender) const
{
	return false;
}

bool AFortAIDirector::IsAnyActiveEncounterRelevantToPlayer(const AFortPlayerPawn* Player) const
{
	return false;
}

bool AFortAIDirector::IsAnyAIRelevantToPlayer(AFortPlayerPawn* Player) const
{
	return false;
}

bool AFortAIDirector::IsAnyEncounterGoalWithinDistanceOfPoint(const FVector& Point, float Distance, bool bOnlyActiveEncounters) const
{
	return false;
}

bool AFortAIDirector::IsLineTooCloseToPatrolWards(const FVector& LineStart, const FVector& LineEnd) const
{
	return false;
}

bool AFortAIDirector::IsPointTooCloseToPatrolWards(const FVector& Point, const EWardAffectType WardEffectTypeFilter) const
{
	return false;
}

void AFortAIDirector::OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation)
{
}

void AFortAIDirector::RegisterPatrolWard(TScriptInterface<IFortPatrolWardInterface> PatrolWard)
{
}

UFortAIEncounterInfo* AFortAIDirector::StartEncounter(FString& EncounterInstigator, UFortDifficultyEncounterSettings* DifficultyEncounterSettings, FFortAIEncounterQueryData OptionalQueryData)
{
	return nullptr;
}

void AFortAIDirector::UnregisterPatrolWard(TScriptInterface<IFortPatrolWardInterface> PatrolWard)
{
}
