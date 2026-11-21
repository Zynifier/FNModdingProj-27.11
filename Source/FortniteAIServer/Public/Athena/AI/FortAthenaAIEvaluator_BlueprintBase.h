// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIEvaluator_BlueprintBase.generated.h"

class UAbilitySystemComponent;
class UBehaviorTreeComponent;

USTRUCT()
struct FGameplayAbilityEvaluatorModule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameplayAbilityEvaluatorModule")
	FGameplayTagContainer GameplayAbilityTag;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> CachedAbilitySystemComponent;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_BlueprintBase : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool EvaluateOngoingConditions(UBehaviorTreeComponent* OwnerComp) const;

	UFUNCTION(BlueprintNativeEvent)
	bool EvaluateStartingConditions(UBehaviorTreeComponent* OwnerComp) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnter(UBehaviorTreeComponent* OwnerComp);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExit(UBehaviorTreeComponent* OwnerComp);

	UPROPERTY(EditAnywhere, Category="ItemEvaluator")
	bool bBlockWeaponActions;

	UPROPERTY(EditAnywhere, Category="GameplayAbility")
	bool bGameplayAbilityEvaluator;

	UPROPERTY(EditAnywhere, Category="GameplayAbility", meta=(EditCondition="bGameplayAbilityEvaluator", EditConditionHides))
	FGameplayAbilityEvaluatorModule GameplayAbilityEvaluatorModule;

};

