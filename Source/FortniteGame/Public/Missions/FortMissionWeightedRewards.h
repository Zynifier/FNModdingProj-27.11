// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "FortMissionWeightedRewards.generated.h"

USTRUCT(BlueprintType)
struct FFortMissionWeightedReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionWeightedReward")
	FName LootTierGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionWeightedReward")
	FSlateBrush LootIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionWeightedReward")
	float Weight;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortMissionWeightedRewards : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Difficulty and Rewards")
	TArray<FFortMissionWeightedReward> Rewards;

};

