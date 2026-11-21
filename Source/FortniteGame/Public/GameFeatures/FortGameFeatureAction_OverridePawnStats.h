// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "FortGameFeatureAction_OverridePawnStats.generated.h"

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Override Pawn Stats"))
class UFortGameFeatureAction_OverridePawnStats : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PawnStats")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="PawnStats", meta=(DisplayName="Override Pawn Stats"))
	FDataTableRowHandle OverridePawnStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="PawnStats")
	int32 Priority;

};

