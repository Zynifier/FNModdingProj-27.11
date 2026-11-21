// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayAbilitySpecHandle.h"
#include "Misc/Guid.h"
#include "FortAbilitySetHandle.generated.h"

class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FFortAbilitySetHandle
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;

	UPROPERTY(Transient)
	TArray<FGameplayAbilitySpecHandle> GrantedAbilityHandles;

	UPROPERTY(Transient)
	TArray<FActiveGameplayEffectHandle> AppliedEffectHandles;

	UPROPERTY(Transient)
	TArray<FGuid> ItemGuidsForAdditionalItems;

};

