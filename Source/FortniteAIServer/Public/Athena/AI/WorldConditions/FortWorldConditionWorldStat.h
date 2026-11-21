// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionBase.h"
#include "FortWorldConditionWorldStat.generated.h"

class UFortWorldStatDefinition;

USTRUCT(meta=(DisplayName="(Fortnite) World Stat"))
struct FFortWorldConditionWorldStat : public FWorldConditionCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortWorldConditionWorldStat")
	TObjectPtr<UFortWorldStatDefinition> WorldStatDefinition;

	UPROPERTY(EditAnywhere, Category="FortWorldConditionWorldStat")
	uint32 Value;

};

USTRUCT()
struct FFortWorldConditionWorldStatState
{
	GENERATED_BODY()

};

