// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "WorldConditionQuery.h"
#include "EncounterFactionData.generated.h"

class UDataTable;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UEncounterFactionData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagQuery RequiredCapabilities;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FWorldConditionQueryDefinition WorldConditionDefinition;

	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.LWMEncounterRow"))
	TObjectPtr<UDataTable> LWMEncounterTable;

};

