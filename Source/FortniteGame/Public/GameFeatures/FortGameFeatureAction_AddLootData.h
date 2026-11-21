// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "STW/GameDataSTW.h"
#include "FortGameFeatureAction_AddLootData.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Save the World Loot Data"))
class UFortGameFeatureAction_AddLootData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Loot Data")
	TArray<FTagRestrictedTable> LootTierData;

	UPROPERTY(EditAnywhere, Category="Loot Data")
	TArray<FTagRestrictedTable> LootPackageData;

};

