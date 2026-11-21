// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaNpcGalileoComponent.h"

const TArray<AFortAthenaAIBotController*>& UFortAthenaNpcGalileoComponent::GetCommunicationGroup()
{
	static TArray<AFortAthenaAIBotController*> Dummy;
	return Dummy;
}

const TArray<FVector>& UFortAthenaNpcGalileoComponent::GetPatrolPath() const
{
	static TArray<FVector> Dummy;
	return Dummy;
}

void UFortAthenaNpcGalileoComponent::OnPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAthenaNpcGalileoComponent::SetCommunicationGroup(const TArray<AFortAthenaAIBotController*>& AIBotControllerList)
{
}

void UFortAthenaNpcGalileoComponent::SetPatrolPath(const TArray<FVector>& NewPatrolPath)
{
}
