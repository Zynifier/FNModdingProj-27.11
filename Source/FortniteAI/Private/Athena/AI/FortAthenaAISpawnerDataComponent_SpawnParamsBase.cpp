// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponent_SpawnParamsBase.h"

TSubclassOf<AAIController> UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetAIControllerClass_Implementation() const
{
	return TSubclassOf<AAIController>();
}

float UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetInAirSpawnTraceEndHeight_Implementation() const
{
	return float();
}

float UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetInAirSpawnTraceSphereRadius_Implementation() const
{
	return float();
}

float UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetInAirSpawnTraceStartHeight_Implementation() const
{
	return float();
}

TSubclassOf<APawn> UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetPawnClass_Implementation() const
{
	return TSubclassOf<APawn>();
}

FDataTableRowHandle UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetPawnStatHandle_Implementation() const
{
	return FDataTableRowHandle();
}

TArray<TSubclassOf<UFortAthenaAISpawnerData>> UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetSpawnerDataSpawnedAsChildren_Implementation() const
{
	return TArray<TSubclassOf<UFortAthenaAISpawnerData>>();
}

float UFortAthenaAISpawnerDataComponent_SpawnParamsBase::GetSpawnTracePadding_Implementation() const
{
	return float();
}

void UFortAthenaAISpawnerDataComponent_SpawnParamsBase::SetSpawnTransform(const FTransform& InSpawnTransform)
{
}

bool UFortAthenaAISpawnerDataComponent_SpawnParamsBase::ShouldCheckForOverlaps_Implementation() const
{
	return false;
}

bool UFortAthenaAISpawnerDataComponent_SpawnParamsBase::ShouldSpawnInAir_Implementation() const
{
	return false;
}
