// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Components/ActorComponent.h"
#include "FortHealthShieldRegenComponent.generated.h"

class AActor;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FHealthShieldEventReceivedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FHealthShieldGameplayEventReceivedDelegate, FGameplayEventData, Payload);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FHealthShieldInstigatorEventReceivedDelegate, const AActor*, Instigator);

USTRUCT(BlueprintType)
struct FFortHealthShieldRegen_HealthDelegateContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortHealthShieldRegen_HealthDelegateContainer")
	FHealthShieldEventReceivedDelegate OnHealthChanged;

	UPROPERTY(BlueprintReadWrite, Category="FortHealthShieldRegen_HealthDelegateContainer")
	FHealthShieldGameplayEventReceivedDelegate OnDamageReceived;

};

USTRUCT(BlueprintType)
struct FFortHealthShieldRegen_ShieldDelegateContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortHealthShieldRegen_ShieldDelegateContainer")
	FHealthShieldEventReceivedDelegate OnShieldChanged;

	UPROPERTY(BlueprintReadWrite, Category="FortHealthShieldRegen_ShieldDelegateContainer")
	FHealthShieldEventReceivedDelegate OnShieldedDamage;

	UPROPERTY(BlueprintReadWrite, Category="FortHealthShieldRegen_ShieldDelegateContainer")
	FHealthShieldInstigatorEventReceivedDelegate OnShieldDestroyed;

	UPROPERTY(BlueprintReadWrite, Category="FortHealthShieldRegen_ShieldDelegateContainer")
	FHealthShieldGameplayEventReceivedDelegate OnDamageReceived;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortHealthShieldRegenComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool AllowHealthShieldRegen();

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static void AssignHealthShieldRegen_HealthListenerDelegates(const UGameplayAbility* OwningAbility, FFortHealthShieldRegen_HealthDelegateContainer Delegates);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static void AssignHealthShieldRegen_ShieldListenerDelegates(const UGameplayAbility* OwningAbility, FFortHealthShieldRegen_ShieldDelegateContainer Delegates);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static void ClearHealthShieldRegen_HealthListenerDelegates(const UGameplayAbility* OwningAbility);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static void ClearHealthShieldRegen_ShieldListenerDelegates(const UGameplayAbility* OwningAbility);

};

