// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Components/FortAISpawnerUtilityComponent.h"

void UFortAISpawnerUtilityComponent::HandleUnownedPawnSpawned(AFortPawn* FortPawn)
{
}

bool UFortAISpawnerUtilityComponent::IsSpawnCountCapped() const
{
	return false;
}

void UFortAISpawnerUtilityComponent::OnUnownedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

int32 UFortAISpawnerUtilityComponent::RequestSpawn(UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList, const FTransform& SpawnTransform)
{
	return int32();
}

void UFortAISpawnerUtilityComponent::SetEQSQuery(TSoftObjectPtr<UEnvQuery> SelectedEQSQuery)
{
}

void UFortAISpawnerUtilityComponent::SetMinigame(const AFortMinigame* Minigame)
{
}

void UFortAISpawnerUtilityComponent::SetQueryRadius(float Radius)
{
}

void UFortAISpawnerUtilityComponent::StartEnvironmentQuery()
{
}
