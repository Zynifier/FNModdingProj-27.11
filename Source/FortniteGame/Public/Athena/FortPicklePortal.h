// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "SourceEffects/SourceEffectStereoDelay.h"
#include "FortPicklePortal.generated.h"

class AFortPlayerPawn;
class UAudioComponent;
class UCurveFloat;
class UMaterialParameterCollection;
class UNiagaraComponent;
class USourceEffectStereoDelayPreset;
class USphereComponent;
class USpotLightComponent;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortPicklePortal : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="PortalEffect")
	void UpdateOpenAmount(float OpenAmount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Collision", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USphereComponent> RangeCollisionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FName OpenAmountParameterName;

	UPROPERTY(EditDefaultsOnly, Category="PortalEffect")
	FComponentReference PortalParticleSystemReference;

	UPROPERTY(EditDefaultsOnly, Category="PortalEffect")
	FComponentReference SMPortalInnerReference;

	UPROPERTY(EditDefaultsOnly, Category="PortalEffect")
	FComponentReference SMPortalOuterReference;

	UPROPERTY(EditDefaultsOnly, Category="PortalEffect")
	FComponentReference SpotlightComponentReference;

	UPROPERTY(EditDefaultsOnly, Category="PortalEffect")
	FComponentReference AudioComponentReference;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> PortalParticleSystem;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SMPortalInner;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SMPortalOuter;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USpotLightComponent> SpotlightComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector2D OuterConeAngleRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector2D InnerConeAngleRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector2D IntensityRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector2D AttenuationRadiusRange;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	TObjectPtr<USourceEffectStereoDelayPreset> EffectPreset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FSourceEffectStereoDelaySettings EffectSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FName MaterialParameterCollectionParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector2D DelayTimeRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector2D WetLevelRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	TObjectPtr<UCurveFloat> OpenCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	FVector ZeroPointPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	float OpenInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	float MaxDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	float NearDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PortalEffect")
	float FadeRadius;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawn>> LocalPawns;

};

