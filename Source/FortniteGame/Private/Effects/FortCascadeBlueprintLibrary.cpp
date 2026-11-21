// Copyright Epic Games, Inc. All Rights Reserved.

#include "Effects/FortCascadeBlueprintLibrary.h"

bool UFortCascadeBlueprintLibrary::IsCascadeSystemBlocked(const UParticleSystem* EmitterTemplate)
{
	return false;
}

bool UFortCascadeBlueprintLibrary::IsCascadeSystemBlockedByPath(const FString& AssetPath)
{
	return false;
}

bool UFortCascadeBlueprintLibrary::IsCascadeSystemBlockedBySoftPtr(TSoftObjectPtr<UParticleSystem> EmitterTemplate)
{
	return false;
}

UParticleSystemComponent* UFortCascadeBlueprintLibrary::SpawnEmitterAtLocation(const UObject* WorldContextObject, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivateSystem, bool bDebounce, float DebounceTime)
{
	return nullptr;
}

UParticleSystemComponent* UFortCascadeBlueprintLibrary::SpawnEmitterAttached(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, EAttachLocation::Type LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate, bool bDebounce, float DebounceTime)
{
	return nullptr;
}
