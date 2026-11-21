// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponentList.h"

UFortAthenaAISpawnerDataComponent* UFortAthenaAISpawnerDataComponentList::GetComponentClassForModification(const TSubclassOf<UFortAthenaAISpawnerDataComponent> ClassToGet)
{
	return nullptr;
}

const APawn* UFortAthenaAISpawnerDataComponentList::GetDefaultPawn() const
{
	return nullptr;
}

TArray<UFortAthenaAISpawnerDataComponent*> UFortAthenaAISpawnerDataComponentList::GetList()
{
	return TArray<UFortAthenaAISpawnerDataComponent*>();
}

UFortAthenaAISpawnerDataComponent* UFortAthenaAISpawnerDataComponentList::GetOrCreateComponentClassForModification(UObject* ComponentOuter, const TSubclassOf<UFortAthenaAISpawnerDataComponent> ClassToClone) const
{
	return nullptr;
}

const FTransform& UFortAthenaAISpawnerDataComponentList::GetSpawnTransform() const
{
	static FTransform Dummy;
	return Dummy;
}

UFortAthenaAISpawnerDataComponentList* UFortAthenaAISpawnerDataComponentList::OverrideComponent(const UFortAthenaAISpawnerDataComponent* NewComponent)
{
	return nullptr;
}

UFortAthenaAISpawnerDataComponentList* UFortAthenaAISpawnerDataComponentList::OverrideComponentClass(const TSubclassOf<UFortAthenaAISpawnerDataComponent> NewComponentSubClass)
{
	return nullptr;
}
