// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAbilitySystemBlueprintLibrary.h"

void UFortAbilitySystemBlueprintLibrary::AssignActiveGameplayEffectTagSetByCallerMagnitude(FActiveGameplayEffectHandle ActiveHandle, FGameplayTag DataTag, float Magnitude)
{
}

void UFortAbilitySystemBlueprintLibrary::EffectContextSetCritical(FGameplayEffectContextHandle EffectContext, bool bInCritical)
{
}

TArray<AActor*> UFortAbilitySystemBlueprintLibrary::FilterTargetsInCone(const AActor* SourceActor, const TArray<AActor*>& ActorsToCheck, const FVector& ConeStart, const FVector& ConeEnd, const float ConeRadius, FGameplayTagContainer ExcludeFromObstructionTags, const bool bShouldCheckLos, const float UseActorCapsuleDotCalculationScalar, const float DebugDrawDuration)
{
	return TArray<AActor*>();
}

FString UFortAbilitySystemBlueprintLibrary::GetAbilitySystemDebugInfo(AActor* DebugActor)
{
	return FString();
}

float UFortAbilitySystemBlueprintLibrary::GetCooldownTimeRemaining(AActor* Actor, FGameplayTagContainer CooldownTags)
{
	return float();
}

void UFortAbilitySystemBlueprintLibrary::GetCooldownTimeRemainingAndDuration(AActor* Actor, FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration)
{
}

UFortAbilitySystemComponent* UFortAbilitySystemBlueprintLibrary::GetFortAbilitySystemComponent(AActor* Actor)
{
	return nullptr;
}

FGameplayAbilitySpecHandle UFortAbilitySystemBlueprintLibrary::GrantAndActivateAbilityOnSelf(UAbilitySystemComponent* AbilitySystem, const TSubclassOf<UGameplayAbility>& AbilityToGrant, UObject* ContextObject)
{
	return FGameplayAbilitySpecHandle();
}

FGameplayAbilitySpecHandle UFortAbilitySystemBlueprintLibrary::GrantAndActivateAbilityOnSelfWithParams(UAbilitySystemComponent* AbilitySystem, const TSubclassOf<UGameplayAbility>& AbilityToGrant, UObject* ContextObject, const FGameplayEventData GameplayEventData)
{
	return FGameplayAbilitySpecHandle();
}

bool UFortAbilitySystemBlueprintLibrary::IsCooldownTagsActive(AActor* Actor, FGameplayTagContainer CooldownTags)
{
	return false;
}

bool UFortAbilitySystemBlueprintLibrary::IsGameplayCueActive(AActor* Actor, const FGameplayTag& GameplayCueTag)
{
	return false;
}

bool UFortAbilitySystemBlueprintLibrary::IsGameplayEffectContextAbilityChildOf(const FGameplayEffectContextHandle& GameplayEffectContextHandle, const TSubclassOf<UGameplayAbility> AbilityClass)
{
	return false;
}

bool UFortAbilitySystemBlueprintLibrary::IsGameplayEffectContextAbilityInstance(const FGameplayEffectContextHandle& GameplayEffectContextHandle, const UGameplayAbility* AbilityInstance)
{
	return false;
}
