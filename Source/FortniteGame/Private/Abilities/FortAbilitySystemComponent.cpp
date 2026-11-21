// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

void UFortAbilitySystemComponent::BP_BlockAbilitiesWithTags(const FGameplayTagContainer& Tags)
{
}

void UFortAbilitySystemComponent::BP_CancelAbilitiesWithTags(const FGameplayTagContainer& Tags)
{
}

FActiveGameplayEffectHandle UFortAbilitySystemComponent::BP_FortApplyGameplayEffectSpecToTarget(const FGameplayEffectSpecHandle& GameplayEffectSpecHandle, UAbilitySystemComponent* TargetOfEffect, UObject* OptionalSourceObject, AActor* OptionalEffectCauser, AActor* OptionalDamageSource, FGameplayEffectContextHandle EffectContext)
{
	return FActiveGameplayEffectHandle();
}

FActiveGameplayEffectHandle UFortAbilitySystemComponent::BP_FortApplyGameplayEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, UObject* OptionalSourceObject, AActor* OptionalEffectCauser, AActor* OptionalDamageSource, float Level, FGameplayEffectContextHandle EffectContext)
{
	return FActiveGameplayEffectHandle();
}

FActiveGameplayEffectHandle UFortAbilitySystemComponent::BP_FortApplyGameplayEffectToTarget(TSubclassOf<UGameplayEffect> GameplayEffectClass, UAbilitySystemComponent* TargetOfEffect, UObject* OptionalSourceObject, AActor* OptionalEffectCauser, AActor* OptionalDamageSource, float Level, FGameplayEffectContextHandle EffectContext)
{
	return FActiveGameplayEffectHandle();
}

void UFortAbilitySystemComponent::BP_UnBlockAbilitiesWithTags(const FGameplayTagContainer& Tags)
{
}

bool UFortAbilitySystemComponent::CanActivateAbilityWithMatchingTag(FGameplayTagContainer GameplayAbilityTags) const
{
	return false;
}

FAttributeInfo UFortAbilitySystemComponent::FindAttributeInformation(const FString AttributeName) const
{
	return FAttributeInfo();
}

TArray<FActiveGameplayEffectHandle> UFortAbilitySystemComponent::GetActiveEffectsWithAllTagsAndSource(FGameplayTagContainer Tags, UObject* Source) const
{
	return TArray<FActiveGameplayEffectHandle>();
}

float UFortAbilitySystemComponent::GetAttributeMagnitude(const FAttributeInfo Info) const
{
	return float();
}

bool UFortAbilitySystemComponent::HasAbilityWithAnyMatchingTag(const FGameplayTagContainer& Tags, const bool bActiveAbilitiesOnly) const
{
	return false;
}

bool UFortAbilitySystemComponent::HasActiveAbilityWithAnyMatchingTag(FGameplayTagContainer Tags) const
{
	return false;
}

FGameplayEffectContextHandle UFortAbilitySystemComponent::MakeFortEffectContext(UObject* SourceObject, AActor* EffectCauser, AActor* DamageSource, const int32 GameplayEffectLevel) const
{
	return FGameplayEffectContextHandle();
}

void UFortAbilitySystemComponent::NetMulticast_RefreshActiveGameplayEffectCueEvents_Implementation()
{
}

void UFortAbilitySystemComponent::OnRep_SharedAnim()
{
}

void UFortAbilitySystemComponent::OverrideAbilityBehaviorDistanceValueByTag(const FGameplayTagContainer Tags, const FGameplayTagContainer& GameplayAbilityDistanceTagContainer, const float DistanceValue)
{
}

int32 UFortAbilitySystemComponent::RemoveActiveEffectsWithTagsAndSource(FGameplayTagContainer Tags, UObject* Source)
{
	return int32();
}

void UFortAbilitySystemComponent::SetLandingMontageReplication(UAnimMontage* Montage1, FName Section1, UAnimMontage* Montage2, FName Section2)
{
}

void UFortAbilitySystemComponent::SetSharedAnimState(EFortSharedAnimationState State)
{
}

void UFortAbilitySystemComponent::SetSharedAnimStateWithMontage(EFortSharedAnimationState State, UAnimMontage* Montage)
{
}

void UFortAbilitySystemComponent::StartOverrideReplicateMontageAnimPosition()
{
}

void UFortAbilitySystemComponent::StopOverrideReplicateMontageAnimPosition()
{
}

void UFortAbilitySystemComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAbilitySystemComponent, LandingMontagePair);
	DOREPLIFETIME(UFortAbilitySystemComponent, RepSharedAnimInfo);
}
