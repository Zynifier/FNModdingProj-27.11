// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Vehicles/FortAthenaVehicleDashboardWidget.h"

void UFortAthenaVehicleDashboardWidget::AddWidgetTagsToHideWhenVisible(FGameplayTagContainer TagToAdd)
{
}

AFortAthenaVehicle* UFortAthenaVehicleDashboardWidget::GetCurrentVehicle() const
{
	return nullptr;
}

float UFortAthenaVehicleDashboardWidget::GetHUDTopSpeed() const
{
	return float();
}

AFortAthenaVehicle* UFortAthenaVehicleDashboardWidget::GetVehicle() const
{
	return nullptr;
}

void UFortAthenaVehicleDashboardWidget::HandleBoostFinished()
{
}

void UFortAthenaVehicleDashboardWidget::HandleBoostStarted()
{
}

void UFortAthenaVehicleDashboardWidget::OnAddedFuel(float NewFuelPercent)
{
}

void UFortAthenaVehicleDashboardWidget::RemoveWidgetTagsToHideWhenVisible(FGameplayTagContainer TagToRemove)
{
}

void UFortAthenaVehicleDashboardWidget::SetupVehicleFuelWidget(AActor* NewVehicle, const bool bRequestShowWidget)
{
}
