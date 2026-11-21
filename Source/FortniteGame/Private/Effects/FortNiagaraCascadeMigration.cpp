// Copyright Epic Games, Inc. All Rights Reserved.

#include "Effects/FortNiagaraCascadeMigration.h"

void UFortNiagaraGameplayLibrary::BeginLegacyAnimTrails(UFXSystemComponent* Target, FName FirstSocketName, FName SecondSocketName, ETrailWidthMode WidthMode, float Width)
{
}

void UFortNiagaraGameplayLibrary::EndLegacyAnimTrails(UFXSystemComponent* Target)
{
}

TSoftObjectPtr<UFXSystemAsset> UFortNiagaraGameplayLibrary::GetEnabledSoftPtr(const FFortPortableSoftParticles& SoftParticles)
{
	return TSoftObjectPtr<UFXSystemAsset>();
}

int32 UFortNiagaraGameplayLibrary::GetPlayerLandType()
{
	return int32();
}

int32 UFortNiagaraGameplayLibrary::GetPlayerWaterType()
{
	return int32();
}

bool UFortNiagaraGameplayLibrary::IsNiagaraEffectEnabled(EFXType InType, UNiagaraSystem* InFXSystemAsset)
{
	return false;
}

bool UFortNiagaraGameplayLibrary::IsNiagaraEffectEnabledSoftPtr(EFXType InType, const TSoftObjectPtr<UNiagaraSystem>& InFXSystemAsset)
{
	return false;
}

bool UFortNiagaraGameplayLibrary::IsNiagaraFXTypeEnabled(EFXType InType)
{
	return false;
}

TSoftObjectPtr<UFXSystemAsset> UFortNiagaraGameplayLibrary::SelectAltSystemAsset(EFXType Type, const TSoftObjectPtr<UNiagaraSystem>& NiagaraSystemAsset, const TSoftObjectPtr<UParticleSystem>& EmitterTemplate)
{
	return TSoftObjectPtr<UFXSystemAsset>();
}

void UFortNiagaraGameplayLibrary::SetAltSystemAsset(UFXSystemComponent* Target, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate)
{
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SetAssetOrSpawnAltFXAtLocation(UFXSystemComponent* Existing, EFXType Type, const UObject* WorldContextObject, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate)
{
	return nullptr;
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SetAssetOrSpawnAltFXAttached(UFXSystemComponent* Existing, EFXType Type, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, EAttachLocation::Type LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate)
{
	return nullptr;
}

void UFortNiagaraGameplayLibrary::SetBatchedTracerPoints(UFXSystemComponent* Target, const FVector& SourcePoint, const TArray<FVector>& EndPoints)
{
}

void UFortNiagaraGameplayLibrary::SetBeamEndPoint(UFXSystemComponent* Target, int32 EmitterIdx, const FVector& EndPoint)
{
}

void UFortNiagaraGameplayLibrary::SetBeamPoints(UFXSystemComponent* Target, int32 EmitterIdx, int32 SourceIndex, const FVector& SourcePoint, const FVector& EndPoint)
{
}

void UFortNiagaraGameplayLibrary::SetBeamSourcePoint(UFXSystemComponent* Target, int32 EmitterIdx, int32 SourceIndex, const FVector& SourcePoint)
{
}

void UFortNiagaraGameplayLibrary::SetCustomTimeDilation(UFXSystemComponent* Target, float Dilation)
{
}

void UFortNiagaraGameplayLibrary::SetImpactLocations(UFXSystemComponent* Target, const TArray<FVector>& ImpactLocations)
{
}

void UFortNiagaraGameplayLibrary::SetImpactNormals(UFXSystemComponent* Target, const TArray<FVector>& ImpactNormals)
{
}

void UFortNiagaraGameplayLibrary::SetInstanceParams(UFXSystemComponent* Target, const TArray<FParticleSysParam>& InstanceParameters)
{
}

void UFortNiagaraGameplayLibrary::SetMultiBeamPoints(UFXSystemComponent* Target, const int32 EmitterIdx, const int32 SourceIndex, const FVector& SourcePoint, const TArray<FVector>& EndPoints)
{
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SpawnAltFXAtLocation(EFXType Type, const UObject* WorldContextObject, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate)
{
	return nullptr;
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SpawnAltFXAttached(EFXType Type, UNiagaraSystem* NiagaraSystemAsset, UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, EAttachLocation::Type LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate)
{
	return nullptr;
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SpawnFXAtLocation(const UObject* WorldContextObject, UFXSystemAsset* FXSystemAsset, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate)
{
	return nullptr;
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SpawnFXAtLocationWithParams(FFXSystemSpawnParameters& SpawnParams)
{
	return nullptr;
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SpawnFXSystemAttached(UFXSystemAsset* FXSystemAsset, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, EAttachLocation::Type LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate)
{
	return nullptr;
}

UFXSystemComponent* UFortNiagaraGameplayLibrary::SpawnFXSystemAttachedWithParams(FFXSystemSpawnParameters& SpawnParams)
{
	return nullptr;
}

void UFortNiagaraGameplayLibrary::TriggerEffect(UFXSystemComponent* Target, const bool bNewTriggerState, const int32 TriggerStateInt)
{
}
