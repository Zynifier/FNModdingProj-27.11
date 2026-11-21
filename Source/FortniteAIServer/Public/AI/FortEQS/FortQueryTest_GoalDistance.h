// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/Tests/EnvQueryTest_Distance.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalDistance.generated.h"

class UEnvQueryContext;

UENUM()
enum class EDistanceMode : uint8
{
	DistItemToContext = 0,
	DistItemGoalActorToContext = 1,
	DistItemToItemGoalActor = 2,
};

UCLASS()
class UFortQueryTest_GoalDistance : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Distance")
	EDistanceMode DistanceMode;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TSubclassOf<UEnvQueryContext> DistanceTo;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TEnumAsByte<EEnvTestDistance::Type> TestMode;

};

