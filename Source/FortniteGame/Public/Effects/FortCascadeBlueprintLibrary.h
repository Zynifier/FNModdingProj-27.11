// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Particles/WorldPSCPool.h"
#include "FortCascadeBlueprintLibrary.generated.h"

class UObject;
class UParticleSystem;
class UParticleSystemComponent;
class USceneComponent;

UCLASS()
class UFortCascadeBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Effects")
	static bool IsCascadeSystemBlocked(const UParticleSystem* EmitterTemplate);

	UFUNCTION(BlueprintCallable, Category="Effects")
	static bool IsCascadeSystemBlockedByPath(const FString& AssetPath);

	UFUNCTION(BlueprintCallable, Category="Effects")
	static bool IsCascadeSystemBlockedBySoftPtr(TSoftObjectPtr<UParticleSystem> EmitterTemplate);

	UFUNCTION(BlueprintCallable, Category="Effects", meta=(DisplayName="Fort Spawn Emitter At Location (Legacy)", Keywords="particle system", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject", CPP_Default_Rotation))
	static UParticleSystemComponent* SpawnEmitterAtLocation(const UObject* WorldContextObject, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivateSystem = true, bool bDebounce = true, float DebounceTime = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Effects", meta=(DisplayName="Fort Spawn Emitter Attached (Legacy)", Keywords="particle system", UnsafeDuringActorConstruction="true", CPP_Default_AttachPointName="None", CPP_Default_Location, CPP_Default_Rotation))
	static UParticleSystemComponent* SpawnEmitterAttached(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale = FVector(1.000000, 1.000000, 1.000000), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, bool bAutoDestroy = true, EPSCPoolMethod PoolingMethod = EPSCPoolMethod::None, bool bAutoActivate = true, bool bDebounce = true, float DebounceTime = -1.000000f);

};

