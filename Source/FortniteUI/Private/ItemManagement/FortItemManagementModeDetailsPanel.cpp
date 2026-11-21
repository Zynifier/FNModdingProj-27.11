// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemManagement/FortItemManagementModeDetailsPanel.h"

TArray<UFortAmmoItemDefinition*> UFortItemManagementItemDetailsPanel::GetAmmoTypeItemDefinitions()
{
	return TArray<UFortAmmoItemDefinition*>();
}

EFortItemManagementMode UFortItemManagementModeDetailsPanel::GetItemManagementMode() const
{
	return EFortItemManagementMode();
}

void UFortItemManagementMulchDetailsPanel::CommitMulch()
{
}

TArray<int32> UFortItemManagementMulchDetailsPanel::GetItemCountsToMulch() const
{
	return TArray<int32>();
}

TArray<UFortItem*> UFortItemManagementMulchDetailsPanel::GetItemsToMulch() const
{
	return TArray<UFortItem*>();
}

bool UFortItemManagementMulchDetailsPanel::IsSpaceAvailableForMulch() const
{
	return false;
}
