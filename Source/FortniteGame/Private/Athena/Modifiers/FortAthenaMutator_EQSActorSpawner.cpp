// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_EQSActorSpawner.h"

UEQSActorSpawner* AFortAthenaMutator_EQSActorSpawner::GetEQSActorSpawnerByNameId(const FName& NameId)
{
	return nullptr;
}

bool AFortAthenaMutator_EQSActorSpawner::ShouldOverrideClassesToSpawn_Implementation(TArray<FEQSActorSpawnerClassToSpawnData>& OutOverrideClassesToSpawn, const FEQSActorSpawnerData& SpawnerData)
{
	return false;
}

bool AFortAthenaMutator_EQSActorSpawner::StartSpawningManually(const FName& NameId, int32 OptionalActivationId)
{
	return false;
}

FEQSActorSpawnerData UEQSActorSpawner::GetSpawnerData()
{
	return FEQSActorSpawnerData();
}

void UEQSActorSpawner::OnFindActorSpawnLocationQueryFinished(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus)
{
}

void UEQSActorSpawnerHelperDestroyActorsInArea::EQSActorSpawnerHelperDestroyActorsInArea_Implementation(TArray<AActor*>& OutDestroyedActors, const FTransform& Transform)
{
}
