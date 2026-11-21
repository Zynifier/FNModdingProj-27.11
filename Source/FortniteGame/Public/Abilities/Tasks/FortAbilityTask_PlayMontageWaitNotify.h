// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayTagContainer.h"
#include "FortAbilityTask_PlayMontageWaitNotify.generated.h"

class UAnimMontage;
class UAnimSequenceBase;
class UFortAbilityTask_PlayMontageWaitNotify;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayMontageWaitNotifyDelegate, FGameplayTag, NotifyTag);

UCLASS()
class UFortAbilityTask_PlayMontageWaitNotify : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static UFortAbilityTask_PlayMontageWaitNotify* PlayMontageAndWaitNotify(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, float PlayRate = 1.000000f, FName StartSection = NAME_None, bool bStopWhenAbilityEnds = true, float RootMotionTranslationScale = 1.000000f);

	UPROPERTY(BlueprintAssignable)
	FPlayMontageWaitNotifyDelegate OnCompleted;

	UPROPERTY(BlueprintAssignable)
	FPlayMontageWaitNotifyDelegate OnBlendOut;

	UPROPERTY(BlueprintAssignable)
	FPlayMontageWaitNotifyDelegate OnInterrupted;

	UPROPERTY(BlueprintAssignable)
	FPlayMontageWaitNotifyDelegate OnCancelled;

	UPROPERTY(BlueprintAssignable)
	FPlayMontageWaitNotifyDelegate OnNotifyBegin;

	UPROPERTY(BlueprintAssignable)
	FPlayMontageWaitNotifyDelegate OnNotifyEnd;

protected:
	UFUNCTION()
	virtual void OnAbilityCancelled();

	UFUNCTION()
	virtual void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	virtual void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnMontageNotifyBegin(UAnimSequenceBase* Animation, FGameplayTag NotifyTag);

	UFUNCTION()
	void OnMontageNotifyEnd(UAnimSequenceBase* Animation, FGameplayTag NotifyTag);

	UPROPERTY()
	TObjectPtr<UAnimMontage> MontageToPlay;

};

