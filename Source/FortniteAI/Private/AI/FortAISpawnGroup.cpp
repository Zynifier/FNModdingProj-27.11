// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAISpawnGroup.h"

TSubclassOf<UFortAIPawnVariant> UFortAISpawnGroup::GetEnemy(int32 EnemyIndex) const
{
	return TSubclassOf<UFortAIPawnVariant>();
}

int32 UFortAISpawnGroup::GetNumberOfEnemies() const
{
	return int32();
}

bool UFortAISpawnGroup::IsLargeSpawnGroup() const
{
	return false;
}

bool UFortAISpawnGroup::IsPrototype() const
{
	return false;
}

bool UFortAISpawnGroup::IsValidForEnemySpawners() const
{
	return false;
}
