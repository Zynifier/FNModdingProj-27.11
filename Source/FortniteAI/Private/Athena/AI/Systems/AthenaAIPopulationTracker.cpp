// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAIPopulationTracker.h"

TArray<AController*> UAthenaAIPopulationTracker::GetAIMatchingQuery(const FGameplayTagQuery& TagQuery) const
{
	return TArray<AController*>();
}

FAIPopulationCountSnapshot UAthenaAIPopulationTracker::GetAIPopulationTrackerCount() const
{
	return FAIPopulationCountSnapshot();
}

int32 UAthenaAIPopulationTracker::GetNumAIPawn() const
{
	return int32();
}

int32 UAthenaAIPopulationTracker::GetNumNonAthenaParticipantBots() const
{
	return int32();
}

int32 UAthenaAIPopulationTracker::GetNumPlayerBots() const
{
	return int32();
}

int32 UAthenaAIPopulationTracker::GetNumTotalBots() const
{
	return int32();
}

void UAthenaAIPopulationTracker::OnAgentGameOver(AFortAthenaAIBotController* AIBotController, AFortPawn* Pawn, AController* Instigator)
{
}

void UAthenaAIPopulationTracker::OnAISpawned(APawn* Pawn, const int32 RequestID)
{
}

void UAthenaAIPopulationTracker::OnFortPawnDestroyed(AActor* DestroyedActor)
{
}

void UAthenaAIPopulationTracker::OnFortPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}
