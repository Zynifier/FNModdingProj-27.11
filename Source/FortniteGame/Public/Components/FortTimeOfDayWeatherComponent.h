// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Scene.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "FortTimeOfDayWeatherComponent.generated.h"

class UCurveFloat;
class UCurveLinearColor;
class UCurveVector;
class UMaterialInstance;
class UMaterialInstanceDynamic;
class UPostProcessComponent;
enum class EGlobalWeatherState : uint8;

UENUM(BlueprintType)
enum class EGlobalWeatherState : uint8
{
	Inactive = 0,
	Active = 1,
	BlendingIn = 2,
	BlendingOut = 3,
};

USTRUCT(BlueprintType)
struct FFortReplicatedWeatherEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Data")
	int32 Index;

	UPROPERTY(BlueprintReadOnly, Category="Data")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="Data")
	float EndTime;

	UPROPERTY(BlueprintReadOnly, Category="Data")
	float BlendInDuration;

	UPROPERTY(BlueprintReadOnly, Category="Data")
	float BlendOutDuration;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherChangedSignature, EGlobalWeatherState, WeatherState, FFortReplicatedWeatherEventData, WeatherData);

USTRUCT()
struct FAIWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AIWeatherData")
	FScalableFloat SightRadiusClamp;

	UPROPERTY(EditDefaultsOnly, Category="AIWeatherData")
	FScalableFloat LoseSightRadiusClamp;

	UPROPERTY(EditDefaultsOnly, Category="AIWeatherData")
	FScalableFloat RequiredBlendPercentageThreshold;

};

USTRUCT()
struct FFortTimeOfDayCurve_Float
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortTimeOfDayCurve_Float", meta=(EditCondition="bUseCurve"))
	TObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditAnywhere, Category="FortTimeOfDayCurve_Float", meta=(EditCondition="!bUseCurve"))
	float FlatValue;

	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bUseCurve;

};

USTRUCT()
struct FFortTimeOfDayCurve_LinearColor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortTimeOfDayCurve_LinearColor", meta=(EditCondition="bUseCurve"))
	TObjectPtr<UCurveLinearColor> Curve;

	UPROPERTY(EditAnywhere, Category="FortTimeOfDayCurve_LinearColor", meta=(EditCondition="!bUseCurve"))
	FLinearColor FlatValue;

	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bUseCurve;

};

USTRUCT(BlueprintType)
struct FDirectionalLightWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_DirectionalLightColor : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_DirectionalLightColorWeight : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_DirectionalLightColorBrightness : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_VolumetricScatteringIntensity : 1;

	UPROPERTY(EditAnywhere, Category="DirectionalLightWeatherData", meta=(EditCondition="bOverride_DirectionalLightColor"))
	FFortTimeOfDayCurve_LinearColor DirectionalLightColor;

	UPROPERTY(EditAnywhere, Category="DirectionalLightWeatherData", meta=(EditCondition="bOverride_DirectionalLightColorWeight"))
	FFortTimeOfDayCurve_Float DirectionalLightColorWeight;

	UPROPERTY(EditAnywhere, Category="DirectionalLightWeatherData", meta=(EditCondition="bOverride_DirectionalLightColorBrightness"))
	FFortTimeOfDayCurve_Float DirectionalLightColorBrightness;

	UPROPERTY(EditAnywhere, Category="DirectionalLightWeatherData", meta=(EditCondition="bOverride_VolumetricScatteringIntensity"))
	FFortTimeOfDayCurve_Float VolumetricScatteringIntensity;

};

USTRUCT(BlueprintType)
struct FExponentialHeightFogWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogDensity : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogHeightFalloff : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogMaxOpacity : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogStartDistance : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogDirectionalInscatteringExponent : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogDirectionalInscatteringStartDistance : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogDirectionalInscatteringColor : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogInscatteringColor : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogScatteringDistribution : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogAlbedo : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogExtinctionScale : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_FogDistance : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_SecondFogDensity : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_SecondFogHeightFalloff : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_SecondHeightFogOffset : 1;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogDensity"))
	FFortTimeOfDayCurve_Float FogDensity;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogHeightFalloff"))
	FFortTimeOfDayCurve_Float FogHeightFalloff;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogMaxOpacity"))
	FFortTimeOfDayCurve_Float FogMaxOpacity;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogStartDistance"))
	FFortTimeOfDayCurve_Float FogStartDistance;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogDirectionalInscatteringExponent"))
	FFortTimeOfDayCurve_Float FogDirectionalInscatteringExponent;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogDirectionalInscatteringStartDistance"))
	FFortTimeOfDayCurve_Float FogDirectionalInscatteringStartDistance;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogDirectionalInscatteringColor"))
	FFortTimeOfDayCurve_LinearColor FogDirectionalInscatteringColor;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogInscatteringColor"))
	FFortTimeOfDayCurve_LinearColor FogInscatteringColor;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogScatteringDistribution"))
	FFortTimeOfDayCurve_Float FogScatteringDistribution;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogAlbedo"))
	FFortTimeOfDayCurve_LinearColor FogAlbedo;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogExtinctionScale"))
	FFortTimeOfDayCurve_Float FogExtinctionScale;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_FogDistance"))
	FFortTimeOfDayCurve_Float FogDistance;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_SecondFogDensity"))
	FFortTimeOfDayCurve_Float SecondFogDensity;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_SecondFogHeightFalloff"))
	FFortTimeOfDayCurve_Float SecondFogHeightFalloff;

	UPROPERTY(EditAnywhere, Category="ExponentialHeightFogWeatherData", meta=(EditCondition="bOverride_SecondHeightFogOffset"))
	FFortTimeOfDayCurve_Float SecondHeightFogOffset;

};

USTRUCT()
struct FFortTimeOfDayCurve_Vector
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortTimeOfDayCurve_Vector", meta=(EditCondition="bUseCurve"))
	TObjectPtr<UCurveVector> Curve;

	UPROPERTY(EditAnywhere, Category="FortTimeOfDayCurve_Vector", meta=(EditCondition="!bUseCurve"))
	FVector FlatValue;

	UPROPERTY(meta=(InlineEditConditionToggle))
	bool bUseCurve;

};

USTRUCT(BlueprintType)
struct FHeightFogAltitudeWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_HeightFogZOffset : 1;

	UPROPERTY(EditAnywhere, Category="HeightFogAltitudeWeatherData", meta=(EditCondition="bOverride_HeightFogZOffset"))
	FFortTimeOfDayCurve_Float HeightFogZOffset;

};

USTRUCT(BlueprintType)
struct FMaterialWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MaterialWeatherData")
	TObjectPtr<UMaterialInstance> SkyMaterialInstance;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> DynamicSkyMaterialInstance;

};

USTRUCT(BlueprintType)
struct FSkyAtmosphereWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_MieScatteringScale : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_MieAbsorptionScale : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_HeightFogContribution : 1;

	UPROPERTY(EditAnywhere, Category="SkyAtmosphereWeatherData", meta=(EditCondition="bOverride_MieScatteringScale"))
	FFortTimeOfDayCurve_Float MieScatteringScale;

	UPROPERTY(EditAnywhere, Category="SkyAtmosphereWeatherData", meta=(EditCondition="bOverride_MieAbsorptionScale"))
	FFortTimeOfDayCurve_Float MieAbsorptionScale;

	UPROPERTY(EditAnywhere, Category="SkyAtmosphereWeatherData", meta=(EditCondition="bOverride_HeightFogContribution"))
	FFortTimeOfDayCurve_Float HeightFogContribution;

};

USTRUCT(BlueprintType)
struct FSkylightWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_SkyLightColor : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_SkyLightColorWeight : 1;

	UPROPERTY(EditAnywhere, Category="SkylightWeatherData", meta=(EditCondition="bOverride_SkyLightColor"))
	FFortTimeOfDayCurve_LinearColor SkyLightColor;

	UPROPERTY(EditAnywhere, Category="SkylightWeatherData", meta=(EditCondition="bOverride_SkyLightColorWeight"))
	FFortTimeOfDayCurve_Float SkyLightColorWeight;

};

USTRUCT(BlueprintType)
struct FWindWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_WindDirection : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_WindStrength : 1;

	UPROPERTY(EditAnywhere, Category="WindWeatherData", meta=(EditCondition="bOverride_WindDirection"))
	FFortTimeOfDayCurve_Vector WindDirection;

	UPROPERTY(EditAnywhere, Category="WindWeatherData", meta=(EditCondition="bOverride_WindStrength"))
	FFortTimeOfDayCurve_Float WindStrength;

};

USTRUCT(BlueprintType)
struct FGlobalWeatherData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FString WeatherEventName;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FString RequiredCalendarEvent;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData", meta=(Categories="Tempest"))
	FGameplayTagContainer WeatherEventTags;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat EnableChanceMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat EnableChanceMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	TObjectPtr<UCurveFloat> Frequency;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(EditCondition="Frequency == nullptr"))
	FScalableFloat FrequencyMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(EditCondition="Frequency == nullptr"))
	FScalableFloat FrequencyMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	TObjectPtr<UCurveFloat> Chance;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(ClampMax="1.000000", ClampMin="0.000000", EditCondition="Chance == nullptr", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat ChanceMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(ClampMax="1.000000", ClampMin="0.000000", EditCondition="Chance == nullptr", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat ChanceMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	TObjectPtr<UCurveFloat> ChanceMultiplierOverElapsedMinutes;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat DurationMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat DurationMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat CooldownMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat CooldownMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat ChanceToRemainActiveMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat ChanceToRemainActiveMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat BlendInMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat BlendInMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat BlendOutMin;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FScalableFloat BlendOutMax;

	UPROPERTY(EditAnywhere, Category="Weather Event Data")
	FPostProcessSettings PostProcessSettings;

	UPROPERTY(EditAnywhere, Category="Weather Event Data", meta=(EditCondition="bOverride_PostProcessBlendWeight"))
	FFortTimeOfDayCurve_Float PostProcessBlendWeight;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FSkylightWeatherData SkylightWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FDirectionalLightWeatherData DirectionalLightWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FExponentialHeightFogWeatherData ExponentialHeightFogWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FSkyAtmosphereWeatherData SkyAtmosphereWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FHeightFogAltitudeWeatherData HeightFogAltitudeWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FMaterialWeatherData MaterialWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData")
	FWindWeatherData WindWeatherData;

	UPROPERTY(EditAnywhere, Category="GlobalWeatherData", meta=(DisplayName="AI Weather Data"))
	FAIWeatherData AIWeatherData;

	UPROPERTY(Transient)
	float TimeForNextAttempt;

	UPROPERTY(Transient)
	uint8 bIsEnabled : 1;

	UPROPERTY(meta=(InlineEditConditionToggle))
	uint8 bOverride_PostProcessBlendWeight : 1;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"), meta=(BlueprintSpawnableComponent))
class UFortTimeOfDayWeatherComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Global Weather")
	float GetBlendTimePercentage() const;

	UFUNCTION(BlueprintPure, Category="Global Weather")
	int32 GetCurrentWeatherEventIndex() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentWeatherIntensity() const;

	UFUNCTION(BlueprintPure)
	FVector GetCurrentWindDirection() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentWindStrength() const;

	UFUNCTION(BlueprintPure, Category="Global Weather")
	EGlobalWeatherState GetWeatherState() const;

	UFUNCTION(BlueprintPure, Category="Global Weather")
	bool IsWeatherEventActive() const;

protected:
	UFUNCTION()
	void OnRep_WeatherEventData();

	UPROPERTY(EditAnywhere, Category="Global Weather Data", meta=(TitleProperty="WeatherEventName"))
	TArray<FGlobalWeatherData> GlobalWeatherDataArray;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	FScalableFloat WeatherEventStartDelayMin;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	FScalableFloat WeatherEventStartDelayMax;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	FScalableFloat WeatherEventEndedCooldownMin;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	FScalableFloat WeatherEventEndedCooldownMax;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	FScalableFloat DisableWeather;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	EAthenaGamePhase GamePhaseToStart;

	UPROPERTY(Transient)
	bool bWeatherDisabled;

	UPROPERTY(Transient)
	bool bWeatherStarted;

	UPROPERTY(EditAnywhere, Category="Global Weather Data")
	FString CalendarEnableEvent;

	UPROPERTY(Transient)
	EGlobalWeatherState WeatherState;

	UPROPERTY(Transient)
	float WeatherStartTime;

	UPROPERTY(Transient)
	float WeatherEventAttemptStart;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WeatherEventData)
	FFortReplicatedWeatherEventData WeatherEventData;

	UPROPERTY(Transient)
	int32 LocalWeatherEventIndex;

	UPROPERTY(Transient)
	float CurrentBlendTime;

	UPROPERTY(Transient)
	float TargetBlendTime;

	UPROPERTY(Transient)
	float BlendTimeLength;

	UPROPERTY(Transient, DuplicateTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> PostProcessComponent;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="true"))
	FOnWeatherChangedSignature OnWeatherChanged;

private:
	UFUNCTION()
	void OnPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

};

