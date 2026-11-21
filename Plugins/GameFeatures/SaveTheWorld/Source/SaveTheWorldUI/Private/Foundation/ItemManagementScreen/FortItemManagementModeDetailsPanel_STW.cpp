// Copyright Epic Games, Inc. All Rights Reserved.

#include "Foundation/ItemManagementScreen/FortItemManagementModeDetailsPanel_STW.h"

TArray<UFortAmmoItemDefinition*> UFortItemManagementItemDetailsPanel_STW::GetAmmoTypeItemDefinitions()
{
	return TArray<UFortAmmoItemDefinition*>();
}

EFortItemManagementMode UFortItemManagementModeDetailsPanel_STW::GetItemManagementMode() const
{
	return EFortItemManagementMode();
}

void UFortItemManagementMulchDetailsPanel_STW::CommitMulch()
{
}

TArray<int32> UFortItemManagementMulchDetailsPanel_STW::GetItemCountsToMulch() const
{
	return TArray<int32>();
}

TArray<UFortItem*> UFortItemManagementMulchDetailsPanel_STW::GetItemsToMulch() const
{
	return TArray<UFortItem*>();
}

bool UFortItemManagementMulchDetailsPanel_STW::IsSpaceAvailableForMulch() const
{
	return false;
}
