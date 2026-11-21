// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Math/RandomStream.h"
#include "Core/FortSpatialGrid.h"
#include "Curie/FX/FortCurieNativeFXHandler.h"
#include "Curie/FortCurieFireNiagaraDataInterface.h"
#include "Curie/Managers/FortCurieFXManager.h"
#include "FortCurieFireNativeFXHandler.generated.h"

class UFortCurieWorldNiagaraComponent;
class UMaterialParameterCollection;
class UNiagaraSystem;
class UTextureRenderTarget2D;

UCLASS()
class UFortCurieFireNativeFXHandler : public UFortCurieNativeFXHandler, public IFortCurieFireParticleDataInterface
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnUserSettingsEffectQualityChanged();

	UPROPERTY(Transient)
	float WorldSystemFireParticleSignificanceRequirement;

	UPROPERTY(Transient)
	float WorldSystemIgnitionParticleSignificanceRequirement;

	UPROPERTY(Transient)
	int32 NumActiveNativeFireStates;

	UPROPERTY(Transient)
	int32 PrevNumActiveFireStates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCurieWorldNiagaraComponent>> WorldFireNiagaraSystems;

	UPROPERTY(Transient)
	TArray<FFortCurieFireParticleActorData> CachedFireParticleActorData;

	UPROPERTY(Transient)
	TArray<FFortCurieFireParticleGrassData> CachedFireParticleGrassData;

	UPROPERTY(Transient)
	TSet<FFortSpatialCellIndex> CachedBurningGrassGridCells;

	UPROPERTY(Transient)
	FRandomStream RandomStream;

	UPROPERTY(Transient)
	FBox GrassFireBounds;

	UPROPERTY(Transient)
	float LandscapeCharInterpSpeed;

	UPROPERTY(Transient)
	double PreviousLandscapeCharTickTime;

};

UCLASS()
class UFortCurieFireNativeFXHandlerConfig : public UFortCurieNativeFXHandlerConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UNiagaraSystem> WorldFireSystem;

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

};

