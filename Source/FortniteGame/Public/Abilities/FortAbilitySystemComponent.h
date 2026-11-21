// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Abilities/AttributeInfo.h"
#include "Abilities/GameplayAbilityRepSharedAnim.h"
#include "Abilities/ReplicatedMontagePair.h"
#include "FortAbilitySystemComponent.generated.h"

class AActor;
class UAbilitySystemComponent;
class UAnimMontage;
class UGameplayEffect;
class UObject;
enum class EFortSharedAnimationState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPersonalVehicleBlockingChanged);

USTRUCT()
struct FAbilityTrackedActorEntry
{
	GENERATED_BODY()

};

USTRUCT()
struct FDebugNativeActionInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FHandleAndPreventGameplayEventEntry
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Object", "LOD", "Lighting", "Transform", "Sockets", "TextureStreaming", "Object", "LOD", "Lighting", "Transform", "Sockets", "TextureStreaming"))
class UFortAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tags", meta=(DisplayName="BlockAbilitiesWithTags"))
	void BP_BlockAbilitiesWithTags(const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, Category="Tags", meta=(DisplayName="CancelAbilitiesWithTags"))
	void BP_CancelAbilitiesWithTags(const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, Category="GameplayEffects", meta=(DisplayName="FortApplyGameplayEffectSpecToTarget", ScriptName="FortApplyGameplayEffectSpecToTarget"))
	FActiveGameplayEffectHandle BP_FortApplyGameplayEffectSpecToTarget(const FGameplayEffectSpecHandle& GameplayEffectSpecHandle, UAbilitySystemComponent* TargetOfEffect, UObject* OptionalSourceObject, AActor* OptionalEffectCauser, AActor* OptionalDamageSource, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintCallable, Category="GameplayEffects", meta=(DisplayName="FortApplyGameplayEffectToSelf", ScriptName="FortApplyGameplayEffectToSelf"))
	FActiveGameplayEffectHandle BP_FortApplyGameplayEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, UObject* OptionalSourceObject, AActor* OptionalEffectCauser, AActor* OptionalDamageSource, float Level, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintCallable, Category="GameplayEffects", meta=(DisplayName="FortApplyGameplayEffectToTarget", ScriptName="FortApplyGameplayEffectToTarget"))
	FActiveGameplayEffectHandle BP_FortApplyGameplayEffectToTarget(TSubclassOf<UGameplayEffect> GameplayEffectClass, UAbilitySystemComponent* TargetOfEffect, UObject* OptionalSourceObject, AActor* OptionalEffectCauser, AActor* OptionalDamageSource, float Level, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintCallable, Category="Tags", meta=(DisplayName="UnBlockAbilitiesWithTags"))
	void BP_UnBlockAbilitiesWithTags(const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintPure, Category="Abilities")
	bool CanActivateAbilityWithMatchingTag(FGameplayTagContainer GameplayAbilityTags) const;

	UFUNCTION(BlueprintPure, Category="Attribute")
	FAttributeInfo FindAttributeInformation(const FString AttributeName) const;

	UFUNCTION(BlueprintPure, Category="GameplayEffects")
	TArray<FActiveGameplayEffectHandle> GetActiveEffectsWithAllTagsAndSource(FGameplayTagContainer Tags, UObject* Source) const;

	UFUNCTION(BlueprintPure, Category="Attribute")
	float GetAttributeMagnitude(const FAttributeInfo Info) const;

	UFUNCTION(BlueprintPure, Category="Abilities")
	bool HasAbilityWithAnyMatchingTag(const FGameplayTagContainer& Tags, const bool bActiveAbilitiesOnly = false) const;

	UFUNCTION(BlueprintPure, Category="Abilities")
	bool HasActiveAbilityWithAnyMatchingTag(FGameplayTagContainer Tags) const;

	UFUNCTION(BlueprintPure, Category="GameplayEffects")
	FGameplayEffectContextHandle MakeFortEffectContext(UObject* SourceObject, AActor* EffectCauser, AActor* DamageSource, const int32 GameplayEffectLevel) const;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_RefreshActiveGameplayEffectCueEvents();

	UFUNCTION(BlueprintCallable, Category="Behavior")
	void OverrideAbilityBehaviorDistanceValueByTag(const FGameplayTagContainer Tags, const FGameplayTagContainer& GameplayAbilityDistanceTagContainer, const float DistanceValue);

	UFUNCTION(BlueprintCallable, Category="GameplayEffects")
	int32 RemoveActiveEffectsWithTagsAndSource(FGameplayTagContainer Tags, UObject* Source);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Animation")
	void SetLandingMontageReplication(UAnimMontage* Montage1, FName Section1, UAnimMontage* Montage2, FName Section2);

	UFUNCTION(BlueprintCallable, Category="Animation")
	void StartOverrideReplicateMontageAnimPosition();

	UFUNCTION(BlueprintCallable, Category="Animation")
	void StopOverrideReplicateMontageAnimPosition();

	UPROPERTY(BlueprintAssignable)
	FPersonalVehicleBlockingChanged OnClientVehicleBlockingChanged;

protected:
	UFUNCTION()
	void OnRep_SharedAnim();

	UFUNCTION(BlueprintCallable, Category="Animation")
	void SetSharedAnimState(EFortSharedAnimationState State);

	UFUNCTION(BlueprintCallable, Category="Animation")
	void SetSharedAnimStateWithMontage(EFortSharedAnimationState State, UAnimMontage* Montage);

	UPROPERTY(Replicated)
	FReplicatedMontagePair LandingMontagePair;

	UPROPERTY(ReplicatedUsing=OnRep_SharedAnim)
	FGameplayAbilityRepSharedAnim RepSharedAnimInfo;

};

