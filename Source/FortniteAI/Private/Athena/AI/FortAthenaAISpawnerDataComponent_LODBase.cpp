// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponent_LODBase.h"

UFortAthenaAILODSettingsContainer* UFortAthenaAISpawnerDataComponent_LODBase::GetAILODSettingsContainer_Implementation() const
{
	return nullptr;
}

FClientAILODSettings UFortAthenaAISpawnerDataComponent_LODBase::GetClientAILODSettings_Implementation() const
{
	return FClientAILODSettings();
}
