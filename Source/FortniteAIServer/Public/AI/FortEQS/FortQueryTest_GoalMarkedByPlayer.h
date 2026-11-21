// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "GameplayTagContainer.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalMarkedByPlayer.generated.h"

UCLASS(meta=(DisplayName="Goal Marked By Player"))
class UFortQueryTest_GoalMarkedByPlayer : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_GoalMarkedByPlayer", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery OwnerTagQuery;

	UPROPERTY(EditAnywhere, Category="FortQueryTest_GoalMarkedByPlayer")
	FAIDataProviderBoolValue OnlyConverterMarkedTargets;

};

