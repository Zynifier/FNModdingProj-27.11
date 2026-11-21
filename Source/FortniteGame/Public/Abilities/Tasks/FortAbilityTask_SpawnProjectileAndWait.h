// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayEffectContainerSpec.h"
#include "FortAbilityTask_SpawnProjectileAndWait.generated.h"

class AActor;
class AFortProjectileBase;
class UFortAbilityTask_SpawnProjectileAndWait;
class UGameplayAbility;

USTRUCT(BlueprintType)
struct FProjectileEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Projectile")
	TObjectPtr<AFortProjectileBase> SpawnedProjectile;

	UPROPERTY(BlueprintReadOnly, Category="Projectile")
	TArray<FHitResult> Hits;

	UPROPERTY(BlueprintReadOnly, Category="Projectile")
	TArray<TObjectPtr<AActor>> ExplodedActors;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnProjectileEventData, const FProjectileEventData&, ProjectileData);

UCLASS()
class UFortAbilityTask_SpawnProjectileAndWait : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Abilities", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	bool BeginSpawningActor(UGameplayAbility* OwningAbility, TSubclassOf<AFortProjectileBase> Class, AFortProjectileBase*& SpawnedActor);

	UFUNCTION(BlueprintCallable, Category="Abilities", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	void FinishSpawningActor(UGameplayAbility* OwningAbility, AFortProjectileBase* SpawnedActor);

	UFUNCTION()
	void OnProjectileDestroyed(AActor* DestroyedActor);

	UFUNCTION(BlueprintCallable, Category="Projectile | Tasks", meta=(AdvancedDisplay="bAllowProjectileSpawnWhenDead, bAllowProjectileSpawnWhenDBNO", BlueprintInternalUseOnly="true", DefaultToSelf="OwningAbility", HidePin="OwningAbility", HideSpawnParms="Instigator"))
	static UFortAbilityTask_SpawnProjectileAndWait* SpawnProjectileAndWait(UGameplayAbility* OwningAbility, TSubclassOf<AFortProjectileBase> Class, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator& SpawnRotation, const FRotator& SpawnDirection, float InitialSpeed, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode, float GravityScale = 1.000000f, AActor* HomingTarget = nullptr, bool bAllowProjectileSpawnWhenDead = false, bool bAllowProjectileSpawnWhenDBNO = false);

	UPROPERTY(BlueprintAssignable)
	FSpawnProjectileEventData Created;

	UPROPERTY(BlueprintAssignable)
	FSpawnProjectileEventData Touched;

	UPROPERTY(BlueprintAssignable)
	FSpawnProjectileEventData Bounced;

	UPROPERTY(BlueprintAssignable)
	FSpawnProjectileEventData Stopped;

	UPROPERTY(BlueprintAssignable)
	FSpawnProjectileEventData Exploded;

	UPROPERTY(BlueprintAssignable)
	FSpawnProjectileEventData Destroyed;

	UPROPERTY()
	TWeakObjectPtr<AFortProjectileBase> SpawnedProj;

	UPROPERTY()
	TObjectPtr<AActor> RequestedBy;

	UPROPERTY()
	FVector SpawnLocation;

	UPROPERTY()
	FRotator SpawnRotation;

	UPROPERTY()
	FRotator SpawnDirection;

	UPROPERTY()
	float InitialSpeed;

	UPROPERTY()
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit;

	UPROPERTY()
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode;

	UPROPERTY()
	float GravityScale;

	UPROPERTY()
	TObjectPtr<AActor> HomingTarget;

	UPROPERTY()
	bool bAllowSpawnWhenDead;

	UPROPERTY()
	bool bAllowSpawnWhenDBNO;

};

