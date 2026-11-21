// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AI/FortAIEncounterInfo.h"
#include "FortAISpawnGroupProgressionInfo.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAISpawnGroupProgressionInfo : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="SpawnGroups")
	TArray<FSpawnGroupProgression> SpawnGroups;

};

