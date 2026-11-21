// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "FortQueryTest_GoalPickupFilter.generated.h"

UCLASS(meta=(DisplayName="Goal: Pickup Filter"))
class UFortQueryTest_GoalPickupFilter : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Pickup Filters")
	float MaxLifeTime;

	UPROPERTY(EditDefaultsOnly, Category="Pickup Filters")
	EFortPickupSpawnSource RequiredPickupSpawnSource;

};

