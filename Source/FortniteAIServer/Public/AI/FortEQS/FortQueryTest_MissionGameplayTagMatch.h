// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_MissionGameplayTagMatch.generated.h"

UCLASS(meta=(DisplayName="Mission - Gameplay Tag Match"))
class UFortQueryTest_MissionGameplayTagMatch : public UEnvQueryTest
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortQueryTest_MissionGameplayTagMatch")
	FGameplayTagQuery MissionPlacementActorTagQuery;

	UPROPERTY(EditAnywhere, Category="FortQueryTest_MissionGameplayTagMatch")
	FGameplayTagContainer GameplayTagsToMatch;

};

