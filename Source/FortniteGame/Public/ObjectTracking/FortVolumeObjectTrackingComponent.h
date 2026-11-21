// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Building/SpatialGameplay/SpatialActorTrackerContext.h"
#include "FortCreativeBudgetTracker.h"
#include "FortCreativeBudgeter.h"
#include "FortCreativeClassInstanceTracker.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "ObjectTracking/ObjectTracking.h"
#include "FortVolumeObjectTrackingComponent.generated.h"

class AActor;
class AFortCreativeHeatmapThermometerPreview;
class AFortVolume;
class APawn;
class APlayerController;
class IFortSpatialGameplayInterface;
class UActorComponent;
class UFortVolumeObjectTrackingComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVolumeObjectTrackingComponentSignature, UFortVolumeObjectTrackingComponent*, VolumeObjectTrackingComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVolumePerformanceMetricsUpdated, const FVolumePerformanceMetrics&, VolumePerformanceMetrics);

USTRUCT(BlueprintType)
struct FCreativeMultiSelectedActorsInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> Actor;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<APlayerController>> InstigatorPlayers;

};

UCLASS(MinimalAPI, meta=(BlueprintSpawnableComponent))
class UFortVolumeObjectTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ActorTracker_ActorEntered(FEventMessageTag Channel, const FActorTrackerActorEnteredContext& PlayerEnterSpatialActorContext);

	UFUNCTION()
	void ActorTracker_ActorExited(FEventMessageTag Channel, const FActorTrackerActorExitContext& PlayerExitSpatialActorContext);

	UFUNCTION()
	void AddActorAtLocation(AActor* Actor, const FVector& Location);

	UFUNCTION()
	void CalculateHeatmap();

	UFUNCTION(BlueprintPure)
	bool DisplayMaxMemoryValueThermometer() const;

	UFUNCTION()
	bool IsEventMessageContextOwnerValid(AActor* EventContextOwner);

	UFUNCTION(BlueprintPure)
	bool IsHeatmapEnabled() const;

	UFUNCTION()
	void RemoveActor(AActor* Actor, UActorComponent* ActorComponent, APawn* InstigatorPawn, AFortVolume* Volume);

	UFUNCTION()
	void RemoveActorWithInterface(AActor* Actor, TScriptInterface<IFortSpatialGameplayInterface> GameplayInterface);

	UFUNCTION()
	void UpdateActor(AActor* Actor, const FVector& Location);

	UFUNCTION()
	void UpdatePreviewLocation(const AFortCreativeHeatmapThermometerPreview* PreviewActor, const FVector& Location);

	UFUNCTION(BlueprintPure)
	bool UseBudgetGridThermometer() const;

protected:
	UFUNCTION()
	void OnVolumePerformanceMetricsReplicated();

private:
	UFUNCTION()
	void AddActorToSelectionPreview(AActor* Actor, int32 PlayerID);

	UFUNCTION()
	void On_RepObjectTrackingHeatmap();

	UFUNCTION()
	void OnRep_BudgetTracker();

	UFUNCTION()
	void OnRep_HeatmapEnabled();

	UFUNCTION()
	void OnRep_HeatmapSize();

	UFUNCTION()
	void RemoveActorFromSelectionPreview(AActor* Actor, int32 PlayerID);

	UPROPERTY(Transient)
	TObjectPtr<AFortVolume> ParentVolume;

	UPROPERTY(ReplicatedUsing=OnVolumePerformanceMetricsReplicated)
	FVolumePerformanceMetrics VolumePerformanceMetrics;

	UPROPERTY(Transient)
	FOnVolumePerformanceMetricsUpdated OnVolumePerformanceMetricsUpdatedEvent;

	UPROPERTY(Replicated)
	FFortCreativeClassInstanceTracker TransientTracker;

	UPROPERTY(ReplicatedUsing=OnRep_BudgetTracker)
	FFortCreativeBudgetTracker BudgetTracker;

	UPROPERTY(Replicated)
	FFortCreativeClassInstanceTracker ClassTracker;

	UPROPERTY(ReplicatedUsing=OnRep_HeatmapEnabled)
	bool bHeatmapEnabled;

	UPROPERTY(Transient)
	bool bHeatmapIsDirty;

	UPROPERTY(ReplicatedUsing=OnRep_HeatmapSize)
	int32 ObjectTrackingHeatmapSize;

	UPROPERTY(ReplicatedUsing=On_RepObjectTrackingHeatmap)
	TArray<uint8> ObjectTrackingHeatmapHighPrecision;

	UPROPERTY(ReplicatedUsing=On_RepObjectTrackingHeatmap)
	TArray<uint8> ObjectTrackingOverBudgetHeatmap;

	UPROPERTY(Transient)
	float TargetUpdateTime;

	UPROPERTY(Transient)
	float CreativeHeatmapThermometerInfluenceDistanceMultiplier;

	UPROPERTY(Transient)
	FFortCreativeGridCellBudget CreativeHeatmapThermometerBudget;

	UPROPERTY(Replicated)
	float CreativeHeatmapThermometerCellSize;

	UPROPERTY()
	TArray<FCreativeMultiSelectedActorsInfo> MultiSelectedActors;

};

