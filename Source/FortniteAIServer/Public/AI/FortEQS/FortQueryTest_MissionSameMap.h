// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_MissionSameMap.generated.h"

UCLASS(meta=(DisplayName="Mission - Same Map"))
class UFortQueryTest_MissionSameMap : public UEnvQueryTest
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortQueryTest_MissionSameMap")
	FGameplayTagQuery MissionPlacementActorTagQuery;

};

