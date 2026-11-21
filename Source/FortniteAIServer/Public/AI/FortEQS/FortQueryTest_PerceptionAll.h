// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_PerceptionAll.generated.h"

class UAISense;

UCLASS(meta=(DisplayName="Goal: Perception - All"))
class UFortQueryTest_PerceptionAll : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Perception", meta=(ArraySizeEnum="/Script/FortniteAI.ECorePerceptionTypes"))
	FAIDataProviderFloatValue SenseScores[6];

	UPROPERTY(EditAnywhere, Category="Perception")
	TMap<TSubclassOf<UAISense>, FAIDataProviderFloatValue> AdditionalSenseScores;

	UPROPERTY(EditAnywhere, Category="Perception")
	FAIDataProviderFloatValue MinSenseAge;

	UPROPERTY(EditAnywhere, Category="Perception")
	FAIDataProviderFloatValue MaxSenseAge;

};

