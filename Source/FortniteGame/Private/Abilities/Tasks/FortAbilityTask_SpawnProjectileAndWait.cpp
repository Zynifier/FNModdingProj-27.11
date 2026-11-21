// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_SpawnProjectileAndWait.h"

bool UFortAbilityTask_SpawnProjectileAndWait::BeginSpawningActor(UGameplayAbility* OwningAbility, TSubclassOf<AFortProjectileBase> Class, AFortProjectileBase*& SpawnedActor)
{
	return false;
}

void UFortAbilityTask_SpawnProjectileAndWait::FinishSpawningActor(UGameplayAbility* OwningAbility, AFortProjectileBase* SpawnedActor)
{
}

void UFortAbilityTask_SpawnProjectileAndWait::OnProjectileDestroyed(AActor* DestroyedActor)
{
}

UFortAbilityTask_SpawnProjectileAndWait* UFortAbilityTask_SpawnProjectileAndWait::SpawnProjectileAndWait(UGameplayAbility* OwningAbility, TSubclassOf<AFortProjectileBase> Class, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator& SpawnRotation, const FRotator& SpawnDirection, float InitialSpeed, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode, float GravityScale, AActor* HomingTarget, bool bAllowProjectileSpawnWhenDead, bool bAllowProjectileSpawnWhenDBNO)
{
	return nullptr;
}
