// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "GameFramework/Info.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "AI/FortThreatVisualsManager.h"
#include "FortInitializationInterface.h"
#include "FortTimeOfDayManagerInterface.h"
#include "TimeOfDay/FortDayPhase.h"
#include "FortTimeOfDayManager.generated.h"

class AActor;
class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class UFortDayPhaseChangeParams;
class UFortDayPhaseInfoOverride;
class UFortTimeOfDayWeatherComponent;
class UMaterialInstance;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class UObject;
class UParticleSystemComponent;
class UPostProcessComponent;
class USkyLightComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;
class UTextureCube;
enum class EFortDayPhase : uint8;

UENUM(BlueprintType)
namespace EFortTODMPostProcess
{
	enum Type
	{
		Morning = 0,
		Day = 1,
		Evening = 2,
		Night = 3,
		Classic = 4,
		NumPostprocess = 5 UMETA(DisplayName="Invalid", Hidden),
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDominantInhibitorSignature);

USTRUCT()
struct FCameraAltitudeAdjustments
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	float Altitude;

	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	float FogHeightFalloff;

	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	float HeightFogZOffset;

	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	float FogDensity;

};

USTRUCT()
struct FCloudColorState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor BottomEmissive;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor TopEmissive;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor BottomLightning;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor TopLightning;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor InternalColor;

};

USTRUCT()
struct FDirectionalLightValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Directional Light Color"))
	FColor LightColor;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Directional Light Brightness"))
	float Brightness;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(UIMax="4.0", UIMin="0.25"))
	float VolumetricScatteringIntensity;

};

USTRUCT()
struct FElementalCharValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor FireCharColor;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	float ElectricalCharEmissive;

};

USTRUCT(BlueprintType)
struct FExponentialHeightFogValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	float FogDensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	float FogHeightFalloff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	float FogMaxOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle", meta=(DisplayName="Fog Start Distance"))
	float StartDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	float DirectionalInscatteringExponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	float DirectionalInscatteringStartDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	FLinearColor DirectionalInscatteringColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	FLinearColor FogInscatteringColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DayNightCycle", meta=(DisplayName="Scattering Distribution", UIMax=".9", UIMin="-.9"))
	float VolumetricFogScatteringDistribution;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DayNightCycle", meta=(DisplayName="Albedo"))
	FLinearColor VolumetricFogAlbedo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DayNightCycle", meta=(DisplayName="Extinction Scale", UIMax="10", UIMin=".1"))
	float VolumetricFogExtinctionScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DayNightCycle", meta=(DisplayName="Distance", UIMax="10000", UIMin="1000"))
	float VolumetricFogDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DayNightCycle")
	FExponentialHeightFogData SecondFogData;

};

USTRUCT()
struct FSkyAtmosphereValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Atmosphere - Rayleigh", meta=(ClampMin="0.000000", SliderExponent="4.000000", UIMax="2.000000", UIMin="0.000000"))
	float RayleighScatteringScale;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Rayleigh", meta=(HideAlphaChannel))
	FLinearColor RayleighScattering;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Rayleigh", meta=(ClampMin="0.100000", SliderExponent="5.000000", UIMax="20.000000", UIMin="0.010000"))
	float RayleighExponentialDistribution;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Mie", meta=(ClampMin="0.000000", SliderExponent="4.000000", UIMax="5.000000", UIMin="0.000000"))
	float MieScatteringScale;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Mie", meta=(HideAlphaChannel))
	FLinearColor MieScattering;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Mie", meta=(ClampMin="0.000000", SliderExponent="4.000000", UIMax="5.000000", UIMin="0.000000"))
	float MieAbsorptionScale;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Mie", meta=(HideAlphaChannel))
	FLinearColor MieAbsorption;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Mie", meta=(ClampMax="0.999000", ClampMin="0.000000", UIMax="0.999000", UIMin="0.000000"))
	float MieAnisotropy;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Mie", meta=(ClampMin="0.100000", SliderExponent="5.000000", UIMax="10.000000", UIMin="0.010000"))
	float MieExponentialDistribution;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Absorption", meta=(ClampMin="0.000000", DisplayName="Absorption Scale", SliderExponent="3.000000", UIMax="0.200000", UIMin="0.000000"))
	float OtherAbsorptionScale;

	UPROPERTY(EditAnywhere, Category="Atmosphere - Absorption", meta=(DisplayName="Absorption", HideAlphaChannel))
	FLinearColor OtherAbsorption;

	UPROPERTY(EditAnywhere, Category="Art direction", meta=(HideAlphaChannel))
	FLinearColor SkyLuminanceFactor;

	UPROPERTY(EditAnywhere, Category="Art direction", meta=(ClampMin="0.000000", DisplayName="Aerial Perspective View Distance Scale", SliderExponent="2.000000", UIMax="3.000000", UIMin="0.000000"))
	float AerialPespectiveViewDistanceScale;

	UPROPERTY(EditAnywhere, Category="Art direction", meta=(ClampMin="0.000000", SliderExponent="2.000000", UIMax="1.000000", UIMin="0.000000"))
	float HeightFogContribution;

};

USTRUCT()
struct FSkyLightValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor SkyLightColor;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FLinearColor SkyLightOcclusionTint;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	float SkyLightMinOcclusion;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle", meta=(UIMax="4.0", UIMin="0.25"))
	float VolumetricScatteringIntensity;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle", meta=(EditCondition="bAllowCubeMapSetting"))
	TObjectPtr<UTextureCube> Cubemap;

	UPROPERTY(Transient)
	TObjectPtr<UTextureCube> DestinationCubemap;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleInstanceOnly, Category="SkyLightValues")
	uint8 bAllowCubeMapSetting : 1;
#endif

};

USTRUCT()
struct FThreatCloudValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FCloudColorState CloudActivated;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	FCloudColorState CloudDeactivated;

};

USTRUCT()
struct FDayPhaseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PhaseStartAnnouncement;

	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	float TimePhaseBegins;

	UPROPERTY(VisibleAnywhere, Transient, Category="DayNightCycle")
	float PhaseLengthInHours;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0.0"))
	float PercentageTransitionIn;

	UPROPERTY(VisibleAnywhere, Category="DayNightCycle", meta=(ClampMax="1200", ClampMin="0", UIMax="1200", UIMin="0.0"))
	float TransitionInTimeInMinutes;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0.0"))
	float PercentageTransitionOut;

	UPROPERTY(VisibleAnywhere, Category="DayNightCycle", meta=(ClampMax="1200", ClampMin="0", UIMax="1200", UIMin="0.0"))
	float TransitionOutTimeInMinutes;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Sky Light"))
	FSkyLightValues SkyLightValues;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Threat Cloud"))
	FThreatCloudValues ThreatCloudValues;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Elemental Char"))
	FElementalCharValues ElementalCharValues;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Directional Light"))
	FDirectionalLightValues DirectionalLightValues;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Exponential Height Fog"))
	FExponentialHeightFogValues ExpHeightFogValues;

	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(DisplayName="Sky Atmosphere"))
	FSkyAtmosphereValues SkyAtmosphereValues;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> LowPriPostProcessComponent;

	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	TObjectPtr<UMaterialInstance> SkyMaterialInstance;

	UPROPERTY(EditAnywhere, Category="DayNightCycle")
	TObjectPtr<UMaterialInstance> StarMapMaterialInstance;

};

USTRUCT(BlueprintType)
struct FInhibitorData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="InhibitorData")
	TObjectPtr<AActor> Inhibitor;

	UPROPERTY(BlueprintReadWrite, Category="InhibitorData")
	FDateTime LastModifiedDate;

	UPROPERTY(BlueprintReadWrite, Category="InhibitorData")
	FVector VolumeScaledExtent;

	UPROPERTY(BlueprintReadWrite, Category="InhibitorData")
	bool bIsVolumeInhibitor;

};

USTRUCT(BlueprintType)
struct FTimeOfDayDirectOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bOverrideLightIntensity : 1;

	UPROPERTY()
	uint8 bOverrideLightColor : 1;

	UPROPERTY()
	uint8 bOverrideSkyLightIntensity : 1;

	UPROPERTY()
	uint8 bOverrideSkyLightColor : 1;

	UPROPERTY()
	uint8 bOverrideFogDensity : 1;

	UPROPERTY()
	uint8 bOverrideFogColor : 1;

	UPROPERTY()
	uint8 bOverrideFogStartDistance : 1;

	UPROPERTY()
	uint8 bOverrideTODMSkylightCubemap : 1;

	UPROPERTY()
	float OverriddenLightIntensity;

	UPROPERTY()
	FLinearColor OverriddenLightColor;

	UPROPERTY()
	float OverriddenSkyLightIntensity;

	UPROPERTY()
	FLinearColor OverriddenSkyLightColor;

	UPROPERTY()
	float OverriddenFogDensity;

	UPROPERTY()
	float OverriddenFogStartDistance;

	UPROPERTY()
	FLinearColor OverriddenFogColor;

	UPROPERTY()
	TSubclassOf<UObject> OverriddenPostProcessActorClass;

	UPROPERTY()
	int32 ReplicationIndex;

};

UCLASS(Config=Game, Transient, NotPlaceable, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Transformation", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), ClassGroup=("Fog"))
class AFortTimeOfDayManager : public AInfo, public IFortInitializationInterface, public IFortTimeOfDayManagerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="DayNightCycle")
	void AddLightAndFogPhaseSettingOverride(EFortDayPhase DayPhase, TSubclassOf<UFortDayPhaseInfoOverride> DayPhaseInfoOverride, float BlendInLength = 10.000000f);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="DayNightCycle")
	void AddLightAndFogPhaseSettingOverrideMulticast(EFortDayPhase DayPhase, TSubclassOf<UFortDayPhaseInfoOverride> DayPhaseInfoOverride, float BlendInLength = 10.000000f);

	UFUNCTION(BlueprintCallable, Category="Overrides")
	void ApplyInhibitorFogOverrides(float FogDensity, FLinearColor FogColor, float FogStartDistance);

	UFUNCTION(BlueprintCallable, Category="DayNightCycle")
	void BlendLightAndFogPhaseSettingOverride(float Alpha);

	UFUNCTION(BlueprintPure, Category="Height Fog")
	static void BreakExponentialHeightFogValues(FExponentialHeightFogValues HeightFogValues, float& FogDensity, float& FogHeightFalloff, float& FogMaxOpacity, float& StartDistance, float& DirectionalInscatteringExponent, float& DirectionalInscatteringStartDistance, FLinearColor& DirectionalInscatteringColor, FLinearColor& FogInscatteringColor, float& VolumetricFogScatteringDistribution, float& VolumetricFogExtinctionScale, float& VolumetricFogDistance);

	UFUNCTION(BlueprintCallable)
	void DisableGlobalInhibitor(const FInhibitorData& InhibitorData);

	UFUNCTION(BlueprintCallable)
	void DisableVolumeInhibitor(const FInhibitorData& InhibitorData);

	UFUNCTION(BlueprintCallable)
	void EnableGlobalInhibitor(const FInhibitorData& InhibitorData);

	UFUNCTION(BlueprintCallable)
	void EnableVolumeInhibitor(const FInhibitorData& InhibitorData);

	UFUNCTION(BlueprintCallable, Category="DayNightCycle")
	void EndBlendLightAndFogPhaseSettingOverride();

	UFUNCTION(BlueprintPure, Category="Overrides")
	FLinearColor GetDirectOverrideFogColor() const;

	UFUNCTION(BlueprintPure, Category="Overrides")
	float GetDirectOverrideFogDensity() const;

	UFUNCTION(BlueprintPure, Category="Overrides")
	float GetDirectOverrideFogStartDistance() const;

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	AActor* GetLastEnabledInhibitor() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Storms")
	float GetSafeZoneGamePhaseTimeRemaining() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Storms")
	float GetStormStrength() const;

	UFUNCTION(BlueprintPure, Category="ThreatVisuals")
	TArray<FThreatLocationInfo> GetThreatClouds() const;

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	bool HasInhibitors() const;

	UFUNCTION(BlueprintCallable)
	void Inhibitor_SetDefaultSettings();

	UFUNCTION(BlueprintPure, Category="Height Fog")
	static FExponentialHeightFogValues MakeExponentialHeightFogValues(float FogDensity, float FogHeightFalloff, float FogMaxOpacity, float StartDistance, float DirectionalInscatteringExponent, float DirectionalInscatteringStartDistance, FLinearColor DirectionalInscatteringColor, FLinearColor FogInscatteringColor, float VolumetricFogScatteringDistribution, float VolumetricFogExtinctionScale, float VolumetricFogDistance);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(CallInEditor="true"))
	void OnDataDrivenCVarChangedEditorOnly(const FString& CVarName);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDayPhaseChange();

	UFUNCTION()
	virtual void OnRep_HeightFogEnabled();

	UFUNCTION()
	virtual void OnRep_TimeOfDay();

	UFUNCTION()
	virtual void OnRep_TimeOfDayInit(const float OldTimeOfDay);

	UFUNCTION()
	virtual void OnRep_TimeOfDaySpeed(const float OldTimeOfDaySpeed);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnStormEnd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnStormStart();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnUpdateDirectionalLightForTimeOfDay(const FLinearColor& AboutToApplyDirectionalLightColor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnWeatherEnd(int32 WeatherEventIndex);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnWeatherStart(int32 WeatherEventIndex);

	UFUNCTION(BlueprintCallable, Category="DayNightCycle")
	void RemoveLightAndFogPhaseSettingOverride(EFortDayPhase DayPhase, float BlendOutLength = 10.000000f);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="DayNightCycle")
	void RemoveLightAndFogPhaseSettingOverrideMulticast(EFortDayPhase DayPhase, float BlendOutLength = 10.000000f);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Storms")
	void SetDirectionalLightColorMultiplier(float NewDirectionalLightColorMultiplier);

	UFUNCTION(BlueprintCallable)
	void SetDirectionalLightComponentRotation(const FQuat& NewQuat, bool bInEditor, float DeltaTime);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Storms")
	void SetFogDirectionalInscatteringMultiplier(float NewFogDirectionalInscatteringMultiplier);

	UFUNCTION(BlueprintCallable)
	void SetRealTimeCaptureAndUpdateSkyCapture(bool bIsRealCaptureActive);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	void SetSpecificTimeOfDayInEditor(float NewTimeOfDayInEditor);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Storms")
	void SetStormStrength(float NewStormStrength);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	void SetUseSpecificTimeOfDayEditing(bool bShouldUseSpecificTimeOfDay);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Storms")
	void ToggleDebugForceStormEffects();

	UFUNCTION(BlueprintCallable)
	void TryToUpdateFogForInhibitors();

	UFUNCTION(BlueprintCallable)
	void UpdateInhibitorLastModificationDate(const FInhibitorData& InhibitorData);

	UFUNCTION(BlueprintCallable)
	void UpdatePostProcessVolumes(EFortDayPhase InCurrentTimeOfDayEditing);

	UFUNCTION(BlueprintCallable)
	void UpdatePostProcessVolumesV2(EFortTODMPostProcess::Type InCurrentTimeOfDayEditing);

	UPROPERTY(BlueprintAssignable)
	FDominantInhibitorSignature InhibitorFogUpdated;

	UPROPERTY()
	FDominantInhibitorSignature OnInhibitorRestoreDefaultSettings;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> DefaultSkydomeMaterial;

	UPROPERTY()
	TArray<FInhibitorData> EnabledVolumeInhibitors;

	UPROPERTY()
	TArray<FInhibitorData> EnabledGlobalInhibitors;

	UPROPERTY()
	TObjectPtr<AActor> LastEnabledInhibitor;

protected:
	UFUNCTION()
	void OnRep_DirectOverrides();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EditorViewSettings", meta=(EditCondition="!bUseSpecificTimeOfDayEditing"))
	EFortDayPhase CurrentTimeOfDayEditing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="EditorViewSettings")
	float CurrentTimeOfDayEditingInHours;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EditorViewSettings", meta=(DisplayName="Use Specific Time Of Day In Editor"))
	bool bUseSpecificTimeOfDayEditing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EditorViewSettings", meta=(DisplayName="Specific Time Of Day In Editor", EditCondition="bUseSpecificTimeOfDayEditing"))
	FString SpecificTimeOfDayEditingString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EditorViewSettings", meta=(ClampMax="24", ClampMin="0", DisplayName="Specific Time Of Day In Editor Scrubber", EditCondition="bUseSpecificTimeOfDayEditing", UIMax="24", UIMin="0"))
	float SpecificTimeOfDayEditing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EditorViewSettings", meta=(DisplayName="PIE With Time Frozen"))
	bool bPIEWithTimeFrozen;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bUseOverrideLightAngle;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EditorViewSettings", meta=(editcondition="bUseOverrideLightAngle"))
	FRotator OverrideLightAngle;
#endif

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TimeOfDayInit, Category="TimeOfDay")
	float TimeOfDay;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TimeOfDay)
	float TimeOfDayReplicated;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TimeOfDay")
	EFortDayPhase CurrentDayNightPhase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TimeOfDay")
	EFortDayPhase TransitionFromPhase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TimeOfDay")
	EFortDayPhase TransitionToPhase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TimeOfDay")
	float TransitionBlendPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle", meta=(ClampMax="10000.0", ClampMin="0", UIMax="10000.0", UIMin="0.0"))
	float DefaultTimeOfDaySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle", meta=(ClampMax="24", ClampMin="0", UIMax="24", UIMin="0"))
	float StartTimeOfDayInGame;

	UPROPERTY(EditDefaultsOnly, Config, Category="DayNightCycle", meta=(UIMax="1.0", UIMin="0.0"))
	float DaylightRotationRateGain;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TimeOfDaySpeed, Category="TimeOfDay")
	float TimeOfDaySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PostProcess")
	TObjectPtr<UMaterialInterface> BasePostProcessMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> PostProcessMaterialMID;

	UPROPERTY(Transient, DuplicateTransient)
	uint32 bHasClonedPPVs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DayNightCycle", meta=(DisplayName="Skip Night"))
	uint8 bSkipNight : 1;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	uint8 bUsePerDayPhaseSkylightCubemaps : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bTimeStarted : 1;

	UPROPERTY(ReplicatedUsing=OnRep_HeightFogEnabled)
	uint8 bHeightFogEnabled : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="HeightFogAltitudeSettings")
	uint8 bBaseHeightFogOnAltitude : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="HeightFogAltitudeSettings")
	float HeightFogZOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="HeightFogAltitudeSettings")
	TArray<FCameraAltitudeAdjustments> AltitudeAdjustments;

	UPROPERTY(EditDefaultsOnly, Config, Category="HeightFogAltitudeSettings")
	TArray<FCameraAltitudeAdjustments> AltitudeAdjustmentsForSecondFog;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle")
	FRotator SunriseDirectionalLightRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle")
	FRotator SunsetDirectionalLightRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TimeOfDay")
	FQuat DirectionalLightQuat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle")
	FRotator SunriseSunObjectRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle")
	FRotator SunsetSunObjectRotation;

	UPROPERTY(EditAnywhere, Config, Category="DayNightCycle")
	float SunObjectDivergencePower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle")
	bool bUseSkyAtmosphereRotationAndDivergence;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle", meta=(editcondition="bUseSkyAtmosphereRotationAndDivergence"))
	FRotator SunriseSkyAtmosphereRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="DayNightCycle", meta=(editcondition="bUseSkyAtmosphereRotationAndDivergence"))
	FRotator SunsetSkyAtmosphereRotation;

	UPROPERTY(EditAnywhere, Config, Category="DayNightCycle", meta=(editcondition="bUseSkyAtmosphereRotationAndDivergence"))
	float SkyAtmosphereRotationDivergencePower;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="TimeOfDay")
	float DistanceToSunOrMoon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="TimeOfDay")
	bool bStartInvisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UDirectionalLightComponent> DirectionalLightComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortTimeOfDayManager")
	TObjectPtr<UTextureCube> OverrideCubemap;

	UPROPERTY(EditAnywhere, Config, Category="DayNightCycle", meta=(ArraySizeEnum="/Script/FortniteGame.EFortDayPhase", DisplayName="Day Phase Settings"))
	FDayPhaseInfo LightAndFogPhaseSettings[4];

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortDayPhase"))
	TObjectPtr<UFortDayPhaseInfoOverride> LightAndFogPhaseSettingOverrides[4];

	UPROPERTY(Transient)
	uint8 bBlendingInLightAndFogOverrides : 1;

	UPROPERTY(Transient)
	uint8 bBlendingOutLightAndFogOverrides : 1;

	UPROPERTY(Transient)
	EFortDayPhase BlendingOutLightAndFogOverridesDayPhase;

	UPROPERTY(Transient)
	float LightAndFogOverridesFadeTime;

	UPROPERTY(Transient)
	float CurrentLightAndFogBlendValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, ReplicatedUsing=OnRep_DirectOverrides, Category="DayNightCycle")
	FTimeOfDayDirectOverrides DirectOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> MorningPostProcessComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> DayPostProcessComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> EveningPostProcessComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> NightPostProcessComponent;

	UPROPERTY(Transient, DuplicateTransient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortDayPhase", EditInline="true"))
	TObjectPtr<UPostProcessComponent> DayPhasePostProcessComponent[4];

	UPROPERTY(Transient, DuplicateTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> OverridePostProcessComponent;

	UPROPERTY(BlueprintReadWrite, Category="DayNightCycle", meta=(DisplayName="Exponential Height Fog"))
	FExponentialHeightFogValues CurrentTimeOfDayFogValues;

	UPROPERTY(BlueprintReadWrite, Category="DayNightCycle", meta=(DisplayName="Directional Light Color"))
	FLinearColor CurrentTimeOfDayDirectionalLightColor;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialParameterCollectionInstance> MaterialParameterCollectionInstance;

	UPROPERTY(EditDefaultsOnly, Config, Category="DayNightCycle")
	FVector RainParticleSystemRelativeOffset;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TObjectPtr<UStaticMesh> SunMesh;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TObjectPtr<UStaticMesh> MoonMesh;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TArray<TObjectPtr<UMaterialInterface>> SunMaterialOverrides;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TArray<TObjectPtr<UMaterialInterface>> MoonMaterialOverrides;

	UPROPERTY(EditDefaultsOnly, Config, Category="DayNightCycle")
	float SunScale;

	UPROPERTY(EditDefaultsOnly, Config, Category="DayNightCycle")
	float MoonScale;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<UMaterialInterface> SkyDomeMaterial;

	UPROPERTY(Transient, DuplicateTransient)
	TObjectPtr<UMaterialInterface> StarMapMaterial;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TObjectPtr<UTexture2D> CloudMaskTexture;

	UPROPERTY(EditDefaultsOnly, Config, Category="StormBlendValues")
	bool bUseStormValues;

	UPROPERTY(EditDefaultsOnly, Config, Category="StormBlendValues")
	FLinearColor StormLightColor;

	UPROPERTY(EditDefaultsOnly, Category="StormBlendValues")
	TObjectPtr<UMaterialInstance> StormMaterialInst;

	UPROPERTY(EditDefaultsOnly, Config, Category="StormBlendValues")
	FExponentialHeightFogValues StormFogValues;

	UPROPERTY(Transient, BlueprintAssignable)
	FDayNightPhaseChangeSignature OnDayPhaseChangeEvent;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortTimeOfDayWeatherComponent> OriginalWeatherComponent;
#endif

	UPROPERTY(EditDefaultsOnly, Config, Category="Weather")
	bool DisableGlobalWeatherEvents;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WeatherComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortTimeOfDayWeatherComponent> WeatherComponent;

private:
	UFUNCTION()
	void OnRep_ServerTODIsVisible();

	UFUNCTION()
	void OnRep_WeatherComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UExponentialHeightFogComponent> ActiveHeightFogComponent;

	UPROPERTY()
	TObjectPtr<UFortDayPhaseChangeParams> DayPhaseChangeEventParams;

	UPROPERTY(Transient)
	TArray<FDayNightPhaseChangeSignature> DelegatesQueuedForProcessingDayPhaseChange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkyLightComponent> SkyLightComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UParticleSystemComponent> RainParticleSystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SunOrMoonMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SkyDomeMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StarMapMeshComp;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> ActiveSkyBoxMat;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> StarMapMID;

	UPROPERTY(Transient)
	float StormStrength;

	UPROPERTY(ReplicatedUsing=OnRep_ServerTODIsVisible)
	bool bServerTODIsVisible;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE"))
	FOnWeatherComponentSetSignature OnWeatherComponentSet;

};

