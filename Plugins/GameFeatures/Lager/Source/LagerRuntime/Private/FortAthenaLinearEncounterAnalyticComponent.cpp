// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLinearEncounterAnalyticComponent.h"

void UFortAthenaLinearEncounterAnalyticComponent::OnAttackerSpawned(AActor* SpawnedAttacker)
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnDefenderDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnDefenderDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnDefenderDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnDefenderSpawned(AActor* SpawnedDefender)
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnEncounterEnd()
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnEncounterStart(UFortAthenaLivingWorldEncounterInstance* InAttackerEncounter, UFortAthenaLivingWorldEncounterInstance* InDefenderEncounter)
{
}

void UFortAthenaLinearEncounterAnalyticComponent::OnStageCompleted(const TArray<AFortPickup*>& SpawnedRewards)
{
}
