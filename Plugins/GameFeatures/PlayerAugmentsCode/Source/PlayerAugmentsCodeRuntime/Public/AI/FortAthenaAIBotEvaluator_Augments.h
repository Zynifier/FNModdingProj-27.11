// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Augments.generated.h"

class UBehaviorTree;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Augments : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Node")
	FGameplayTag InjectionTag;

	UPROPERTY(EditAnywhere, Category="Node")
	TObjectPtr<UBehaviorTree> BehaviorAsset;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AugmentStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AugmentItemKeyName;

};

