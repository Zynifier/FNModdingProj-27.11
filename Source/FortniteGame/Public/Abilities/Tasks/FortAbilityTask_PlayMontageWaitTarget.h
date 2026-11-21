// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortCharacterPartMontageInfo.h"
#include "Abilities/FortGameplayAbility.h"
#include "Abilities/Tasks/FortAbilityTask_WaitTargetSelection.h"
#include "FortAbilityTask_PlayMontageWaitTarget.generated.h"

class UAnimMontage;
class UFortAbilityTask_PlayMontageWaitTarget;
class UGameplayAbility;
enum class EFortAbilityTargetDataPolicy : uint8;
enum class EFortGameplayAbilityMontageSectionToPlay : uint8;

UENUM()
enum class EFortAbilityTargetDataPolicy : uint8
{
	// Create target data on client and replicate to server (more forgiving detection, use for aiming)

	ReplicateToServer = 0,
	// Create target data directly on server (more resistant to exploits, use for presets like "affects owner")

	SimulateOnServer = 1,
};

UCLASS()
class UFortAbilityTask_PlayMontageWaitTarget : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability | Tasks")
	void EnableScalingWithRateOfFire();

	UFUNCTION()
	void OnTargetDataCancelledCallback();

	UFUNCTION()
	void OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_PlayMontageWaitTarget* PlayMontageInfoAndWaitForTrigger(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FFortGameplayAbilityMontageInfo& MontageInfo, EFortAbilityTargetDataPolicy TargetDataPolicy = EFortAbilityTargetDataPolicy::ReplicateToServer);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Play Montage and Wait for Trigger", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_PlayMontageWaitTarget* PlayMontageWaitTarget(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, float AnimPlayRate = 1.000000f, EFortGameplayAbilityMontageSectionToPlay SectionToPlay = EFortGameplayAbilityMontageSectionToPlay::FirstSection, FName OverrideSection = NAME_None, float AnimRootMotionTranslationScale = 1.000000f, EFortAbilityTargetDataPolicy TargetDataPolicy = EFortAbilityTargetDataPolicy::ReplicateToServer);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Play Montage With Character Parts and Wait for Trigger", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_PlayMontageWaitTarget* PlayMontageWithCharPartsWait(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, TArray<FFortCharacterPartMontageInfo> CharacterPartMontages, float AnimPlayRate = 1.000000f, EFortGameplayAbilityMontageSectionToPlay SectionToPlay = EFortGameplayAbilityMontageSectionToPlay::FirstSection, FName OverrideSection = NAME_None, float AnimRootMotionTranslationScale = 1.000000f, EFortAbilityTargetDataPolicy TargetDataPolicy = EFortAbilityTargetDataPolicy::ReplicateToServer);

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

