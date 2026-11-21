// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "WorldConditionQuery.h"
#include "FortAthenaLivingWorldCategory.generated.h"

class UDataTable;
class UFortAthenaLivingWorldEncounter;

USTRUCT()
struct FFortLivingWorldEventTableVariation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLivingWorldEventTableVariation")
	TSoftObjectPtr<UDataTable> EventTableVariation;

	UPROPERTY(EditDefaultsOnly, Category="FortLivingWorldEventTableVariation")
	FScalableFloat VariationWeight;

};

USTRUCT()
struct FFortAthenaLivingWorldCategory : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> EventTable;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TArray<FFortLivingWorldEventTableVariation> EventTableVariations;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	int32 MaxCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	int32 MaxSpawnedCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	int32 EventInstanceMaxCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	int32 EventInstanceMaxSpawnedCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FWorldConditionQueryDefinition CanSpawnCondition;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	float Priority;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	bool bExcludeFromGlobalAIBudget;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FGameplayTagQuery RequirePlaylistTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TArray<TSoftObjectPtr<UFortAthenaLivingWorldEncounter>> Encounters;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat IsEnabled;

};

