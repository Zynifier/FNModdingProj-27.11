// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortCurieFXSettings.generated.h"

class UMaterialParameterCollection;
class UNiagaraSystem;
class USoundBase;
class UStaticMesh;
class UTextureRenderTarget2D;

USTRUCT()
struct FNativeCurieFXTypeSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="General", meta=(DisplayName="Glow Fade-In Curve", EditCondition="bNeedsGlow", XAxisName="Time", YAxisName="Alpha Mult"))
	FRuntimeFloatCurve GlowFadeInCurve;

	UPROPERTY(EditAnywhere, Category="General", meta=(DisplayName="Glow Fade-Out Curve", EditCondition="bNeedsGlow", XAxisName="Time", YAxisName="Alpha Mult"))
	FRuntimeFloatCurve GlowFadeOutCurve;

	UPROPERTY(EditAnywhere, Category="General", meta=(ClampMin="0", EditCondition="bNeedsGlow", UIMin="0"))
	int32 GlowPriority;

	UPROPERTY(EditAnywhere, Category="General", meta=(ClampMin="0.000000", EditCondition="bNeedsGlow", UIMin="0.000000"))
	float GlowMaterialIdx;

	UPROPERTY(EditAnywhere, Category="General")
	uint8 bNeedsSignificanceTracking : 1;

	UPROPERTY(EditAnywhere, Category="General")
	uint8 bNeedsGlow : 1;

	UPROPERTY(EditAnywhere, Category="General")
	uint8 bNeedsAmbientAudio : 1;

};

UCLASS(Config=Game)
class UFortCurieFXSettings : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="NativeFXTypes")
	FNativeCurieFXTypeSettings ElectricityNativeFXTypeSettings;

	UPROPERTY(EditDefaultsOnly, Category="NativeFXTypes")
	FNativeCurieFXTypeSettings FireNativeFXTypeSettings;

	UPROPERTY(EditDefaultsOnly, Category="NativeFXTypes")
	FNativeCurieFXTypeSettings CharredNativeFXTypeSettings;

	UPROPERTY(EditDefaultsOnly, Category="Electricity")
	TArray<TObjectPtr<UStaticMesh>> ElectricityArcMeshes;

	UPROPERTY(EditDefaultsOnly, Category="Electricity")
	TObjectPtr<UNiagaraSystem> ElectricityArcImpactSystem;

	UPROPERTY(EditDefaultsOnly, Category="Electricity")
	TObjectPtr<USoundBase> ElectricityArcSound;

	UPROPERTY(EditDefaultsOnly, Category="Electricity")
	TObjectPtr<USoundBase> ElectricityAmbientSound;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UNiagaraSystem> PlayerWorldFireSystem;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<USoundBase> FireAmbientSound;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	TObjectPtr<UTextureRenderTarget2D> LandscapeCharRenderTarget;

	UPROPERTY(EditDefaultsOnly, Category="Fire")
	FName PlayerWorldFireSystemLightScalabilityParamName;

	UPROPERTY(EditDefaultsOnly, Category="General", meta=(ClampMin="0", UIMin="0"))
	int32 GlowElementIdxPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, Category="General", meta=(ClampMin="0", UIMin="0"))
	int32 GlowLerpDataIdx;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0", UIMin="0"))
	int32 CharredEffectPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcTilingDivisorPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcStartTimestampPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcJumpDurationPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcDurationBeforeFadeoutPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcWPONoisePrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcWPONoiseWorldTileScalePrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcWPONoiseScalePrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcSplineWidthPrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0", UIMin="0"))
	int32 ElectricityArcColorScalePrimitiveDataIdx;

	UPROPERTY(EditDefaultsOnly, Category="Electricity", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float ElectricityArcMaxPropagationLength;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector ElectricityArcRandScaleMin;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector ElectricityArcRandScaleMax;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector2D ElectricityArcTilingDivisorRand;

	UPROPERTY(EditDefaultsOnly, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcJumpDuration;

	UPROPERTY(EditDefaultsOnly, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcLifetime;

	UPROPERTY(EditDefaultsOnly, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcFadeoutDuration;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector ElectricityArcWPONoiseRandMin;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector ElectricityArcWPONoiseRandMax;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector2D ElectricityArcWPONoiseWorldTileScaleRand;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity")
	FVector2D ElectricityArcWPONoiseScaleRand;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcSplineWidthFirstIteration;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcSplineWidthSubsequentIteration;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcColorScaleFirstIteration;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcColorScaleSubsequentIteration;

	UPROPERTY(EditDefaultsOnly, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcRetriggerDelay;

	UPROPERTY(EditDefaultsOnly, Category="Electricity", meta=(ClampMin="0.100000", UIMin="0.100000"))
	float ElectricityArcImpactFXDelay;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0.010000", UIMIn="0.010000"))
	float CharredStateInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float CharredStateFireAttachedFinalAlpha;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float CharredStateNearFireFinalAlpha;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0.010000", UIMin="0.010000"))
	float LandscapeCharredStateInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0.010000", UIMin="0.010000"))
	float MinLandscapeFireSphericalBounds;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="0.010000", UIMin="0.010000"))
	float MaxLandscapeFireSphericalBounds;

	UPROPERTY(EditDefaultsOnly, Category="Fire", meta=(ClampMin="1.000000", UIMin="1.000000"))
	float LandscapeFireRandomLocationRadius;

	UPROPERTY(EditDefaultsOnly, Category="General", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float AmbientAudioFadeTime;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FName NativeFXHandlerRegistryName;

};

