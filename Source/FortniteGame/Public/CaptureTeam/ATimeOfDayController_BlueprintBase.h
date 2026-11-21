// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ATimeOfDayController_BlueprintBase.generated.h"

class AFortTimeOfDayManager;
class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class USkyLightComponent;
class UTextureCube;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Hidden"))
class ATimeOfDayController_BlueprintBase : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Hidden", meta=(CallInEditor="true", DevelopmentOnly))
	void SetPostProcessSettings();

	UFUNCTION(BlueprintImplementableEvent, Category="Hidden", meta=(CallInEditor="true", DevelopmentOnly))
	void SetSunOrMoonScale();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogCutoffDistance : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogDensity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogHeightFalloff : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogInscatteringColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogMaxOpacity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogStartDistance : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogDirectionalInscatteringColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogDirectionalInscatteringExponent : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogDirectionalInscatteringStartDistance : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogFullyDirectionalInscatteringColorDistance : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogUseVolumetricFog : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogVolumetricFogExtinctionScale : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogVolumetricFogDistance : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogVolumetricFogScatteringDistribution : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_FogVolumetricFogAlbedo : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_TimeOfDay : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_PostProcessBlendWeight : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_PostProcessFogOpacity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_PostProcessFogColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_DirectionalLightColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_DirectionalLightIntensity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_DirectionalLightAngle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_CloudHorizonColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SkyboxHorizonColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SkyboxZenithColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_CloudAmountHorizon : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_CloudAmountZenith : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_CloudSpeedMaster : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_CloudSpeedDetailTextureOne : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_CloudSpeedDetailTextureTwo : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_StormStrength : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SunScale : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SunDiscIntensity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SkyLightColor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SkyLightIntensity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Overrides", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bOverride_SkyLightCubemap : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Standard", meta=(DisplayName="Fog Cutoff Distance", editcondition="bOverride_FogCutoffDistance"))
	float FogCutoffDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Standard", meta=(DisplayName="Fog Density", editcondition="bOverride_FogDensity"))
	float FogDensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Standard", meta=(DisplayName="Fog Height Falloff", editcondition="bOverride_FogHeightFalloff"))
	float FogHeightFalloff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Standard", meta=(DisplayName="Fog Inscattering Color", editcondition="bOverride_FogInscatteringColor"))
	FLinearColor FogInscatteringColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Standard", meta=(DisplayName="Fog Max Opacity", editcondition="bOverride_FogMaxOpacity"))
	float FogMaxOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Standard", meta=(DisplayName="Fog Start Distance", editcondition="bOverride_FogStartDistance"))
	float FogStartDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Directional", meta=(DisplayName="Directional Inscattering Color", editcondition="bOverride_FogDirectionalInscatteringColor"))
	FLinearColor FogDirectionalInscatteringColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Directional", meta=(DisplayName="Directional Inscattering Exponent", editcondition="bOverride_FogDirectionalInscatteringExponent"))
	float FogDirectionalInscatteringExponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Directional", meta=(DisplayName="Directional Inscattering Start Distance", editcondition="bOverride_FogDirectionalInscatteringStartDistance"))
	float FogDirectionalInscatteringStartDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Directional", meta=(DisplayName="Fully Directional Inscattering Color Distance", editcondition="bOverride_FogFullyDirectionalInscatteringColorDistance"))
	float FogFullyDirectionalInscatteringColorDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Volumetric Fog", meta=(DisplayName="Should Use Volumetric Fog?", editcondition="bOverride_FogUseVolumetricFog"))
	bool FogUseVolumetricFog;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Volumetric Fog", meta=(DisplayName="Volumetric Fog Extinction Scale", editcondition="bOverride_FogVolumetricFogExtinctionScale"))
	float FogVolumetricFogExtinctionScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Volumetric Fog", meta=(DisplayName="Volumetric Fog Distance", editcondition="bOverride_FogVolumetricFogDistance"))
	float FogVolumetricFogDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Volumetric Fog", meta=(DisplayName="Volumetric Fog Scattering Distribution", editcondition="bOverride_FogVolumetricFogScatteringDistribution"))
	float FogVolumetricFogScatteringDistribution;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Fog|Volumetric Fog", meta=(DisplayName="Volumetric Fog Albedo", editcondition="bOverride_FogVolumetricFogAlbedo"))
	FColor FogVolumetricFogAlbedo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Time Of Day", meta=(ClampMax="23.99", ClampMin="0.0", DisplayName="Time Of Day in Hours", editcondition="bOverride_TimeOfDay", UIMax="23.99", UIMin="0.0"))
	float TimeOfDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Post Process", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="Post Process Blend Weight", editcondition="bOverride_PostProcessBlendWeight", UIMax="1.0", UIMin="0.0"))
	float PostProcessBlendWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Post Process", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="Post Process Fog Opacity", editcondition="bOverride_PostProcessFogOpacity", UIMax="1.0", UIMin="0.0"))
	float PostProcessFogOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Post Process", meta=(DisplayName="Post Process Fog Color", editcondition="bOverride_PostProcessFogColor"))
	FLinearColor PostProcessFogColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Directional Light", meta=(DisplayName="Directional Light Color", editcondition="bOverride_DirectionalLightColor"))
	FLinearColor DirectionalLightColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Directional Light", meta=(ClampMin="0.0", DisplayName="Directional Light Intensity", editcondition="bOverride_DirectionalLightIntensity"))
	float DirectionalLightIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Directional Light", meta=(DisplayName="Directional Light Angle", editcondition="bOverride_DirectionalLightAngle"))
	FVector DirectionalLightAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Skybox", meta=(DisplayName="Reset TODM Materials When Overriding"))
	bool bResetMaterialWhenUpdatingParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Cloud Horizon Color", editcondition="bOverride_CloudHorizonColor"))
	FLinearColor CloudHorizonColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Skybox Horizon Color", editcondition="bOverride_SkyboxHorizonColor"))
	FLinearColor SkyboxHorizonColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Skybox Zenith Color", editcondition="bOverride_SkyboxZenithColor"))
	FLinearColor SkyboxZenithColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="Cloud Amount Horizon", editcondition="bOverride_CloudAmountHorizon", UIMax="1.0", UIMin="0.0"))
	float CloudAmountHorizon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="Cloud Amount Zenith", editcondition="bOverride_CloudAmountZenith", UIMax="1.0", UIMin="0.0"))
	float CloudAmountZenith;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Cloud Speed Master", editcondition="bOverride_CloudSpeedMaster"))
	float CloudSpeedMaster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Cloud Speed Detail 1", editcondition="bOverride_CloudSpeedDetailTextureOne"))
	float CloudSpeedDetailTextureOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Cloud Speed Detail 2", editcondition="bOverride_CloudSpeedDetailTextureTwo"))
	float CloudSpeedDetailTextureTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(ClampMax="1.0", ClampMin="0.0", DisplayName="Storm Strength", editcondition="bOverride_StormStrength", UIMax="1.0", UIMin="0.0"))
	float StormStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Sun Scale", editcondition="bOverride_SunScale"))
	float SunScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Sun Disc Intensity", editcondition="bOverride_SunDiscIntensity"))
	float SunDiscIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skybox", meta=(DisplayName="Scalar Parameters"))
	TMap<FName, float> ScalarParameters;

	UPROPERTY(EditAnywhere, Category="Skybox")
	TArray<FName> SkyboxHorizonMaterialParameters;

	UPROPERTY(EditDefaultsOnly, Category="Skybox")
	TArray<FName> SkyboxZenithMaterialParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Sky Light", meta=(DisplayName="Sky Light Color", editcondition="bOverride_SkyLightColor"))
	FLinearColor SkyLightColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Sky Light", meta=(DisplayName="Sky Light Intensity", editcondition="bOverride_SkyLightIntensity"))
	float SkyLightIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sky Light", meta=(DisplayName="Sky Light Cubemap", editcondition="bOverride_SkyLightCubemap"))
	TObjectPtr<UTextureCube> SkyLightCubemap;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TimeOfDayController_BlueprintBase")
	TObjectPtr<AFortTimeOfDayManager> TODM;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UExponentialHeightFogComponent> ExponentialHeightFog;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UDirectionalLightComponent> DirectionalLight;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkyLightComponent> SkyLight;

};

