// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObjectTracking/FortVolumeObjectTrackingComponent.h"
#include "Net/UnrealNetwork.h"

void UFortVolumeObjectTrackingComponent::ActorTracker_ActorEntered(FEventMessageTag Channel, const FActorTrackerActorEnteredContext& PlayerEnterSpatialActorContext)
{
}

void UFortVolumeObjectTrackingComponent::ActorTracker_ActorExited(FEventMessageTag Channel, const FActorTrackerActorExitContext& PlayerExitSpatialActorContext)
{
}

void UFortVolumeObjectTrackingComponent::AddActorAtLocation(AActor* Actor, const FVector& Location)
{
}

void UFortVolumeObjectTrackingComponent::AddActorToSelectionPreview(AActor* Actor, int32 PlayerID)
{
}

void UFortVolumeObjectTrackingComponent::CalculateHeatmap()
{
}

bool UFortVolumeObjectTrackingComponent::DisplayMaxMemoryValueThermometer() const
{
	return false;
}

bool UFortVolumeObjectTrackingComponent::IsEventMessageContextOwnerValid(AActor* EventContextOwner)
{
	return false;
}

bool UFortVolumeObjectTrackingComponent::IsHeatmapEnabled() const
{
	return false;
}

void UFortVolumeObjectTrackingComponent::On_RepObjectTrackingHeatmap()
{
}

void UFortVolumeObjectTrackingComponent::OnRep_BudgetTracker()
{
}

void UFortVolumeObjectTrackingComponent::OnRep_HeatmapEnabled()
{
}

void UFortVolumeObjectTrackingComponent::OnRep_HeatmapSize()
{
}

void UFortVolumeObjectTrackingComponent::OnVolumePerformanceMetricsReplicated()
{
}

void UFortVolumeObjectTrackingComponent::RemoveActor(AActor* Actor, UActorComponent* ActorComponent, APawn* InstigatorPawn, AFortVolume* Volume)
{
}

void UFortVolumeObjectTrackingComponent::RemoveActorFromSelectionPreview(AActor* Actor, int32 PlayerID)
{
}

void UFortVolumeObjectTrackingComponent::RemoveActorWithInterface(AActor* Actor, TScriptInterface<IFortSpatialGameplayInterface> GameplayInterface)
{
}

void UFortVolumeObjectTrackingComponent::UpdateActor(AActor* Actor, const FVector& Location)
{
}

void UFortVolumeObjectTrackingComponent::UpdatePreviewLocation(const AFortCreativeHeatmapThermometerPreview* PreviewActor, const FVector& Location)
{
}

bool UFortVolumeObjectTrackingComponent::UseBudgetGridThermometer() const
{
	return false;
}

void UFortVolumeObjectTrackingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, VolumePerformanceMetrics);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, TransientTracker);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, BudgetTracker);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, ClassTracker);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, bHeatmapEnabled);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, ObjectTrackingHeatmapSize);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, ObjectTrackingHeatmapHighPrecision);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, ObjectTrackingOverBudgetHeatmap);
	DOREPLIFETIME(UFortVolumeObjectTrackingComponent, CreativeHeatmapThermometerCellSize);
}
