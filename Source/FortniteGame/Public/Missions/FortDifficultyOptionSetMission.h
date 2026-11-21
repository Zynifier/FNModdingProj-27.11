// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortDifficultyOptionSetMission.generated.h"

class UFortDifficultyOptionCategoryMission;

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionSetMission : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="FortDifficultyOptionSetMission")
	TArray<TObjectPtr<UFortDifficultyOptionCategoryMission>> MissionOptionsCategories;

};

