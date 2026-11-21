// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPlaysetItemDefinition.h"

FVector UFortPlaysetItemDefinition::AdjustToFinalLocation(UObject* WorldContextObject, UFortPlaysetItemDefinition* Playset, FVector BaseLocation, FRotator Rotation)
{
	return FVector();
}

#if WITH_EDITOR
FName UFortPlaysetItemDefinition::GetPlaysetName() const
{
	return FName();
}
#endif

void UFortPlaysetItemDefinition::SpawnActorsInPlayset(AActor* WorldContextObject, UFortPlaysetItemDefinition* Playset)
{
}

ULevelStreamingDynamic* UFortPlaysetItemDefinition::SpawnPlayset(AActor* WorldContextObject, const UFortPlaysetItemDefinition* Playset, FVector Location, FRotator Rotation, FFortPlaysetStreamingData& OutLevelData)
{
	return nullptr;
}

ULevelStreamingDynamic* UFortPlaysetItemDefinition::SpawnPlaysetFromStruct(AActor* WorldContextObject, const FFortPlaysetStreamingData& LevelData)
{
	return nullptr;
}
