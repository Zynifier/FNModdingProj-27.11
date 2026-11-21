// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldPrefabActorSpawner.h"

void AFortAthenaLivingWorldPrefabActorSpawner::CallWhenActorSpawned(const FOnActorSpawnedDelegate& DelegateToCall)
{
}

AActor* AFortAthenaLivingWorldPrefabActorSpawner::GetSpawnedActor() const
{
	return nullptr;
}

void AFortAthenaLivingWorldPrefabActorSpawner::OnSnapCompleted(UFortSnapOnSurfaceComponent* Component, const FTransform& OldTransform, const FTransform& NewTransfom)
{
}
