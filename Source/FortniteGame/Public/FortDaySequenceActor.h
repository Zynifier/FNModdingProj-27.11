// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "DaySequenceActor.h"
#include "FortTimeOfDayManagerInterface.h"
#include "FortDaySequenceActor.generated.h"

class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class UNiagaraComponent;
class USceneComponent;
class USkyAtmosphereComponent;
class USkyLightComponent;
class UStaticMeshComponent;
class UTextureCube;
class UVolumetricCloudComponent;

USTRUCT()
struct FFortDayPhaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DayNightCycle", meta=(ClampMax="23.99", ClampMin="0", UIMax="23.99", UIMin="0.0"))
	float StartTime;

};

UCLASS(Config=Game, Transient, NotPlaceable, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortDaySequenceActor : public ADaySequenceActor, public IFortTimeOfDayManagerInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sequence")
	TMap<FName, FDaySequenceAssetData> ScalabilitySequences;

protected:
	UFUNCTION(meta=(CallInEditor="true"))
	void HandleAntiAliasingQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleEffectsQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleGlobalIlluminationQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandlePostProcessQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleReflectionQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleShadowQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleTextureQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleViewDistanceQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnAntiAliasingQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnEffectsQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnGlobalIlluminationQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnPostProcessQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnReflectionQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnShadowQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnTextureQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, meta=(CallInEditor="true"))
	void OnTimeOfDayManagerVisibilitySet(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnViewDistanceQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, meta=(CallInEditor="true"))
	void TEMPHACK_TickTimeOfDay();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Sequence", meta=(CallInEditor="true"))
	void UpdateScalabilitySequences();

private:
	UFUNCTION()
	void OnRep_ServerTodIsVisible();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USceneComponent> SunRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UDirectionalLightComponent> SunComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UExponentialHeightFogComponent> ExponentialHeightFogComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SkyDomeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkyAtmosphereComponent> SkyAtmosphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkyLightComponent> SkyLightComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UVolumetricCloudComponent> VolumetricCloudComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UNiagaraComponent> SunFlareComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="DayNightCycle", meta=(AllowPrivateAccess="true"))
	FVector LightDirection;

	UPROPERTY(EditAnywhere, Config, Category="DayNightCycle")
	bool bStartInvisible;

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle", meta=(ArraySizeEnum="/Script/FortniteGame.EFortDayPhase"))
	FFortDayPhaseData DayPhaseInfo[4];

	UPROPERTY(EditDefaultsOnly, Category="DayNightCycle")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialParameterCollectionInstance> MaterialParameterCollectionInstance;

	UPROPERTY(EditDefaultsOnly, Category="PostProcess")
	TObjectPtr<UMaterialInterface> OutlinePostProcessMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> OutlinePostProcessMID;

	UPROPERTY(EditAnywhere, Category="Sun")
	bool bUseSunAngle;

	UPROPERTY(EditAnywhere, Category="Sun")
	bool bUseSunDivergence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Sun", meta=(EditCondition="bUseSunAngle", AllowPrivateAccess="true"))
	float SunAngle;

	UPROPERTY(EditAnywhere, Category="Sun", meta=(EditCondition="bUseSunAngle && bUseSunDivergence"))
	float SunLightHorizonClamp;

	UPROPERTY(EditAnywhere, Category="Skylight")
	bool bUseSkyLightCubeMapBlending;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Skylight", meta=(AllowPrivateAccess="true"))
	float SkyLightCubeMapBlend;

	UPROPERTY(EditAnywhere, Category="Skylight", meta=(EditCondition="bUseSkyLightCubeMapBlending"))
	TArray<TObjectPtr<UTextureCube>> SkyLightCubeMaps;

	UPROPERTY(ReplicatedUsing=OnRep_ServerTODIsVisible)
	bool bServerTODIsVisible;

};

