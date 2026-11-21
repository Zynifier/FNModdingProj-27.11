// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/Tests/EnvQueryTest_PathfindingBatch.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_PathfindingBatch.generated.h"

UCLASS(meta=(DisplayName="Fort Pathfinding Batch"))
class UFortQueryTest_PathfindingBatch : public UEnvQueryTest_PathfindingBatch
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Pathfinding", meta=(Categories="NavFilter"))
	FGameplayTag NavFilterTag;

};

