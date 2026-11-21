// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterDefinition/NPCCharacterType_FromPreset.h"

TSoftClassPtr<UFortAthenaAISpawnerData> UNPCCharacterType_FromPreset::GetAIToSpawn() const
{
	return TSoftClassPtr<UFortAthenaAISpawnerData>();
}

TArray<FString> UNPCCharacterType_FromPreset::GetAvailableAIs() const
{
	return TArray<FString>();
}
