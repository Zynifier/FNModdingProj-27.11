// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_GameplayTaskBase.h"
#include "GameplayTagContainer.h"
#include "FortBTTask_ExecuteGameplayAbility.generated.h"

UCLASS(MinimalAPI)
class UFortBTTask_ExecuteGameplayAbility : public UBTTask_GameplayTaskBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="!bUseBlackboardTag", EditConditionHides, HideEditConditionToggle="TRUE"))
	FGameplayTagContainer GameplayAbilityTag;

	UPROPERTY(EditAnywhere, Category="Condition")
	FBlackboardKeySelector GameplayAbilityTagBlackboardKey;

	UPROPERTY()
	bool bUseBlackboardTag;

};

