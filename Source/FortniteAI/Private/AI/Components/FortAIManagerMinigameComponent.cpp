// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Components/FortAIManagerMinigameComponent.h"

FGameplayTag UFortAIManagerMinigameComponent::GetSpawnTagFromPawnObject(const UObject* PawnObject) const
{
	return FGameplayTag();
}

void UFortAIManagerMinigameComponent::HandleMinigameStarted()
{
}

void UFortAIManagerMinigameComponent::OnPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAIManagerMinigameComponent::OnPawnSpawned(APawn* Pawn, const int32 RequestID)
{
}
