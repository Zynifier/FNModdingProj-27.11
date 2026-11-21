// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAIDirector.h"
#include "FortAISpawnGroupCapsCategorySet.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAISpawnGroupCapsCategorySet : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupCapsCategorySet")
	TArray<FFortAIEncounterSpawnGroupCapsCategory> SpawnGroupCapsCategories;

};

