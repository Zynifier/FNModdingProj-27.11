// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Building/BuildingAutoNav.h"
#include "Building/BuildingSMActor.h"
#include "BuildingTimeOfDayLights.generated.h"

class ULightComponent;
class UMaterial;
class UMaterialInstanceDynamic;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FBuildingTimeOfDayLightsActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Building|TimeOfDayLights", meta=(GetByRef))
	TObjectPtr<UMaterial> FourLayerMaterial;

};

USTRUCT(BlueprintType)
struct FNativeBuildingPropFourLayerMaterial
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="NativeBuildingPropFourLayerMaterial")
	int32 Index;

	UPROPERTY(BlueprintReadWrite, Category="NativeBuildingPropFourLayerMaterial")
	TObjectPtr<UMaterialInstanceDynamic> MID;

	UPROPERTY(BlueprintReadWrite, Category="NativeBuildingPropFourLayerMaterial")
	TMap<FName, FLinearColor> EmissiveColors;

};

USTRUCT(BlueprintType)
struct FNativeDayPhaseFloats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="NativeDayPhaseFloats")
	float Morning;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="NativeDayPhaseFloats")
	float Day;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="NativeDayPhaseFloats")
	float Evening;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="NativeDayPhaseFloats")
	float Night;

};

USTRUCT(BlueprintType)
struct FTimeOfDayBlueprintDefaultVariables
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|TimeOfDayLights")
	TObjectPtr<UStaticMesh> AlternateShadowStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|TimeOfDayLights")
	float VolumetricLightScatteringIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|TimeOfDayLights")
	bool bDisableTODLightsAndMaterialEmissiveValues;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|TimeOfDayLights")
	bool bDisableStaticMeshShadowCastingWhenLightsAreActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|TimeOfDayLights")
	bool bUseAnAlternateShadowMeshWhenTheLightIsOff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Building|TimeOfDayLights")
	bool bCastVolumetricShadows;

};

USTRUCT(BlueprintType)
struct FTimeOfDayControlledLightData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="TimeOfDayControlledLightData", meta=(EditInline="true"))
	TObjectPtr<ULightComponent> LightComponent;

	UPROPERTY(BlueprintReadOnly, Category="TimeOfDayControlledLightData")
	FVector Position;

	UPROPERTY(BlueprintReadOnly, Category="TimeOfDayControlledLightData")
	float InitialIntensity;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTimeOfDayLightsActorClassData)
class ABuildingTimeOfDayLights : public ABuildingAutoNav
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void AnimateLightParameters(const TArray<FTimeOfDayControlledLightData>& LightData, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay, const float DayPhaseTransitionLength);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void AnimateMidValuesForLightsFourLayer(const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay, const float DayPhaseTransitionLength);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void DoDayPhaseChangedLightAnimation(const bool bIsAtCreation, UPARAM(ref) TArray<FLinearColor>& EmissiveMultipliers, UPARAM(ref) TArray<float>& LightConeOpacities, const TArray<FTimeOfDayControlledLightData>& LightData, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay, const float DayPhaseTransitionLength, const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API float FindScalarValueAcrossTimeOfDayPhaseFloats(const FNativeDayPhaseFloats& DayPhaseFloats, const float Alpha);

	UFUNCTION(BlueprintNativeEvent, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void GetTimeOfDayBlueprintDefaultVariables(FTimeOfDayBlueprintDefaultVariables& OutVariables);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void HandleBaseSimpleFourLayerMaterials(const float Duration, const float Start, const float End);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void InitializeLightValuesAndStoreMaterials(TArray<FLinearColor>& EmissiveMultipliers, TArray<float>& LightConeOpacities, const TArray<FTimeOfDayControlledLightData>& LightData, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay, const float DayPhaseTransitionLength, const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void SetLightIntensityByDayPhase(ULightComponent* LightComponent, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay);

	UFUNCTION(BlueprintCallable, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API void SetMidValuesForLights(const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay, const TArray<float>& LightConeOpacities, const float DayPhaseTransitionLength, const TArray<FLinearColor>& EmissiveMultipliers);

	UFUNCTION(BlueprintPure, Category="Building|TimeOfDayLights")
	FORTNITEGAME_API bool UseNativeLightAnimation() const;

	UPROPERTY(BlueprintReadOnly, Category="Building|TimeOfDayLights")
	TArray<FTimeOfDayControlledLightData> TimeOfDayControlledLightDataArray;

	UPROPERTY(BlueprintReadWrite, Category="Building|TimeOfDayLights")
	TArray<FNativeBuildingPropFourLayerMaterial> FourLayerColorInfo;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterial> FourLayerMaterial_DEPRECATED;
#endif

};

