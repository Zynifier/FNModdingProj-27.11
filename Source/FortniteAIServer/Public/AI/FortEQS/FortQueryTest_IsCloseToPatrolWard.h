// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "AI/FortPatrolWardInterface.h"
#include "FortQueryTest_IsCloseToPatrolWard.generated.h"

UCLASS()
class UFortQueryTest_IsCloseToPatrolWard : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PatrolWard")
	EWardAffectType WardEffectTypeFilter;

};

