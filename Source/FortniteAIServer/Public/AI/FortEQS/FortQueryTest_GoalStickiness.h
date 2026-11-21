// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalStickiness.generated.h"

UCLASS()
class UFortQueryTest_GoalStickiness : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0"))
	FAIDataProviderFloatValue StartValueForGoal;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0"))
	FAIDataProviderFloatValue EndValueForGoal;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue TimeBeforeValueLerp;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue ValueLerpDuration;

	UPROPERTY(EditAnywhere, Category="CurrentGoal")
	FAIDataProviderBoolValue ApplyStickinessToAllGoalsWithSameActor;

};

