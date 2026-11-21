// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponent_SkillsetBase.h"

float UFortAthenaAISpawnerDataComponent_SkillsetBase::GetSkill_Implementation()
{
	return float();
}

TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> UFortAthenaAISpawnerDataComponent_SkillsetBase::GetSkillSets_Implementation()
{
	return TArray<TSubclassOf<UFortAthenaAIBotSkillSet>>();
}

bool UFortAthenaAISpawnerDataComponent_SkillsetBase::ShouldUseMatchMMRToOverrideSkillLevel_Implementation()
{
	return false;
}
