// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortGameRewardOverridesData.generated.h"

USTRUCT(BlueprintType)
struct FGameRewardOverridesInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString MissionName;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString OverrideRewardsTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 LootLevel;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString LootTierGroup;

};

