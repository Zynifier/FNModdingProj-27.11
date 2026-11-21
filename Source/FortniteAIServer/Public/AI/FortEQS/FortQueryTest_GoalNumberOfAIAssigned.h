// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalNumberOfAIAssigned.generated.h"

UENUM()
enum class ECountAIAssignedToType : uint8
{
	Goal = 0,
	Actor = 1,
	Assignment = 2,
};

UCLASS(meta=(DisplayName="Goal: Number Of AI Assigned"))
class UFortQueryTest_GoalNumberOfAIAssigned : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CountingOptions")
	ECountAIAssignedToType TypeOfMatchToCount;

};

