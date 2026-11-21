// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortKeysAndLocksDisplayCase.h"

void AFortKeysAndLocksDisplayCase::NativeCalculateLockInteractStrings(const TArray<FFortItemEntry>& Loot, const TArray<FText>& RarityTexts, const UFortWorldItemDefinition* ItemDefinition, const bool bShowCount, FText& HaveKey, FText& NeedKey)
{
}

bool AFortKeysAndLocksDisplayCase::NativeLockChildActorsPassAllRequirements(const TArray<UChildActorComponent*>& LockChildActors, const UFortWorldItemDefinition* ItemDefinition)
{
	return false;
}
