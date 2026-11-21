// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortWeaponEnums.h"
#include "FortWeaponFireModeData.generated.h"

class AFortTracerBase;
class UAnimMontage;
class UNiagaraSystem;
class UParticleSystem;
class USoundBase;

UCLASS()
class UFortWeaponFireModeData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortWeaponFireModeData")
	float FireModeDataDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponFireModeData")
	TSubclassOf<AFortTracerBase> TracerTemplate;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	bool bOverrideImpactSurfaceEffects;

	UPROPERTY(EditDefaultsOnly, Category="Effects", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TObjectPtr<UParticleSystem> ImpactPhysicalSurfaceEffects[35];

	UPROPERTY(EditDefaultsOnly, Category="Effects", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TArray<TObjectPtr<UNiagaraSystem>> ImpactNiagaraPhysicalSurfaceEffectAssets;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponFireModeData")
	TObjectPtr<UParticleSystem> BeamParticleSystem;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponFireModeData")
	TObjectPtr<UNiagaraSystem> BeamNiagaraSystemAsset;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	bool bOverrideImpactSurfaceSounds;

	UPROPERTY(EditDefaultsOnly, Category="Sounds", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TObjectPtr<USoundBase> ImpactPhysicalSurfaceSounds[35];

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponFireModeData")
	TObjectPtr<UParticleSystem> MuzzleParticleSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponFireModeData")
	TObjectPtr<UNiagaraSystem> MuzzleNiagaraSystem;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundBase> PrimaryFireSound1P;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	bool bOverridePrimaryFireSoundArray;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponSoundState"))
	TObjectPtr<USoundBase> PrimaryFireSound[3];

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> OverrideWeaponFireMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> OverrideWeaponFireDownsightsMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> OverrideWeaponFireFromCrouchWalkMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> OverrideWeaponReloadMontage;

	UPROPERTY(EditAnywhere, Category="PawnAnimation")
	TObjectPtr<UAnimMontage> OverridePawnReloadMontage;

	UPROPERTY(EditAnywhere, Category="Reload Type")
	bool bShouldOverrideReloadType;

	UPROPERTY(EditAnywhere, Category="Reload Type")
	EFortWeaponReloadType OverrideReloadType;

	UPROPERTY(EditAnywhere, Category="Reload Type")
	float OverrideReloadDuration;

};

