// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIEncounterInfo.h"

UFortAIAssignment* UFortAIEncounterInfo::CreateEncounterAssignment(UFortAIAssignmentSettings* AssignmentSettings, AActor* GoalActor)
{
	return nullptr;
}

void UFortAIEncounterInfo::DespawnPendingAndCurrentAI()
{
}

bool UFortAIEncounterInfo::EncounterHasReservedSpawnRequestForEnemySpawner(AActor* EnemySpawner) const
{
	return false;
}

bool UFortAIEncounterInfo::GetCurrentSpawnAreaDirections(TArray<TEnumAsByte<EFortEncounterDirection::Type>>& OutDirections) const
{
	return false;
}

void UFortAIEncounterInfo::GetEncounterAssignmentGoalActors(TArray<AActor*>& OutGoalActors) const
{
}

AFortAIDirectorDataManager* UFortAIEncounterInfo::GetEncounterDataManager()
{
	return nullptr;
}

void UFortAIEncounterInfo::GetEncounterGameplayTags(FGameplayTagContainer& OutEncounterTags) const
{
}

AActor* UFortAIEncounterInfo::GetEncounterQueryActor() const
{
	return nullptr;
}

void UFortAIEncounterInfo::GetEncounterRifts(TArray<ABuildingRift*>& OutRifts) const
{
}

float UFortAIEncounterInfo::GetEncounterTimeSeconds()
{
	return float();
}

int32 UFortAIEncounterInfo::GetPawnNumberLimit() const
{
	return int32();
}

bool UFortAIEncounterInfo::GroupHasAIRemainingToSpawn(const FFortAISpawnerData& FortAISpawnerData)
{
	return false;
}

void UFortAIEncounterInfo::NotifyRiftDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAIEncounterInfo::OnEncounterPawnDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAIEncounterInfo::OnGameDifficultyChanged()
{
}

void UFortAIEncounterInfo::OnGoalTakeDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAIEncounterInfo::RegisterAISpawner(AActor* InAISpawner)
{
}

void UFortAIEncounterInfo::RequestActivation(int32 ActivationDelay)
{
}

void UFortAIEncounterInfo::SetEncounterActivationState(bool bEncounterActivityState)
{
}

void UFortAIEncounterInfo::SetNukeWavesAtEncounterEnd(bool bNuke)
{
}

void UFortAIEncounterInfo::SetPawnNumberLimit(int32 InPawnNumberLimit)
{
}

AFortAIPawn* UFortAIEncounterInfo::SpawnAIPawnReservedForEnemySpawner(AActor* EnemySpawner, FVector SpawnLocation, FRotator SpawnRotation)
{
	return nullptr;
}

void UFortAIEncounterInfo::SpawnTestAIGroup(const UFortAISpawnGroup* SpawnGroupToSpawn, FVector SpawnLocation, FRotator SpawnRotation, AActor* SpawnSource, const TArray<UFortAbilitySet*> AbilitySetsToGrantOnSpawn, FFortAISpawnGroupUpgradeData UpgradeData, bool bAllowAssigningToExternalSpawners, float SecondsBetweenSpawns)
{
}

void UFortAIEncounterInfo::UnRegisterAISpawner(AActor* InAISpawner)
{
}
