// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Creative/UI/CreativePerformanceHUDBase.h"

int32 UCreativePerformanceHUDBase::GetCostPreviewOfSelectedActor()
{
	return int32();
}

void UCreativePerformanceHUDBase::HandleGameStateInitialized(AFortGameState* GameState)
{
}

void UCreativePerformanceHUDBase::HandleSpatialLoadingStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext)
{
}

bool UCreativePerformanceHUDBase::IsHeatmapEnabled() const
{
	return false;
}

void UCreativePerformanceHUDBase::OnCostPreviewOfSelectionChanged()
{
}

void UCreativePerformanceHUDBase::OnPerformanceMetricsUpdated(const FVolumePerformanceMetrics& VolumePerformanceMetrics)
{
}

void UCreativePerformanceHUDBase::OnPlayerEnteredSpatialGameplayActor(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& PlayerEnterSpatialActorContext)
{
}

void UCreativePerformanceHUDBase::OnPlayerExitedSpatialGameplayActor(FEventMessageTag Channel, const FPlayerExitSpatialActorContext& PlayerExitSpatialActorContext)
{
}

void UCreativePerformanceHUDBase::OnSimpleMetricInformationUpdated(APlayerState* ClientState, const FSimpleMetricInformation& MetricInformation)
{
}

void UCreativePerformanceHUDBase::OnVolumeTrackingComponentReplicated()
{
}

bool UCreativePerformanceHUDBase::ShowBudgetGridThermometerCoordinates()
{
	return false;
}

void UCreativePerformanceHUDBase::StartTimer()
{
}

void UCreativePerformanceHUDBase::StopTimer()
{
}
