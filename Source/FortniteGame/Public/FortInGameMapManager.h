// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Fonts/SlateFontInfo.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortInitializationInterface.h"
#include "FortMiniMapInterface.h"
#include "FortTeamEnum.h"
#include "FortWorldSettings.h"
#include "FortInGameMapManager.generated.h"

class AActor;
class AFortInGameMapManager;
class ASceneCapture2D;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UTexture2D;

UENUM()
enum class EMapCaptureMethod : int32
{
	None = 0,
	LiveCapture = 1,
	StaticCapture = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAllowShowMainMapChanged, bool, bAllowShowMainMap);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMapExplorationThresholdReached, int32, ThresholdIndex, uint8, Team);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMapFullyExplored, uint8, Team);

USTRUCT()
struct FFortIngameMapManagerCreated
{
	GENERATED_BODY()

};

USTRUCT()
struct FTeamMapExplorationEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamId;

	UPROPERTY()
	int8 ExplorationThreshold;

};

USTRUCT()
struct FTeamMapInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> ReplicatedSeedPack;

	UPROPERTY()
	uint8 TeamId;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortInGameMapManager : public AActor, public IFortInitializationInterface, public IFortMiniMapInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void AllowShowMainMap(bool bAllowShow);

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void AllowShowMiniMap(bool bAllowShow);

	UFUNCTION(BlueprintCallable, Category="UI")
	FVector2D BPWorldLocationToMapLocation(const FVector& WorldLocation, float InMapSize);

	UFUNCTION(BlueprintPure, Category="UI", meta=(DisplayName="GetUIMapManager", WorldContext="WorldContextObject"))
	static AFortInGameMapManager* GetCurrent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="InGameMap")
	bool GetStaticCaptureSetupComplete() const;

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void PaintOnFog(const FVector& WorldCoords, EFortTeam::Type Team = EFortTeam::HumanCampaign);

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void ResetCaptureLocation();

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void ResetCaptureRotation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="InGameMap")
	void ServerClearAllFog();

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void SetActorBoundaryData(float UpperZ, float LowerZ, const TArray<TSoftClassPtr<AActor>>& ClassesToHide);

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	void SetCaptureLocation(const FVector& Location);

	UFUNCTION(BlueprintPure, Category="InGameMap")
	bool ShouldShowMainMap() const;

	UPROPERTY(BlueprintAssignable, Category="InGameMap")
	FOnAllowShowMainMapChanged OnAllowShowMainMapChanged;

protected:
	UFUNCTION(NetMulticast, Reliable)
	void BroadcastExplorationEvents(const TArray<FTeamMapExplorationEvent>& Events);

	UFUNCTION()
	void OnRep_ClearAllFog();

	UFUNCTION()
	void OnRep_MapData();

	UPROPERTY(ReplicatedUsing=OnRep_MapData)
	TArray<FTeamMapInfo> MapData;

	UPROPERTY(ReplicatedUsing=OnRep_ClearAllFog)
	uint8 bClearAllFog : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	FName StaticCaptureCameraName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	int32 MapLayerSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	FMargin MapMargin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	TSubclassOf<ASceneCapture2D> SceneCaptureClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	TSubclassOf<ASceneCapture2D> SceneCaptureBlurryClass;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UMaterialInterface> MapMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MapMaterialMID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UIOptionsThatShouldNotBeHere")
	float MapOpacityWhenWalking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera")
	float OffsetZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera", meta=(ClampMax="255", ClampMin="0"))
	int32 IconVisibilityFogThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	float DelayBetweenDispersions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	float ExploredRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	float ExploredFalloffRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	float SeenRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	float SeenFalloffRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	int32 VisibilityMaxGradient;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldCamera", meta=(ClampMax="255", ClampMin="0", UIMax="255", UIMin="0"))
	int32 UnexploredOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	FCurveTableRowHandle CloudBrightnessCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera")
	FCurveTableRowHandle DesaturationFactorCurve;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldCamera", meta=(ClampMax="1.0", ClampMin="0.01", UIMax="1.0", UIMin="0.01"))
	float MaxPercentageMapExplored;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SaveTheWorldCamera", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MapExplorationThresholdPercentage;

	UPROPERTY()
	float LastMapExplorationThresholdPercentageReached;

	UPROPERTY(BlueprintAssignable, Category="SaveTheWorldCamera")
	FOnMapFullyExplored OnMapFullyExplored;

	UPROPERTY(BlueprintAssignable, Category="SaveTheWorldCamera")
	FOnMapExplorationThresholdReached OnMapExplorationThresholdReached;

	UPROPERTY(Transient)
	EMapCaptureMethod MapCaptureMethod;

	UPROPERTY(Transient)
	TObjectPtr<ASceneCapture2D> SceneCapture;

	UPROPERTY(Transient)
	TObjectPtr<ASceneCapture2D> SceneCaptureBlurry;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> FogMask;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InGameMap")
	bool bUseExplorationBasedFogOfWar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InGameMap")
	bool bShareMapWithTeam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InGameMap")
	bool bResetMapDataOnTeamSwitch;

	UPROPERTY(VisibleAnywhere, Transient, Category="Heatmap")
	TObjectPtr<UTexture2D> HeatmapMask;

	UPROPERTY(VisibleAnywhere, Transient, Category="Heatmap")
	bool bCanUpdateHeatmapMask;

	UPROPERTY()
	float MapWorldScale;

	UPROPERTY(EditAnywhere, Category="Map Locations", meta=(ArraySizeEnum="/Script/FortniteGame.EMapLocationStateType"))
	FLinearColor DefaultMapLocationFontColor[3];

	UPROPERTY(EditAnywhere, Category="Map Locations")
	FSlateFontInfo DefaultMapLocationFont;

	UPROPERTY(EditAnywhere, Category="Map Locations")
	uint32 MobileMapLocationFontSizeOverride;

	UPROPERTY(Transient)
	FSlateFontInfo MapLocationFont;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FMapLocationRenderData> MinimapLocationRenderData_Player1;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FMapLocationRenderData> MinimapLocationRenderData_Player2;

private:
	UFUNCTION(BlueprintPure, Category="InGameMap")
	UTexture2D* GetHeatmapMask() const;

	UFUNCTION(BlueprintPure, Category="InGameMap")
	float GetHeatmapMaskScale() const;

	UPROPERTY(EditAnywhere, Category="FortInGameMapManager", meta=(AllowPrivateAccess))
	TArray<TSoftClassPtr<AActor>> ActorClassesToHide;

};

