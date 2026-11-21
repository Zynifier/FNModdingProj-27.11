// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_PawnHealth.generated.h"

UCLASS(meta=(DisplayName="Goal: Pawn Health"))
class UFortQueryTest_PawnHealth : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Health")
	bool bUsePercentHealth;

};

