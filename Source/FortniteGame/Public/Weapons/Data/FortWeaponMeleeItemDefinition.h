// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortCombatTypes.h"
#include "FortWeaponSoundStateEnum.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortWeaponMeleeItemDefinition.generated.h"

class UAnimInstance;
class UAnimationAsset;
class UNiagaraSystem;
class UParticleSystem;
class USoundBase;

UENUM()
enum class EFortMeleeFX : uint8
{
	Idle = 0,
	Swing = 1,
	AnimTrail = 2,
};

USTRUCT(BlueprintType)
struct FAttachedParticleComponentDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AttachedParticleComponentDef")
	FTransform Transform;

	UPROPERTY(EditAnywhere, Category="AttachedParticleComponentDef")
	FName ParentSocket;

	UPROPERTY(EditAnywhere, Category="AttachedParticleComponentDef", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<UParticleSystem> Template;

	UPROPERTY(EditAnywhere, Category="AttachedParticleComponentDef")
	TEnumAsByte<EDetailMode> DetailMode;

};

USTRUCT(BlueprintType)
struct FFortMeleeWeaponStats : public FFortBaseWeaponStats
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float RangeVSEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float ConeYawAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float ConePitchAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float SwingPlaySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float SwingTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float BuildingConeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float BuildingConeAnglePitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float RangeVSBuildings2D;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float RangeVSBuildingsZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	float RangeVSWeakSpots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortWeaponMeleeStats")
	TMap<FGameplayTag, float> GenericSurfaceDurabilityCostMultipliers;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortWeaponMeleeItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WeaponMeleeItemDefinition")
	UNiagaraSystem* GetAnimTrailNiagaraSystem() const;

	UFUNCTION(BlueprintPure, Category="WeaponMeleeItemDefinition")
	UNiagaraSystem* GetIdleEffectNiagaraSystem() const;

	UFUNCTION(BlueprintPure, Category="WeaponMeleeItemDefinition")
	UNiagaraSystem* GetSwingEffectNiagaraSystem() const;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|1) Idle", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UParticleSystem> IdleEffect;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|1) Idle", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UNiagaraSystem> IdleEffectNiagara;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|1) Idle", meta=(DisplayPriority="3"))
	FName IdleFXSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|2) Swing", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UParticleSystem> SwingEffect;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|2) Swing", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UNiagaraSystem> SwingEffectNiagara;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|2) Swing", meta=(DisplayPriority="3"))
	FName SwingFXSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UParticleSystem> AnimTrails;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<UNiagaraSystem> AnimTrailsNiagara;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="1"))
	FName NiagaraSkeletonDIVariableName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="2"))
	FName AnimTrailsFirstSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="3"))
	FName AnimTrailsSecondSocketName;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="6"))
	float AnimTrailsWidth;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="4"))
	bool bUseAnimTrails;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|3) AnimTrails|System Parameters", meta=(DisplayPriority="5"))
	bool bAttachAnimTrailsToWeapon;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bPrimaryFireRequiresAmmo : 1;

	UPROPERTY(EditDefaultsOnly, Category="WeaponData")
	uint8 bSecondaryFireRequiresAmmo : 1;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|4) Impacts", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<UParticleSystem>> ImpactPhysicalSurfaceEffectsMap;

	UPROPERTY(meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface", AssetBundles="EquippedCosmetic"))
	TArray<TSoftObjectPtr<UNiagaraSystem>> ImpactNiagaraPhysicalSurfaceEffects_DEPRECATED;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects|4) Impacts", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<UNiagaraSystem>> ImpactNiagaraPhysicalSurfaceEffectsMap;

	UPROPERTY(EditAnywhere, Category="WeaponData Effects", meta=(AssetBundles="EquippedCosmetic"))
	TArray<FAttachedParticleComponentDef> ParticleComponentsDefs;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="EquippedCosmetic"))
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditAnywhere, Category="WeaponData", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<UAnimationAsset> SingleAnimationToPlay;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<USoundBase>> ImpactPhysicalSurfaceSoundsMap;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EFortReloadFXState::Type>, TSoftObjectPtr<USoundBase>> ReloadSoundsMap;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TMap<TEnumAsByte<EFortWeaponSoundState::Type>, TSoftObjectPtr<USoundBase>> PrimaryFireSoundMap;

	UPROPERTY(EditAnywhere, Category="WeaponData Sounds", meta=(AssetBundles="EquippedCosmetic", DisplayPriority="3"))
	TSoftObjectPtr<USoundBase> GenericImpactSound;

	UPROPERTY(EditAnywhere, Category="BR Cosmetic")
	bool bNeedsMaterial0MID;

	UPROPERTY(EditAnywhere, Category="BR Cosmetic")
	bool bWatchKills;

	UPROPERTY(EditAnywhere, Category="BR Cosmetic")
	bool bCandyCaneKillReaction;

};

