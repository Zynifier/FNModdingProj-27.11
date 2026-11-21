// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "WorldConditionQuery.h"
#include "WorldConditionSchema.h"
#include "FortAthenaBTService_WorldCondition.generated.h"

class AAIController;
class AActor;

UCLASS()
class UFortAthenaBTService_WorldCondition : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="WC")
	FWorldConditionQueryDefinition Conditions;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ConditionsResultName;

	UPROPERTY()
	FWorldConditionQueryState QueryState;

	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedOwnerController;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CachedOwnerPawn;

};

UCLASS()
class UFortBTWorldConditionSchema : public UWorldConditionSchema
{
	GENERATED_BODY()

};

