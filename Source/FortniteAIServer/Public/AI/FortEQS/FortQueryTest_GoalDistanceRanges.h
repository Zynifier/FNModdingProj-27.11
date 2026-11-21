// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Tests/EnvQueryTest_Distance.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "AI/FortEQS/FortQueryTest_GoalDistance.h"
#include "FortQueryTest_GoalDistanceRanges.generated.h"

class UCurveFloat;
class UEnvQueryContext;

USTRUCT()
struct FGoalDistanceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIgnoreScreeningDistance;

	UPROPERTY(EditDefaultsOnly, Category="GoalDistanceData", meta=(EditCondition="!bIgnoreScreeningDistance"))
	FAIDataProviderFloatValue ScreeningTestMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TSoftObjectPtr<UCurveFloat> TestScoreCurve;

	UPROPERTY(EditDefaultsOnly, Category="GoalDistanceData", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0.0"))
	FAIDataProviderFloatValue CurveDistanceScale;

};

UCLASS(HideCategories=("TestBS"))
class UFortQueryTest_GoalDistanceRanges : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Distance")
	EDistanceMode DistanceMode;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TSubclassOf<UEnvQueryContext> DistanceTo;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TEnumAsByte<EEnvTestDistance::Type> ScreeningTestMode;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TEnumAsByte<EEnvTestDistance::Type> TestMode;

	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TArray<FGoalDistanceData> GoalDistanceDataRanges;

};

