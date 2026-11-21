// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "WorldConditionQuery.h"
#include "WorldConditionSchema.h"
#include "FortAthenaWorldConditionStateTreeTask.generated.h"

class AActor;

USTRUCT()
struct FFortAthenaWorldConditionInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> ActorA;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> ActorB;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> ActorC;

	UPROPERTY(EditAnywhere, Category="Output")
	bool bOutResult;

	UPROPERTY()
	FWorldConditionQueryState QueryState;

};

USTRUCT(meta=(DisplayName="(Fortnite) Use WorldCondition"))
struct FFortAthenaWorldConditionInstanceDataStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="SmartObject")
	FWorldConditionQueryDefinition Conditions;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag StateTreeEventTag;

};

UCLASS()
class UFortStateTreeConditionSchema : public UWorldConditionSchema
{
	GENERATED_BODY()

};

