// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Math/MathFwd.h"
#include "Math/RandomStream.h"
#include "Core/FortSpatialGrid.h"
#include "Curie/FX/FortCurieNativeFXHandler.h"
#include "Curie/FortCurieFireNiagaraDataInterface.h"
#include "Curie/Managers/FortCurieFXManager.h"
#include "FX/FortCurieVoxelFireDebugNiagaraDataInterface.h"
#include "FX/FortCurieVoxelFireNiagaraDataInterface.h"
#include "FX/InfernoCurieVoxelFireAudioNiagaraDataInterface.h"
#include "FortCurieVoxelFireNativeFXHandler.generated.h"

class UAudioComponent;
class UFortCurieComponent;
class UFortCurieWorldNiagaraComponent;
class UMaterialParameterCollection;
class UNiagaraSystem;
class USoundBase;
class UTextureRenderTarget2D;

USTRUCT()
struct FFortCurieVoxelFireParticleGrassData
{
	GENERATED_BODY()

};

UCLASS()
class UFortCurieVoxelFireNativeFXHandler : public UFortCurieNativeFXHandler, public IFortCurieFireParticleDataInterface, public IFortCurieVoxelFireDebugParticleDataInterface, public IFortCurieVoxelFireParticleDataInterface, public IInfernoCurieVoxelFireAudioParticleDataInterface
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnUserSettingsEffectQualityChanged();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TSet<TObjectPtr<UFortCurieComponent>> PendingUpdateComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TSet<TObjectPtr<UFortCurieComponent>> PendingRemoveComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCurieWorldNiagaraComponent>> WorldFireNiagaraSystems;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCurieWorldNiagaraComponent>> WorldFireDebugNiagaraSystems;

	UPROPERTY(Transient)
	float WorldSystemFireParticleSignificanceRequirement;

	UPROPERTY(Transient)
	float WorldSystemIgnitionParticleSignificanceRequirement;

	UPROPERTY(Transient)
	float AudioGrassFireSignificanceRequirement;

	UPROPERTY(Transient)
	float AudioActorFireSignificanceRequirement;

	UPROPERTY(Transient)
	FRandomStream RandomStream;

	UPROPERTY(Transient)
	FBox GrassFireBounds;

	UPROPERTY(Transient)
	float LandscapeCharInterpSpeed;

	UPROPERTY(Transient)
	float TimeSinceAudioUpdate;

	UPROPERTY(Transient)
	TArray<FFortCurieVoxelFireParticleGrassData> CachedFireParticleGrassData;

	UPROPERTY(Transient)
	TArray<FFortCurieFireParticleActorData> CachedFireParticleActorData;

	UPROPERTY(Transient)
	TSet<FFortSpatialCellIndex> CachedBurningGrassGridCells;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FFortSpatialCellIndex, TObjectPtr<UAudioComponent>> GrassAudioMap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> PreallocatedAudioComponents;

	UPROPERTY(Transient)
	FTimerHandle AudioComponentCleanupTimerHandle;

	UPROPERTY(Transient)
	double PreviousLandscapeCharTickTime;

};

UCLASS()
class UFortCurieVoxelFireNativeFXHandlerConfig : public UFortCurieNativeFXHandlerConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UNiagaraSystem> WorldFireSystem;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UNiagaraSystem> WorldFireDebugSystem;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UTextureRenderTarget2D> LandscapeCharRenderTarget;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	FName PlayerWorldFireSystemLightScalabilityParamName;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	FName LandscapeBiasParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	FName LandscapeDivisorParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	float LandscapeFireRandomLocationRadius;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	float MinLandscapeFireSphericalBounds;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	float MaxLandscapeFireSphericalBounds;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	float LandscapeCharInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	float LandscapeIgnitionParticleMovementSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(EditCondition="!bNeedsAmbientAudio"))
	bool bUseVoxelFireAmbientAudio;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(EditCondition="bUseVoxelFireAmbientAudio"))
	TObjectPtr<USoundBase> StructureFireAmbientSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(EditCondition="bUseVoxelFireAmbientAudio"))
	TObjectPtr<USoundBase> GrassFireAmbientSound;

};

