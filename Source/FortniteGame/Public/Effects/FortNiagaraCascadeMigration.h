// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/WorldPSCPool.h"
#include "FortNiagaraCascadeMigration.generated.h"

class UFXSystemAsset;
class UFXSystemComponent;
class UNiagaraSystem;
class UObject;
class UParticleSystem;
class USceneComponent;
enum class EFXType : uint8;

UENUM(BlueprintType)
enum class EFXType : uint8
{
	GenericAnimNotify = 0,
	TrailAnimNotify = 1,
	WeaponImpactEffect = 2,
	WeaponMeleeImpactEffect = 3,
	Contrail = 4,
	Emote = 5,
	Trap = 6,
	Skin = 7,
	Glider = 8,
	Vehicle = 9,
	BackpackBling = 10,
	Water = 11,
	LootChest = 12,
	EnvironmentalAmbient = 13,
	WeaponRangedBeam = 14,
	WeaponBulletShells = 15,
	WeaponMuzzleFlashes = 16,
	PickAxe = 17,
	Curie = 18,
	Projectile = 19,
	Land = 20,
};

USTRUCT(BlueprintType)
struct FFortPortableSoftParticles
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	EFXType FXType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	TSoftObjectPtr<UNiagaraSystem> NiagaraVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	TSoftObjectPtr<UParticleSystem> CascadeVersion;

};

UCLASS()
class UFortNiagaraGameplayLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void BeginLegacyAnimTrails(UFXSystemComponent* Target, FName FirstSocketName, FName SecondSocketName, ETrailWidthMode WidthMode, float Width);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void EndLegacyAnimTrails(UFXSystemComponent* Target);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static TSoftObjectPtr<UFXSystemAsset> GetEnabledSoftPtr(const FFortPortableSoftParticles& SoftParticles);

	UFUNCTION(BlueprintPure, Category="Effects", meta=(Keywords="particle system"))
	static int32 GetPlayerLandType();

	UFUNCTION(BlueprintPure, Category="Effects", meta=(Keywords="particle system"))
	static int32 GetPlayerWaterType();

	UFUNCTION(BlueprintPure, Category="Effects", meta=(Keywords="particle system"))
	static bool IsNiagaraEffectEnabled(EFXType InType, UNiagaraSystem* InFXSystemAsset);

	UFUNCTION(BlueprintPure, Category="Effects", meta=(DisplayName="Is Niagara Effect Enabled (SoftObj)", Keywords="particle system"))
	static bool IsNiagaraEffectEnabledSoftPtr(EFXType InType, const TSoftObjectPtr<UNiagaraSystem>& InFXSystemAsset);

	UFUNCTION(BlueprintPure, Category="Effects", meta=(Keywords="particle system"))
	static bool IsNiagaraFXTypeEnabled(EFXType InType);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static TSoftObjectPtr<UFXSystemAsset> SelectAltSystemAsset(EFXType Type, const TSoftObjectPtr<UNiagaraSystem>& NiagaraSystemAsset, const TSoftObjectPtr<UParticleSystem>& EmitterTemplate);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetAltSystemAsset(UFXSystemComponent* Target, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject", CPP_Default_Rotation))
	static UFXSystemComponent* SetAssetOrSpawnAltFXAtLocation(UFXSystemComponent* Existing, EFXType Type, const UObject* WorldContextObject, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", CPP_Default_AttachPointName="None", CPP_Default_Location, CPP_Default_Rotation))
	static UFXSystemComponent* SetAssetOrSpawnAltFXAttached(UFXSystemComponent* Existing, EFXType Type, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetBatchedTracerPoints(UFXSystemComponent* Target, const FVector& SourcePoint, const TArray<FVector>& EndPoints);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetBeamEndPoint(UFXSystemComponent* Target, int32 EmitterIdx, const FVector& EndPoint);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetBeamPoints(UFXSystemComponent* Target, int32 EmitterIdx, int32 SourceIndex, const FVector& SourcePoint, const FVector& EndPoint);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetBeamSourcePoint(UFXSystemComponent* Target, int32 EmitterIdx, int32 SourceIndex, const FVector& SourcePoint);

	UFUNCTION(BlueprintCallable, Category="Effects", meta=(Keywords="particle system"))
	static void SetCustomTimeDilation(UFXSystemComponent* Target, float Dilation);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetImpactLocations(UFXSystemComponent* Target, const TArray<FVector>& ImpactLocations);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetImpactNormals(UFXSystemComponent* Target, const TArray<FVector>& ImpactNormals);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetInstanceParams(UFXSystemComponent* Target, const TArray<FParticleSysParam>& InstanceParameters);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void SetMultiBeamPoints(UFXSystemComponent* Target, const int32 EmitterIdx, const int32 SourceIndex, const FVector& SourcePoint, const TArray<FVector>& EndPoints);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject", CPP_Default_Rotation))
	static UFXSystemComponent* SpawnAltFXAtLocation(EFXType Type, const UObject* WorldContextObject, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", CPP_Default_AttachPointName="None", CPP_Default_Location, CPP_Default_Rotation))
	static UFXSystemComponent* SpawnAltFXAttached(EFXType Type, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject", CPP_Default_Rotation))
	static UFXSystemComponent* SpawnFXAtLocation(const UObject* WorldContextObject, UFXSystemAsset* FXSystemAsset, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject"))
	static UFXSystemComponent* SpawnFXAtLocationWithParams(FFXSystemSpawnParameters& SpawnParams);

	UFUNCTION(BlueprintCallable, Category="Effects", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true", CPP_Default_AttachPointName="None", CPP_Default_Location, CPP_Default_Rotation))
	static UFXSystemComponent* SpawnFXSystemAttached(UFXSystemAsset* FXSystemAsset, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true);

	UFUNCTION(BlueprintCallable, Category="Effects", meta=(Keywords="particle system", UnsafeDuringActorConstruction="true"))
	static UFXSystemComponent* SpawnFXSystemAttachedWithParams(FFXSystemSpawnParameters& SpawnParams);

	UFUNCTION(BlueprintCallable, Category="Effects|Components|ParticleSystem", meta=(Keywords="particle system"))
	static void TriggerEffect(UFXSystemComponent* Target, const bool bNewTriggerState, const int32 TriggerStateInt);

};

