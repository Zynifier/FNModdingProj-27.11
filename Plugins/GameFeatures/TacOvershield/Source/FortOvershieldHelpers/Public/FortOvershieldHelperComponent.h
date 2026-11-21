// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Components/ActorComponent.h"
#include "FortOvershieldHelperComponent.generated.h"

class AActor;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FEventReceivedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FGameplayEventReceivedDelegate, FGameplayEventData, Payload);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FInstigatorEventReceivedDelegate, const AActor*, Instigator);

USTRUCT(BlueprintType)
struct FFortOvershieldDelegateContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortOvershieldDelegateContainer")
	FEventReceivedDelegate OnOvershieldChanged;

	UPROPERTY(BlueprintReadWrite, Category="FortOvershieldDelegateContainer")
	FEventReceivedDelegate OnShieldedDamage;

	UPROPERTY(BlueprintReadWrite, Category="FortOvershieldDelegateContainer")
	FEventReceivedDelegate OnOvershieldedDamage;

	UPROPERTY(BlueprintReadWrite, Category="FortOvershieldDelegateContainer")
	FInstigatorEventReceivedDelegate OnShieldDestroyed;

	UPROPERTY(BlueprintReadWrite, Category="FortOvershieldDelegateContainer")
	FInstigatorEventReceivedDelegate OnOvershieldDestroyed;

	UPROPERTY(BlueprintReadWrite, Category="FortOvershieldDelegateContainer")
	FGameplayEventReceivedDelegate OnDamageReceived;

};

UCLASS()
class UFortOvershieldHelperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static void AssignOvershieldListenerDelegates(UGameplayAbility* OwningAbility, FFortOvershieldDelegateContainer Delegates);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static void ClearOvershieldListenerDelegates(UGameplayAbility* OwningAbility);

};

