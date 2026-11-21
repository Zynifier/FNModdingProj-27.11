// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_CurieState.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Query Curie State"))
class UFortQueryTest_CurieState : public UEnvQueryTest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Query", meta=(Categories="Curie.State"))
	FGameplayTagQuery CurieStateQuery;

};

