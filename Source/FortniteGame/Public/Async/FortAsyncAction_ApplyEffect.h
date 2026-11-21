// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Async/AbilityAsync.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Engine/HitResult.h"
#include "GameplayEffectTypes.h"
#include "ScalableFloat.h"
#include "Types/TargetingSystemTypes.h"
#include "FortAsyncAction_ApplyEffect.generated.h"

class UAbilitySystemComponent;
class UFortAsyncAction_ApplyEffectBase;
class UFortAsyncAction_ApplyEffectToAbilityTargetData;
class UFortAsyncAction_ApplyGameplayEffectToTargetingHandle;
class UGameplayAbility;
class UGameplayEffect;
class UObject;

UCLASS()
class UFortAsyncAction_ApplyEffectBase : public UAbilityAsync
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks")
	void AddTargets(const TArray<FHitResult>& HitResults);

protected:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE"))
	static UFortAsyncAction_ApplyEffectBase* ApplyGameplayEffectToHitResultsAsync(UAbilitySystemComponent* OriginatingAbilitySystemComponent, const TArray<FHitResult>& HitResults, TSubclassOf<UGameplayEffect> GameplayEffectClass, int32 GameplayEffectLevel, int32 Stacks, FGameplayEffectContextHandle EffectContext, FScalableFloat MaxTargetsToProcessPerTickCVar);

	UPROPERTY(Transient)
	FGameplayEffectSpecHandle CachedEffectSpecToApply;

	UPROPERTY(Transient)
	TArray<FHitResult> HitResultArray;

};

UCLASS()
class UFortAsyncAction_ApplyEffectToAbilityTargetData : public UFortAsyncAction_ApplyEffectBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	void AddTargetData(UPARAM(ref) FGameplayAbilityTargetDataHandle& Target);

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static UFortAsyncAction_ApplyEffectToAbilityTargetData* ApplyGameplayEffectToTargetDataAsync(UGameplayAbility* OwningAbility, UPARAM(ref) FGameplayAbilityTargetDataHandle& Target, TSubclassOf<UGameplayEffect> GameplayEffectClass, int32 GameplayEffectLevel, int32 Stacks, FScalableFloat MaxTargetsToProcessPerTickCVar);

};

UCLASS()
class UFortAsyncAction_ApplyGameplayEffectToTargetingHandle : public UFortAsyncAction_ApplyEffectBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(WorldContext="WorldContextObject"))
	void AddTargetsFromHandle(const UObject* WorldContextObject, const FTargetingRequestHandle& TargetingHandle);

	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE"))
	static UFortAsyncAction_ApplyGameplayEffectToTargetingHandle* ApplyGameplayEffectToTargetingHandleAsync(UAbilitySystemComponent* OriginatingAbilitySystemComponent, const FTargetingRequestHandle& TargetingHandle, TSubclassOf<UGameplayEffect> GameplayEffectClass, int32 GameplayEffectLevel, int32 Stacks, FGameplayEffectContextHandle EffectContext, FScalableFloat MaxTargetsToProcessPerTickCVar);

};

