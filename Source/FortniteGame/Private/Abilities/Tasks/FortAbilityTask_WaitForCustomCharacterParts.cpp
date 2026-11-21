// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_WaitForCustomCharacterParts.h"

void UFortAbilityTask_WaitForCustomCharacterParts::OnFinishedCharacterCustomizationCallback(AFortPlayerPawn* InPawn)
{
}

UFortAbilityTask_WaitForCustomCharacterParts* UFortAbilityTask_WaitForCustomCharacterParts::WaitForCustomCharacterPartsReady(UGameplayAbility* OwningAbility, TArray<TSoftObjectPtr<UCustomCharacterPart>> CustomCharacterParts)
{
	return nullptr;
}
