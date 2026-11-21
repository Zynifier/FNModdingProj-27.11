// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility.h"
#include "Abilities/Tasks/FortAbilityTask_WaitTargetSelection.h"
#include "FortAbilityTask_PlayAnimWaitTarget.generated.h"

class UAnimMontage;
class UFortAbilityTask_PlayAnimWaitTarget;
class UGameplayAbility;
enum class EFortGameplayAbilityMontageSectionToPlay : uint8;
enum class EFortSharedAnimationState : uint8;

UCLASS()
class UFortAbilityTask_PlayAnimWaitTarget : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnTargetDataCancelledCallback();

	UFUNCTION()
	void OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Play Anim and Wait for Trigger", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_PlayAnimWaitTarget* PlayAnimWaitTarget(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, EFortSharedAnimationState AnimState, EFortGameplayAbilityMontageSectionToPlay SectionToPlay = EFortGameplayAbilityMontageSectionToPlay::FirstSection, FName OverrideSection = NAME_None);

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_PlayAnimWaitTarget* PlayAnimWithMontageInfoAndWaitForTrigger(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FFortGameplayAbilityMontageInfo& MontageInfo, EFortSharedAnimationState AnimState);

	UPROPERTY(BlueprintAssignable)
	FWaitTargetSelectionDelegate Triggered;

	UPROPERTY(BlueprintAssignable)
	FWaitTargetSelectionDelegate Cancelled;

	UPROPERTY(BlueprintAssignable)
	FWaitTargetSelectionDelegate Completed;

protected:
	UPROPERTY()
	FFortGameplayAbilityMontageInfo MontageInfo;

};

