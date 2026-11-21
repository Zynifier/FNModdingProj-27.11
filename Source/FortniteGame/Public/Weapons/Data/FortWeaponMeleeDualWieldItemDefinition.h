// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "FortWeaponSoundStateEnum.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "FortWeaponMeleeDualWieldItemDefinition.generated.h"

class UNiagaraSystem;
class UParticleSystem;
class USkeletalMesh;
class USoundBase;

UCLASS(BlueprintType)
class UFortWeaponMeleeDualWieldItemDefinition : public UFortWeaponMeleeItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition")
	USkeletalMesh* GetWeaponMeshOffhandOverride() const;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<USkeletalMesh> WeaponMeshOffhandOverride;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|1) Idle", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UParticleSystem> IdleEffectOffhand;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|1) Idle", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UNiagaraSystem> IdleEffectOffhandNiagara;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|2) Swing", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UParticleSystem> SwingEffectOffhand;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|2) Swing", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UNiagaraSystem> SwingEffectOffhandNiagara;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UParticleSystem> AnimTrailsOffhand;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UNiagaraSystem> AnimTrailsNiagaraOffhand;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="4"))
	TSoftObjectPtr<USoundBase> OffhandGenericImpactSound;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<USoundBase>> OffhandImpactPhysicalSurfaceSoundsMap;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|4) Impacts", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="4"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<UParticleSystem>> OffhandImpactPhysicalSurfaceEffects;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|4) Impacts", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="4"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<UNiagaraSystem>> OffhandImpactNiagaraPhysicalSurfaceEffects;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EFortWeaponSoundState::Type>, TSoftObjectPtr<USoundBase>> OffhandPrimaryFireSoundMap;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="2"))
	FName AnimTrailsOffhandFirstSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="3"))
	FName AnimTrailsOffhandSecondSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="6"))
	float AnimTrailsOffhandWidth;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="4"))
	bool bUseAnimTrailsOffhand;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="5"))
	bool bAttachAnimTrailsOffhandToWeapon;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|1) Idle", meta=(DisplayPriority="3"))
	FName IdleFXOffhandSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|2) Swing", meta=(DisplayPriority="3"))
	FName SwingFXOffhandSocketName;

};

