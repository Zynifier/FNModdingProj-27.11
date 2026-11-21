// Copyright Epic Games, Inc. All Rights Reserved.

#include "SquadManagement/FortSquadManagementScreenBase.h"

void UFortSquadManagementScreenBase::ClearSquad()
{
}

FName UFortSquadManagementScreenBase::GetIdOfSquadToManageBP() const
{
	return FName();
}

int32 UFortSquadManagementScreenBase::GetNumUnlockedSquads() const
{
	return int32();
}

void UFortSquadManagementScreenBase::HandleBackInputAction()
{
}

void UFortSquadManagementScreenBase::HandleClosePickerInputAction()
{
}

void UFortSquadManagementScreenBase::HandleCyclePickerSortInputAction()
{
}

void UFortSquadManagementScreenBase::HandleDifferentSquadSlotSelected(const int32 SquadSlotIndex)
{
}

void UFortSquadManagementScreenBase::HandleInspectInputAction()
{
}

void UFortSquadManagementScreenBase::HandleInventoryInputAction()
{
}

void UFortSquadManagementScreenBase::HandleManageInputAction()
{
}

void UFortSquadManagementScreenBase::HandleOpenSquadSlot(const int32 SquadSlotIndex)
{
}

void UFortSquadManagementScreenBase::HandlePickerSelectionChanged(UFortItem* SelectedItem)
{
}

void UFortSquadManagementScreenBase::HandlePickerSelectionCommitted(UFortItem* CommittedItem)
{
}

void UFortSquadManagementScreenBase::HandleSelectPickerSlotInputAction()
{
}

void UFortSquadManagementScreenBase::HandleShouldAutoSlotSurvivorSquadsChanged()
{
}

void UFortSquadManagementScreenBase::HandleViewInAll(const int32 SquadSlotIndex)
{
}

bool UFortSquadManagementScreenBase::IsScreenWIFE() const
{
	return false;
}

void UFortSquadManagementScreenBase::NavigateToSquadSlot(int32 SquadSlotIndex)
{
}

void UFortSquadManagementScreenBase::SelectNextSquad()
{
}

void UFortSquadManagementScreenBase::SelectPreviousSquad()
{
}

void UFortSquadManagementScreenBase::SelectSquadWithOffset(int32 Offset)
{
}

void UFortSquadManagementScreenBase::SetIdOfSquadToManageBP(const FName& SquadId)
{
}

void UFortSquadManagementScreenBase::SetupInputHandlers()
{
}

bool UFortSquadManagementScreenBase::TryGetAttributeValueFromSquad(float& OutValue, const FGameplayAttribute& Attribute) const
{
	return false;
}

bool UFortSquadManagementScreenBase::TryGetSquadMainAttribute(FGameplayAttribute& OutGameplayAttribute) const
{
	return false;
}

bool UFortSquadManagementScreenBase::TryGetSquadTeamAttribute(FGameplayAttribute& OutGameplayAttribute) const
{
	return false;
}

bool UFortSquadManagementScreenBase::TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const
{
	return false;
}
