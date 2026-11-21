// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "FortAbilityTask_WaitAnimBPOverride.generated.h"

class AFortPlayerPawn;
class UAnimInstance;
class UFortAbilityTask_WaitAnimBPOverride;
class UFortGadgetItemDefinition;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimBPReady);

UCLASS()
class UFortAbilityTask_WaitAnimBPOverride : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnFinishedCharacterCustomizationCallback(AFortPlayerPawn* InPawn);

	UFUNCTION()
	void OnPawnAnimBPCallback();

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="Wait AnimBP Override Ready", HidePin="OwningAbility"))
	static UFortAbilityTask_WaitAnimBPOverride* WaitAnimBPOverrideReady(UGameplayAbility* OwningAbility, TSoftClassPtr<UAnimInstance> AnimInstance, TSoftObjectPtr<UFortGadgetItemDefinition> GadgetItemDef);

	UPROPERTY(BlueprintAssignable)
	FOnAnimBPReady OnReady;

	UPROPERTY()
	TSoftClassPtr<UAnimInstance> AnimInstanceWaitingFor;

	UPROPERTY()
	TSoftObjectPtr<UFortGadgetItemDefinition> GadgetItemDefWaitingFor;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

};

