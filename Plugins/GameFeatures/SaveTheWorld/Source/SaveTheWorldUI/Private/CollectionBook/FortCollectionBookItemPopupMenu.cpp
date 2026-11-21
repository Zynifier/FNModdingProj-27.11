// Copyright Epic Games, Inc. All Rights Reserved.

#include "CollectionBook/FortCollectionBookItemPopupMenu.h"

bool UFortCollectionBookItemPopupMenu::CanItemBePurchased()
{
	return false;
}

bool UFortCollectionBookItemPopupMenu::CanItemBeUnslotted()
{
	return false;
}

UFortCollectionBookSlotButton* UFortCollectionBookItemPopupMenu::GetHostButton() const
{
	return nullptr;
}
