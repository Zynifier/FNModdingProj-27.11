// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "FortAbilityTask_TargetSelectionContinuous.generated.h"

class UFortAbilityTask_TargetSelectionContinuous;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetSelectionContinuousDelegate, const FGameplayAbilityTargetDataHandle&, TargetData, FGameplayTag, ApplicationTag);

UCLASS()
class UFortAbilityTask_TargetSelectionContinuous : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static UFortAbilityTask_TargetSelectionContinuous* DoTargetSelectionContinuous(UGameplayAbility* OwningAbility, FName TaskInstanceName, FGameplayTag ApplicationTag, bool bStopAtFirstTarget = true);

	UPROPERTY(BlueprintAssignable)
	FTargetSelectionContinuousDelegate Targeted;

	UPROPERTY(BlueprintAssignable)
	FTargetSelectionContinuousDelegate Cancelled;

};

