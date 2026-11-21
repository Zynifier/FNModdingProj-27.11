// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GameplayTagContainer.h"
#include "FortBTDecorator_GameplayAbility_HasGameplayAbility.generated.h"

UCLASS(MinimalAPI)
class UFortBTDecorator_GameplayAbility_HasGameplayAbility : public UBTDecorator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition", meta=(DisplayName="AbilityOwningActor", ToolTips="Which Actor (from the blackboard) should be checked for this gameplay tag query?"))
	FBlackboardKeySelector AbilityOwningActorKey;

	UPROPERTY(EditAnywhere, Category="Condition", meta=(EditCondition="!bUseBlackboardTag", EditConditionHides, HideEditConditionToggle="TRUE"))
	FGameplayTagContainer GameplayAbilityTag;

	UPROPERTY(EditAnywhere, Category="Condition")
	FBlackboardKeySelector GameplayAbilityTagBlackboardKey;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bOnlyTestActiveAbility;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bUseBlackboardTag;
#endif

};

