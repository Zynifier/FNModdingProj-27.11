// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIKit/Tabs/UIKitTabGroup.h"

void UUIKitTabGroup::DeselectAll()
{
}

int32 UUIKitTabGroup::GetSelectedTabIndex() const
{
	return int32();
}

int32 UUIKitTabGroup::GetTabIndexByID(FName TabNameID) const
{
	return int32();
}

UUIKitTabGroupButtonViewModel* UUIKitTabGroup::GetTabViewModelByID(FName TabNameID) const
{
	return nullptr;
}

void UUIKitTabGroup::HandleTabButtonClicked(UCommonButtonBase* SelectedTabButton, int32 ButtonIndex)
{
}

bool UUIKitTabGroup::IsTabViewModelValid(const UUIKitTabGroupButtonViewModel* TabVM) const
{
	return false;
}

void UUIKitTabGroup::SelectNextTab()
{
}

void UUIKitTabGroup::SelectPreviousTab()
{
}

bool UUIKitTabGroup::SelectTabByIndex(int32 Index, bool bSuppressClickFeedback)
{
	return false;
}

void UUIKitTabGroup::SetInputActions(FDataTableRowHandle NextTab, FDataTableRowHandle PreviousTab)
{
}
