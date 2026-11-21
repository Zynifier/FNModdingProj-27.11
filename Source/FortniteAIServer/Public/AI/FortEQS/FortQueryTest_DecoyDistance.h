// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_DecoyDistance.generated.h"

class UEnvQueryContext;

UCLASS(HideCategories=("Filter"))
class UFortQueryTest_DecoyDistance : public UEnvQueryTest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Distance")
	TSubclassOf<UEnvQueryContext> DistanceTo;

};

