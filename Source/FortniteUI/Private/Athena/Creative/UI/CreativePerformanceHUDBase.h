// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "Building/SpatialGameplay/SpatialLoadingStateContext.h"
#include "FortHUDElementWidget.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "ObjectTracking/FortMetricInformation.h"
#include "ObjectTracking/ObjectTracking.h"
#include "CreativePerformanceHUDBase.generated.h"

class AFortGameState;
class AFortVolume;
class APlayerState;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePerformanceHUDBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Client Enter Volume"))
	void BP_OnClientEnterVolume(APlayerState* ClientPlayerState, AFortVolume* Volume);

	UFUNCTION(BlueprintCallable, Category="HUD")
	int32 GetCostPreviewOfSelectedActor();

	UFUNCTION()
	void HandleGameStateInitialized(AFortGameState* GameState);

	UFUNCTION()
	void HandleSpatialLoadingStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext);

	UFUNCTION(BlueprintImplementableEvent)
	void HideUIMetrics();

	UFUNCTION(BlueprintPure, Category="HUD")
	bool IsHeatmapEnabled() const;

	UFUNCTION()
	void OnCostPreviewOfSelectionChanged();

	UFUNCTION()
	void OnPerformanceMetricsUpdated(const FVolumePerformanceMetrics& VolumePerformanceMetrics);

	UFUNCTION()
	void OnPlayerEnteredSpatialGameplayActor(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& PlayerEnterSpatialActorContext);

	UFUNCTION()
	void OnPlayerExitedSpatialGameplayActor(FEventMessageTag Channel, const FPlayerExitSpatialActorContext& PlayerExitSpatialActorContext);

	UFUNCTION()
	void OnSimpleMetricInformationUpdated(APlayerState* ClientState, const FSimpleMetricInformation& MetricInformation);

	UFUNCTION()
	void OnVolumeTrackingComponentReplicated();

	UFUNCTION(BlueprintImplementableEvent)
	void RefreshCostPreviewOfSelectedActor(const int32 CostPreviewOfSelection, const bool isThrowingPlayset);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSimpleUIMetrics(const FSimpleMetricInformation& SimplePerformanceMetrics);

	UFUNCTION(BlueprintImplementableEvent)
	void SetUIMetrics(const FVolumePerformanceMetrics& VolumePerformanceMetrics);

	UFUNCTION(BlueprintPure, Category="HUD")
	static bool ShowBudgetGridThermometerCoordinates();

	UFUNCTION(BlueprintCallable, Category="HUD")
	void StartTimer();

	UFUNCTION(BlueprintCallable, Category="HUD")
	void StopTimer();

};

