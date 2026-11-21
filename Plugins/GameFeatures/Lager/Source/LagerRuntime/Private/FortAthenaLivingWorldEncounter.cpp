// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldEncounter.h"

void UFortAthenaLivingWorldEncounterInstance::AddAllowedPointProvider(const TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>& PointProvider)
{
}

void UFortAthenaLivingWorldEncounterInstance::AdvanceEncounterStage()
{
}

int32 UFortAthenaLivingWorldEncounterInstance::GetAliveSpawnedActorCount() const
{
	return int32();
}

int32 UFortAthenaLivingWorldEncounterInstance::GetTotalActorCount() const
{
	return int32();
}

bool UFortAthenaLivingWorldEncounterInstance::HasReachedMaxSpawnedCount() const
{
	return false;
}

void UFortAthenaLivingWorldEncounterInstance::OnEncounterActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

bool UFortAthenaLivingWorldEncounterInstance::OwnsActor(AActor* Actor) const
{
	return false;
}

void UFortAthenaLivingWorldEncounterInstance::PauseEncounter()
{
}

void UFortAthenaLivingWorldEncounterInstance::RemoveAllowedPointProvider(const TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>& PointProvider)
{
}

void UFortAthenaLivingWorldEncounterInstance::RequestEventGeneration()
{
}

void UFortAthenaLivingWorldEncounterInstance::Reset()
{
}

void UFortAthenaLivingWorldEncounterInstance::ResumeEncounter()
{
}

void UFortAthenaLivingWorldEncounterInstance::StartEncounterStage(const int32 StageIndex)
{
}
