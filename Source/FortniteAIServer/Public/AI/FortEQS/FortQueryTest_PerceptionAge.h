// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "AI/FortAIPerceptionComponent.h"
#include "FortQueryTest_PerceptionAge.generated.h"

class UAISense;

UCLASS()
class UFortQueryTest_PerceptionAge : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Perception")
	TEnumAsByte<ECorePerceptionTypes::Type> Sense;

	UPROPERTY()
	TSubclassOf<UAISense> SenseClass;

};

