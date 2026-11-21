// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "Athena/AI/StateTrees/Tasks/FortAthenaStateTreeTaskTypes.h"
#include "FortAthenaToggleGameplayEffectStateTreeTask.generated.h"

class AActor;
class UGameplayEffect;

USTRUCT(meta=(DisplayName="(Fortnite) Toggle GameplayEffects"))
struct FFortAthenaToggleGameplayEffectStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode AddExecutionMode;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode RemoveExecutionMode;

};

USTRUCT()
struct FFortAthenaToggleGameplayEffectStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectClassesToAdd;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bAutomaticallyRemoveAddedEffectsOnExit;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectClassesToRemove;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer GameplayEffectsByTagsToRemove;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer GameplayEffectsBySourceTagsToRemove;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer GameplayEffectsByAppliedTagsToRemove;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer GameplayEffectsByGrantedTagsToRemove;

};

