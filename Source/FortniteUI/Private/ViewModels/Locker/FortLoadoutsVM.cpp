// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/Locker/FortLoadoutsVM.h"

FText UFortLoadoutVM::GetDefaultName() const
{
	return FText();
}

UFortItemVM* UFortLoadoutVM::GetFirstValidItem(UUserWidget* ContextWidget, const UFortLockerCategoryConfig* Category) const
{
	return nullptr;
}

UFortItemVM* UFortLoadoutVM::GetItem(UUserWidget* ContextWidget, const UFortLockerCategoryConfig* Category, int32 SlotIndex) const
{
	return nullptr;
}

const UFortCosmeticLockerItem* UFortLoadoutVM::GetLockerItem()
{
	return nullptr;
}

bool UFortLoadoutVM::IsValid() const
{
	return false;
}

bool UFortLoadoutsVM::GetCanEnableRandomization() const
{
	return false;
}

bool UFortLoadoutsVM::GetHasLoadouts() const
{
	return false;
}

void UFortLoadoutsVM::ToggleRandomEnabled()
{
}
