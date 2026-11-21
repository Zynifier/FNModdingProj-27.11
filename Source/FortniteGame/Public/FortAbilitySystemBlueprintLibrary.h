// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortAbilitySystemBlueprintLibrary.generated.h"

class AActor;
class UAbilitySystemComponent;
class UFortAbilitySystemComponent;
class UGameplayAbility;
class UObject;

UCLASS(meta=(ScriptName="FortAbilitySystemLibrary"))
class UFortAbilitySystemBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability | GameplayEffect")
	static void AssignActiveGameplayEffectTagSetByCallerMagnitude(FActiveGameplayEffectHandle ActiveHandle, FGameplayTag DataTag, float Magnitude);

	UFUNCTION(BlueprintCallable, Category="Ability | EffectContext", meta=(DisplayName="SetCritical"))
	static void EffectContextSetCritical(FGameplayEffectContextHandle EffectContext, bool bInCritical);

	UFUNCTION(BlueprintCallable, Category="Ability | Target Filter")
	static TArray<AActor*> FilterTargetsInCone(const AActor* SourceActor, const TArray<AActor*>& ActorsToCheck, const FVector& ConeStart, const FVector& ConeEnd, const float ConeRadius, FGameplayTagContainer ExcludeFromObstructionTags, const bool bShouldCheckLos = true, const float UseActorCapsuleDotCalculationScalar = 3.000000f, const float DebugDrawDuration = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Ability | Debug")
	static FString GetAbilitySystemDebugInfo(AActor* DebugActor);

	UFUNCTION(BlueprintCallable, Category="Ability | Cooldowns", meta=(DefaultToSelf="Actor"))
	static float GetCooldownTimeRemaining(AActor* Actor, FGameplayTagContainer CooldownTags);

	UFUNCTION(BlueprintCallable, Category="Ability | Cooldowns", meta=(DefaultToSelf="Actor"))
	static void GetCooldownTimeRemainingAndDuration(AActor* Actor, FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration);

	UFUNCTION(BlueprintPure, Category="Ability")
	static UFortAbilitySystemComponent* GetFortAbilitySystemComponent(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Ability | Advanced", meta=(AutoCreateRefTerm="AbilityToGrant"))
	static FGameplayAbilitySpecHandle GrantAndActivateAbilityOnSelf(UAbilitySystemComponent* AbilitySystem, const TSubclassOf<UGameplayAbility>& AbilityToGrant, UObject* ContextObject);

	UFUNCTION(BlueprintCallable, Category="Ability | Advanced", meta=(AutoCreateRefTerm="AbilityToGrant"))
	static FGameplayAbilitySpecHandle GrantAndActivateAbilityOnSelfWithParams(UAbilitySystemComponent* AbilitySystem, const TSubclassOf<UGameplayAbility>& AbilityToGrant, UObject* ContextObject, const FGameplayEventData GameplayEventData);

	UFUNCTION(BlueprintCallable, Category="Ability | Cooldowns", meta=(DefaultToSelf="Actor"))
	static bool IsCooldownTagsActive(AActor* Actor, FGameplayTagContainer CooldownTags);

	UFUNCTION(BlueprintCallable, Category="Ability | Gameplay Cue")
	static bool IsGameplayCueActive(AActor* Actor, const FGameplayTag& GameplayCueTag);

	UFUNCTION(BlueprintPure, Category="Ability | GameplayEffect")
	static bool IsGameplayEffectContextAbilityChildOf(const FGameplayEffectContextHandle& GameplayEffectContextHandle, const TSubclassOf<UGameplayAbility> AbilityClass);

	UFUNCTION(BlueprintPure, Category="Ability | GameplayEffect")
	static bool IsGameplayEffectContextAbilityInstance(const FGameplayEffectContextHandle& GameplayEffectContextHandle, const UGameplayAbility* AbilityInstance);

};

