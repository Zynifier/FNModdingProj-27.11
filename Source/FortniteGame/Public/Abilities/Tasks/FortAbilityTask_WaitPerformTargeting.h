// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "FortAbilityTask_WaitPerformTargeting.generated.h"

class AActor;
class UFortAbilityTask_WaitPerformTargeting;
class UGameplayAbility;
class UTargetingPreset;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitPerformTargetingDelegate, const FGameplayAbilityTargetDataHandle&, TargetData);

UCLASS()
class UFortAbilityTask_WaitPerformTargeting : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnTargetDataCancelledCallback();

	UFUNCTION()
	void OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Perform Targeting Ability Task", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_WaitPerformTargeting* WaitPerformTargeting(UGameplayAbility* OwningAbility, FName TaskInstanceName, UTargetingPreset* TargetingPreset, bool bForceTargetingOnServer, bool bUseAsyncTargeting);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Perform Filtering Ability Task", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_WaitPerformTargeting* WaitPerformTargetingWithTargets(UGameplayAbility* OwningAbility, FName TaskInstanceName, UTargetingPreset* TargetingPreset, bool bForceTargetingOnServer, bool bUseAsyncTargeting, const TArray<AActor*> InTargets);

	UPROPERTY(BlueprintAssignable)
	FWaitPerformTargetingDelegate Targeted;

	UPROPERTY(BlueprintAssignable)
	FWaitPerformTargetingDelegate Cancelled;

protected:
	UPROPERTY()
	TObjectPtr<UTargetingPreset> TargetingPreset;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> InitialTargets;

	UPROPERTY()
	uint8 bForceTargetingOnServer : 1;

	UPROPERTY()
	uint8 bUseAsyncTargeting : 1;

};

