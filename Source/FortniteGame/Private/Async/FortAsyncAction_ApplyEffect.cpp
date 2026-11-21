// Copyright Epic Games, Inc. All Rights Reserved.

#include "Async/FortAsyncAction_ApplyEffect.h"

void UFortAsyncAction_ApplyEffectBase::AddTargets(const TArray<FHitResult>& HitResults)
{
}

UFortAsyncAction_ApplyEffectBase* UFortAsyncAction_ApplyEffectBase::ApplyGameplayEffectToHitResultsAsync(UAbilitySystemComponent* OriginatingAbilitySystemComponent, const TArray<FHitResult>& HitResults, TSubclassOf<UGameplayEffect> GameplayEffectClass, int32 GameplayEffectLevel, int32 Stacks, FGameplayEffectContextHandle EffectContext, FScalableFloat MaxTargetsToProcessPerTickCVar)
{
	return nullptr;
}

void UFortAsyncAction_ApplyEffectToAbilityTargetData::AddTargetData(FGameplayAbilityTargetDataHandle& Target)
{
}

UFortAsyncAction_ApplyEffectToAbilityTargetData* UFortAsyncAction_ApplyEffectToAbilityTargetData::ApplyGameplayEffectToTargetDataAsync(UGameplayAbility* OwningAbility, FGameplayAbilityTargetDataHandle& Target, TSubclassOf<UGameplayEffect> GameplayEffectClass, int32 GameplayEffectLevel, int32 Stacks, FScalableFloat MaxTargetsToProcessPerTickCVar)
{
	return nullptr;
}

void UFortAsyncAction_ApplyGameplayEffectToTargetingHandle::AddTargetsFromHandle(const UObject* WorldContextObject, const FTargetingRequestHandle& TargetingHandle)
{
}

UFortAsyncAction_ApplyGameplayEffectToTargetingHandle* UFortAsyncAction_ApplyGameplayEffectToTargetingHandle::ApplyGameplayEffectToTargetingHandleAsync(UAbilitySystemComponent* OriginatingAbilitySystemComponent, const FTargetingRequestHandle& TargetingHandle, TSubclassOf<UGameplayEffect> GameplayEffectClass, int32 GameplayEffectLevel, int32 Stacks, FGameplayEffectContextHandle EffectContext, FScalableFloat MaxTargetsToProcessPerTickCVar)
{
	return nullptr;
}
