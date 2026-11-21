// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/Collections/FortMcpCollectableCharacter.h"

EFortCollectedState UFortMcpCollectableCharacter::AddToPlayerCollection(const AFortPlayerController* FPC, const FGameplayTag& Variant, const FFortMcpCollectedCharacterProperties& Props, const FGameplayTagContainer& ContextTags, ECharacterEncounterType EncounterType)
{
	return EFortCollectedState();
}

void UFortMcpCollectableCharacter::SavePlayerQuestUpdate(const AFortPlayerController* FPC, const FGameplayTag& Variant, ESavePlayerQuestUpdate Update)
{
}
