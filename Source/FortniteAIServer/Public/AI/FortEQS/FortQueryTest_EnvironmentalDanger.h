// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_EnvironmentalDanger.generated.h"

UCLASS()
class UFortQueryTest_EnvironmentalDanger : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_EnvironmentalDanger")
	bool bUse3DBoundsCheck;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_EnvironmentalDanger")
	FGameplayTag DangerSourceActorRegistryTag;

};

