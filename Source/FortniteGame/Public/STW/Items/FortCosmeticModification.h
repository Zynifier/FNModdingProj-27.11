// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "FortCosmeticModification.generated.h"

class AFortTracerBase;
class UMaterialInterface;
class UNiagaraSystem;
class UParticleSystem;

USTRUCT(BlueprintType)
struct FFortCosmeticModification
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Material", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UMaterialInterface> CosmeticMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> AmbientParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> AmbientNiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> MuzzleParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> MuzzleNiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> ReloadParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> ReloadNiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> BeamParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UNiagaraSystem> BeamNiagaraSystem;

	UPROPERTY(EditAnywhere, Category="Particle", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface", AssetBundles="Equipped"))
	TSoftObjectPtr<UParticleSystem> ImpactPhysicalSurfaceEffects[35];

	UPROPERTY(EditAnywhere, Category="Particle", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface", AssetBundles="Equipped, ClientAthenaPreload"))
	TArray<TSoftObjectPtr<UNiagaraSystem>> ImpactNiagaraPhysicalSurfaceEffects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tracer", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<AFortTracerBase> TracerTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	bool bModifyColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor ColorAlteration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FName ColorParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	bool bModifyDecalColour;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor DecalColourAlterationStart;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor DecalColourAlterationEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	bool bModifyShellColour;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FLinearColor ShellColourAlteration;

};

USTRUCT(BlueprintType)
struct FFortConditionalCosmeticModification
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosmetic")
	FFortCosmeticModification CosmeticModification;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cosmetic")
	FGameplayTagContainer ConditionalTags;

};

