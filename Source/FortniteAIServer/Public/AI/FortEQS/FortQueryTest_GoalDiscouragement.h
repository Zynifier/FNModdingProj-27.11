// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalDiscouragement.generated.h"

UCLASS(meta=(DisplayName="Goal: Similar Assignment Discouragement"))
class UFortQueryTest_GoalDiscouragement : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CurrentGoal")
	FAIDataProviderBoolValue DisableDiscouragementWhenUndermining;

};

