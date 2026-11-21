// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_CanHitWithGameplayAbility.generated.h"

class UEnvQueryContext;

UCLASS()
class UFortQueryTest_CanHitWithGameplayAbility : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UEnvQueryContext> AIsUsingAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UEnvQueryContext> AbilityTargets;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	FGameplayTagContainer GameplayAbilityTag;

};

