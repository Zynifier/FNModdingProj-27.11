// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Abilities/FortGameplayAbility.h"
#include "Abilities/GameplayAbilityRepSharedAnim.h"
#include "FortAbilityTask_PlayAnimAndWait.generated.h"

class UAnimMontage;
class UFortAbilityTask_PlayAnimAndWait;
class UGameplayAbility;
enum class EFortSharedAnimationState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimWaitSimpleDelegate);

UCLASS()
class UFortAbilityTask_PlayAnimAndWait : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="PlayAnimAndWait", HidePin="OwningAbility"))
	static UFortAbilityTask_PlayAnimAndWait* CreatePlayAnimAndWaitProxy(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FFortGameplayAbilityMontageInfo& PlayMontageInfo, EFortSharedAnimationState AnimState, bool bStopWhenAbilityEnds = true);

	UFUNCTION()
	void OnAnimBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnAnimInterrupted();

	UPROPERTY(BlueprintAssignable)
	FAnimWaitSimpleDelegate OnCompleted;

	UPROPERTY(BlueprintAssignable)
	FAnimWaitSimpleDelegate OnBlendOut;

	UPROPERTY(BlueprintAssignable)
	FAnimWaitSimpleDelegate OnInterrupted;

	UPROPERTY(BlueprintAssignable)
	FAnimWaitSimpleDelegate OnCancelled;

protected:
	UPROPERTY()
	FFortGameplayAbilityMontageInfo MontageInfo;

	UPROPERTY()
	EFortSharedAnimationState AnimState;

	UPROPERTY()
	bool bStopWhenAbilityEnds;

};

