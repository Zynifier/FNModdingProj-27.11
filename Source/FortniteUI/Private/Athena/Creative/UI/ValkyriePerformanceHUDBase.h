// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "Building/SpatialGameplay/SpatialLoadingStateContext.h"
#include "FortHUDElementWidget.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "ObjectTracking/ObjectTracking.h"
#include "ValkyriePerformanceHUDBase.generated.h"

class AFortGameState;
class AFortMinigame;
class APlayerState;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UValkyriePerformanceHUDBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Client Enter Spatial Gameplay Actor"))
	void BP_OnClientEnterSpatialGameplayActor(APlayerState* ClientPlayerState);

	UFUNCTION()
	void HandleGameStateInitialized(AFortGameState* GameState);

	UFUNCTION()
	void HandleSpatialLoadingStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext);

	UFUNCTION(BlueprintImplementableEvent)
	void HideUIMetrics();

	UFUNCTION()
	void OnPlayerEnteredSpatialGameplayActor(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& PlayerEnterSpatialActorContext);

	UFUNCTION()
	void OnPlayerExitedSpatialGameplayActor(FEventMessageTag Channel, const FPlayerExitSpatialActorContext& PlayerExitSpatialActorContext);

	UFUNCTION()
	void OnPlayspaceMemoryValueUpdated(int32 MemoryValue);

	UFUNCTION(BlueprintImplementableEvent)
	void SetUIMetrics(const FVolumePerformanceMetrics& VolumePerformanceMetrics);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thermometer")
	FScalableFloat ThermometerMemoryThreshold;

private:
	UFUNCTION()
	void OnMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode);

};

