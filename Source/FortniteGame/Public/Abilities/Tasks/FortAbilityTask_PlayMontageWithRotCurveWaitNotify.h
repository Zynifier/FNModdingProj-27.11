// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility_AITurnTransition.h"
#include "Abilities/Tasks/FortAbilityTask_PlayMontageWaitNotify.h"
#include "FortAbilityTask_PlayMontageWithRotCurveWaitNotify.generated.h"

class UAnimSequenceBase;
class UFortAbilityTask_PlayMontageWithRotCurveWaitNotify;
class UGameplayAbility;

UCLASS(NotPlaceable)
class UFortAbilityTask_PlayMontageWithRotCurveWaitNotify : public UFortAbilityTask_PlayMontageWaitNotify
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability | Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static UFortAbilityTask_PlayMontageWithRotCurveWaitNotify* PlayMontageWithRotCurveAndWaitNotify(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FPickedTurnTransitionData InData, const bool bCanUseDesiredRotationAsFallback = false);

protected:
	UFUNCTION()
	void OnNotifyBegin(UAnimSequenceBase* Animation, FGameplayTag NotifyTag);

};

