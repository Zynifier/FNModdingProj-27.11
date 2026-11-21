// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterDefinition/NPCCharacterModifier.h"

EDataValidationResult UNPCCharacterModifier::BP_IsDataValid_Implementation(TArray<FText>& OutErrorMessages) const
{
	return EDataValidationResult();
}

bool UNPCCharacterModifier::BP_IsNeededForPreview_Implementation() const
{
	return false;
}

void UNPCCharacterModifier::BP_ModifySpawnComponentList_Implementation(UFortAthenaAISpawnerDataComponentList* OutList, UObject* ComponentOuter)
{
}

void UNPCCharacterModifier::BP_OnPreSpawned_Implementation(AFortPawn* Pawn)
{
}

void UNPCCharacterModifier::BP_OnSpawned_Implementation(AFortPawn* Pawn)
{
}

UNPCCharacterDefinition* UNPCCharacterModifier::GetCharacterDefinition() const
{
	return nullptr;
}
