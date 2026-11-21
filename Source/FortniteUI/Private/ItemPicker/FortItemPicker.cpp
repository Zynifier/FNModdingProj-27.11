// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemPicker/FortItemPicker.h"

bool UFortItemPickerBase::CanItemBeComitted(const UFortItem* ItemToCommit)
{
	return false;
}

void UFortItemPickerBase::CenterSelectedItemTileWidget()
{
}

void UFortItemPickerBase::ClearSelection()
{
}

int32 UFortItemPickerBase::GetIndexForItem(UFortItem* Item) const
{
	return int32();
}

TScriptInterface<IFortItemListViewInterface> UFortItemPickerBase::GetListViewInterface()
{
	return TScriptInterface<IFortItemListViewInterface>();
}

UFortItem* UFortItemPickerBase::GetSelectedItem() const
{
	return nullptr;
}

bool UFortItemPickerBase::IsNullItemExplicitlySelected() const
{
	return false;
}

bool UFortItemPickerBase::SetSelectedIndex(int32 Index)
{
	return false;
}

void UFortItemPickerBase::SetSelectedItem(const UFortItem* ItemToSelect)
{
}

bool UFortItemPickerBase::TryCommitSelectedItem()
{
	return false;
}
