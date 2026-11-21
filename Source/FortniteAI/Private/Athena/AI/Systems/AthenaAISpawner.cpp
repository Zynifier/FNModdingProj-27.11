// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAISpawner.h"

bool UAthenaAISpawner::CancelRequest(const int32 RequestID)
{
	return false;
}

void UAthenaAISpawner::QueueForDespawn(AActor* ActorToDespawn)
{
}

int32 UAthenaAISpawner::RequestSpawn(UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList, const FTransform& SpawnTransform, const bool bUrgentRequest)
{
	return int32();
}
