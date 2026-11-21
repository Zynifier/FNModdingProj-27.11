// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "Athena/AI/StateTrees/Conditions/StateTreeGameplayTagActorConditions.h"
#include "FortWorldConditionGameplayTagActor.generated.h"

USTRUCT(meta=(DisplayName="(Fortnite) Actor's tags matches Gameplay Tag Container"))
struct FFortWorldConditionGameplayTagActor : public FWorldConditionCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Default", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorContextRef;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer TagContainerToCheck;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EHasMatchingGameplayTagContainerTestType TestType;

};

USTRUCT()
struct FFortWorldConditionGameplayTagActorQueryState
{
	GENERATED_BODY()

};

