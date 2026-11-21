// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "FortAbilityTask_AutoAimConditionFailed.generated.h"

class AFortPawn;
class UFortAbilityTask_AutoAimConditionFailed;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAutoAimConditionFailed);

UCLASS()
class UFortAbilityTask_AutoAimConditionFailed : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="AutoAimConditionFailed", HidePin="OwningAbility"))
	static UFortAbilityTask_AutoAimConditionFailed* CreateAutoAimConditionFailed(UGameplayAbility* OwningAbility);

	UPROPERTY(BlueprintAssignable)
	FAutoAimConditionFailed OnAutoAimConditionFailed;

protected:
	UPROPERTY()
	TObjectPtr<AFortPawn> CachedPawn;

};

