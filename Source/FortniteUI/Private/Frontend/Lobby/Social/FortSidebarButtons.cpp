// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Lobby/Social/FortSidebarButtons.h"

UWidget* UFortSidebarButtons::GetFocusedSidebarButton() const
{
	return nullptr;
}

UWidget* UFortSidebarButtons::GetHoveredSidebarButton() const
{
	return nullptr;
}

UWidget* UFortSidebarButtons::GetSelectedSidebarButton() const
{
	return nullptr;
}

void UFortSidebarButtons::HandleButtonGroupOnHoveredChanged(UCommonButtonLegacy* HoveredButton, const int32 ButtonIdx)
{
}

void UFortSidebarButtons::HandleNextTabAction_STW(bool& bPassThrough)
{
}

void UFortSidebarButtons::HandlePrevTabAction_STW(bool& bPassThrough)
{
}

void UFortSidebarButtons::HandleSettingsSavedTabChanged(const bool IsTabSaved)
{
}
