// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortCreativeCreatureManagerComponent.h"

void UFortCreativeCreatureManagerComponent::OnAIPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortCreativeCreatureManagerComponent::OnInfoComponentAdded(UFortCreativeCreatureManagerInfoComponent* CreatureManagerInfoComponent)
{
}

void UFortCreativeCreatureManagerComponent::OnInfoComponentRemoved(UFortCreativeCreatureManagerInfoComponent* CreatureManagerInfoComponent)
{
}

ECreatureManagerAffectedTargets UFortCreativeCreatureManagerInfoComponent::GetAffectedTargetsType() const
{
	return ECreatureManagerAffectedTargets();
}

TSoftClassPtr<AFortAIPawn> UFortCreativeCreatureManagerInfoComponent::GetCreatureBlueprintClass() const
{
	return TSoftClassPtr<AFortAIPawn>();
}

UFortCreativeCreatureManagerComponent* UFortCreativeCreatureManagerInfoComponent::GetCreatureManagerComponent()
{
	return nullptr;
}

float UFortCreativeCreatureManagerInfoComponent::GetEnvironmentalDamageOverride() const
{
	return float();
}

float UFortCreativeCreatureManagerInfoComponent::GetHearingAggroRange() const
{
	return float();
}

float UFortCreativeCreatureManagerInfoComponent::GetInvalidFloat()
{
	return float();
}

int32 UFortCreativeCreatureManagerInfoComponent::GetInvalidInt32()
{
	return int32();
}

int32 UFortCreativeCreatureManagerInfoComponent::GetMaxHealth() const
{
	return int32();
}

float UFortCreativeCreatureManagerInfoComponent::GetMovementSpeedMultiplier() const
{
	return float();
}

float UFortCreativeCreatureManagerInfoComponent::GetOverrideDamage() const
{
	return float();
}

EScoreDistributionType UFortCreativeCreatureManagerInfoComponent::GetScoreDistribution() const
{
	return EScoreDistributionType();
}

int32 UFortCreativeCreatureManagerInfoComponent::GetScorePoints() const
{
	return int32();
}

bool UFortCreativeCreatureManagerInfoComponent::GetWeaponKnockbackImmunity() const
{
	return false;
}

void UFortCreativeCreatureManagerInfoComponent::ResetEnvironmentalDamageOverride()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetHearingAggroRange()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetMaxHealth()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetMovementSpeedMultiplier()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetOverrideDamage()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetScoreDistribution()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetScorePoints()
{
}

void UFortCreativeCreatureManagerInfoComponent::ResetWeaponKnockbackImmunity()
{
}

void UFortCreativeCreatureManagerInfoComponent::SetAffectedTargetsType(ECreatureManagerAffectedTargets InAffectedTargetsType)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetCreatureBlueprintClass(TSoftClassPtr<AFortAIPawn> InCreatureBlueprintClass)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetCreatureManagerComponent(UFortCreativeCreatureManagerComponent* InCreatureManagerComponent)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetDamageOverrideEffect(TSubclassOf<UGameplayEffect> Effect)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetDamageOverrideTag(FGameplayTag Tag)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetEnvironmentalDamageOverride(float InOverrideDamage)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetEnvironmentalDamageOverrideEffect(TSubclassOf<UGameplayEffect> Effect)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetHearingAggroRange(float InHearingAggroRange)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetMaxHealth(int32 InMaxHealth)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetMaxHealthOverrideEffect(TSubclassOf<UGameplayEffect> Effect)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetMaxHealthOverrideTag(FGameplayTag Tag)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetMovementOverrideTag(FGameplayTag Tag)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetMovementSpeedMultiplier(float InOverrideMovementSpeedMultiplier)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetMovementSpeedOverrideEffect(TSubclassOf<UGameplayEffect> Effect)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetOverrideDamage(float InOverrideDamage)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetScoreDistribution(const EScoreDistributionType InScoreDistribution)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetScorePoints(int32 InScorePoints)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetWeaponKnockbackImmunity(bool InImmuneToWeaponKnockback)
{
}

void UFortCreativeCreatureManagerInfoComponent::SetWeaponKnockbackImmunityEffect(TSubclassOf<UGameplayEffect> Effect)
{
}
