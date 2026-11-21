// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterDefinition/NPCCharacterDefinition.h"

UFortAthenaAISpawnerDataComponentList* UNPCCharacterDefinition::CreateComponentList(UObject* Outer, const TArray<UNPCCharacterModifier*>& AdditionalModifiers, const bool bForPreview) const
{
	return nullptr;
}

TSubclassOf<AActor> UNPCCharacterDefinition::GetCharacterBlueprint(const TArray<UNPCCharacterModifier*>& AdditionalModifiers) const
{
	return TSubclassOf<AActor>();
}

const UAthenaCharacterItemDefinition* UNPCCharacterDefinition::GetCharacterCID(UObject* Outer, const TArray<UNPCCharacterModifier*>& AdditionalModifiers) const
{
	return nullptr;
}

void UNPCCharacterDefinition::GetPreviewMesh(UObject* Outer, const TArray<UNPCCharacterModifier*>& AdditionalModifiers, TArray<FCharacterPreviewMesh>& OutCharacterPreviewMeshes, APawn*& OutDefaultPawn) const
{
}

void UNPCCharacterDefinition::GetRequiredAssets(TArray<FSoftObjectPath>& OutAssets) const
{
}
