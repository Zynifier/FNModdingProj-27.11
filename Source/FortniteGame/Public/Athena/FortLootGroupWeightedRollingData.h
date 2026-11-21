// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortLootGroupWeightedRollingData.generated.h"

USTRUCT()
struct FFortLootGroupWeightData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Loot Group", meta=(Categories="LootGroup"))
	FScalableFloat Weight;

	UPROPERTY(EditAnywhere, Category="Loot Group", meta=(Categories="LootGroup"))
	FGameplayTag LootRowRequiredTag;

};

UCLASS()
class UFortLootGroupWeightedRollingData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Loot Group")
	FScalableFloat MinGroupsToPick;

	UPROPERTY(EditAnywhere, Category="Loot Group")
	FScalableFloat MaxGroupsToPick;

	UPROPERTY(EditAnywhere, Category="Loot Group", meta=(TitleProperty="LootRowRequiredTag"))
	TArray<FFortLootGroupWeightData> LootGroupWeightData;

};

