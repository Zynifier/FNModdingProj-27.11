// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistentTypes.h"
#include "FortRewardReport.generated.h"

USTRUCT()
struct FFortRewardReport
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText MissionName;

	UPROPERTY()
	FText TheaterName;

	UPROPERTY()
	FText Difficulty;

	UPROPERTY()
	float DifficultyValue;

	UPROPERTY()
	TArray<FFortRewardActivity> RewardActivities;

	UPROPERTY()
	bool bIsFinalized;

};

