// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortInGameMapManagerAthena.h"
#include "FortWorldSettings.h"
#include "FortInGameMapManagerCreative.generated.h"

class AFortMinigame;
class AFortVolume;
class ASceneCapture2D;
class UFortVolumeObjectTrackingComponent;
class UMaterialInterface;
enum class EFortCreativeHeatmapDrawState : uint8;

UENUM(BlueprintType)
enum class EFortCreativeHeatmapDrawState : uint8
{
	Visible = 0,
	VisibleWithValues = 1,
	NotVisible = 2,
	Count = 3 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHeatmapDrawStateChangedDelegate, EFortCreativeHeatmapDrawState, NewState);

USTRUCT()
struct FFortSceneCaptureData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ASceneCapture2D> SceneCapture;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortInGameMapManagerCreative : public AFortInGameMapManagerAthena
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortCreativeHeatmapDrawState GetHeatmapDrawState() const;

	UPROPERTY(BlueprintAssignable)
	FHeatmapDrawStateChangedDelegate OnHeatmapDrawStateChanged;

protected:
	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void SetCurrentVolume(AFortVolume* InVolume);

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void SetDefaultSceneCapture();

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void SetOverrideSceneCapture(FVector Location, FRotator Rotation, float Width, float Zoom, bool bUseClippingPlanes, float NearClipLength = -1.000000f, float FarClipLength = -1.000000f);

	UPROPERTY(EditDefaultsOnly, Category="FortInGameMapManagerCreative")
	TObjectPtr<UMaterialInterface> HeatmapEnabledMapMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortInGameMapManagerCreative")
	TObjectPtr<UMaterialInterface> HeatmapDisabledMapMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortInGameMapManagerCreative")
	TArray<FLinearColor> HeatmapColorRange;

	UPROPERTY(EditAnywhere, Category="Minimap")
	TObjectPtr<UMaterialInterface> HighMemMaterial;

	UPROPERTY(EditAnywhere, Category="Minimap")
	TObjectPtr<UMaterialInterface> LockedMaterial;

	UPROPERTY(EditDefaultsOnly, Category="HeatmapValues")
	FSlateFontInfo HeatmapValuesFontInfo;

	UPROPERTY(EditDefaultsOnly, Category="HeatmapValues")
	FSlateFontInfo HeatmapValuesMinimapFontInfo;

	UPROPERTY(EditDefaultsOnly, Category="HeatmapValues")
	int32 HeatmapMinValueForVisibility;

	UPROPERTY(EditDefaultsOnly, Category="FortInGameMapManagerCreative")
	float HeatmapColorAlpha;

	UPROPERTY(EditDefaultsOnly, Category="FortInGameMapManagerCreative")
	FScalableFloat bShowLocationNames;

private:
	UFUNCTION()
	void OnPlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode);

	UFUNCTION()
	void OnVolumeObjectTrackingComponentChanged(UFortVolumeObjectTrackingComponent* InVolumeObjectTrackingComponent);

	UPROPERTY()
	TObjectPtr<UMaterialInterface> CreativeMapMaterial;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FMapLocationRenderData> EmptyMinimapLocationRenderData;

};

