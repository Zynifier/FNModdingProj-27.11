// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GameplayTagContainer.h"
#include "FortBTDecorator_QueryGameplayAbility.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortBTDecorator_QueryGameplayAbility : public UBTDecorator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="!bUseBlackboardTag", EditConditionHides, HideEditConditionToggle="TRUE"))
	FGameplayTagContainer GameplayAbilityTag;

	UPROPERTY(EditAnywhere, Category="Condition")
	FBlackboardKeySelector GameplayAbilityTagBlackboardKey;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="bUseTarget"))
	FBlackboardKeySelector Target;

	UPROPERTY(EditAnywhere, Category="Condition")
	FGameplayTagContainer ActiveAbilityTagsToSkipTesting;

	UPROPERTY()
	bool bUseTarget;

	UPROPERTY()
	bool bUseBlackboardTag;

};

