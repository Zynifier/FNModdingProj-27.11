// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "FortAbilityTask_SetNextMontageSectionAndWait.generated.h"

class UAnimMontage;
class UFortAbilityTask_SetNextMontageSectionAndWait;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetNextMontageSectionSimpleDelegate);

UCLASS()
class UFortAbilityTask_SetNextMontageSectionAndWait : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", DisplayName="Set Next Montage Section and Wait", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_SetNextMontageSectionAndWait* SetNextMontageSectionAndWait(UGameplayAbility* OwningAbility, UAnimMontage* PlayingMontage, FName NextMontageSection);

	UPROPERTY(BlueprintAssignable)
	FSetNextMontageSectionSimpleDelegate OnComplete;

	UPROPERTY(BlueprintAssignable)
	FSetNextMontageSectionSimpleDelegate OnInterrupted;

};

