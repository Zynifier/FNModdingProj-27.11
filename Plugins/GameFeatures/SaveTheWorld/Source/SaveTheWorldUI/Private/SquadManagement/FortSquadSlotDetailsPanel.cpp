// Copyright Epic Games, Inc. All Rights Reserved.

#include "SquadManagement/FortSquadSlotDetailsPanel.h"

void UFortSquadSlotDetailsPanel::GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const
{
}

UFortItem* UFortSquadSlotDetailsPanel::GetItemInSquadSlotBP(const ULocalPlayer* LocalPlayer) const
{
	return nullptr;
}

TArray<EFortSquadSlottingRestrictionReason> UFortSquadSlotDetailsPanel::GetSlottingRestrictionReasons() const
{
	return TArray<EFortSquadSlottingRestrictionReason>();
}

bool UFortSquadSlotDetailsPanel::IsSquadSlotLockedBP() const
{
	return false;
}

void UFortSquadSlotDetailsPanel::SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex)
{
}

void UFortSquadSlotDetailsPanel::SetScrollWidget()
{
}

bool UFortSquadSlotDetailsPanel::TryGetItemToPreviewInSlot(UFortItem*& OutItemToPreviewInSlot) const
{
	return false;
}
