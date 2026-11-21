// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_PropagateAwareness.generated.h"

class AFortPlayerPawnAthena;
class UFortAthenaAIBotPropagateAwarenessDigestedSkillSet;
class UFortAthenaAIRuntimeParameters_AffiliationBase;
class UFortAthenaAIRuntimeParameters_BehaviorTreeControl;
class UGameplayEffect;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_PropagateAwareness : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Settings", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery AwarenessTagQuery;

	UPROPERTY(EditAnywhere, Category="Settings", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UGameplayEffect> AwarenessGameplayEffectClass;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawnAthena>> AwareAllyPawns;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawnAthena>> AlreadyTestedPawns;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotPropagateAwarenessDigestedSkillSet> PropagateAwarenessSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_BehaviorTreeControl> BehaviorControlsRuntimeParameters;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AffiliationBase> AffiliationRuntimeParameters;

};

