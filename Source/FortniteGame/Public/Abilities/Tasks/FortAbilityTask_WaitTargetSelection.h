// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "FortAbilityTask_WaitTargetSelection.generated.h"

class UFortAbilityTask_WaitTargetSelection;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWaitTargetSelectionDelegate, const FGameplayAbilityTargetDataHandle&, TargetData, FGameplayTag, ApplicationTag);

UCLASS()
class UFortAbilityTask_WaitTargetSelection : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnTargetDataCancelledCallback();

	UFUNCTION()
	void OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Do Target Selection", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_WaitTargetSelection* WaitTargetSelection(UGameplayAbility* OwningAbility, FName TaskInstanceName, FGameplayTag InApplicationTag, bool bForceTargetingOnServer);

	UPROPERTY(BlueprintAssignable)
	FWaitTargetSelectionDelegate Targeted;

	UPROPERTY(BlueprintAssignable)
	FWaitTargetSelectionDelegate Cancelled;

protected:
	UPROPERTY()
	TEnumAsByte<EGameplayTargetingConfirmation::Type> ConfirmationType;

	UPROPERTY()
	bool bForceTargetingOnServer;

	UPROPERTY()
	FGameplayTag InstantTargetTag;

};

