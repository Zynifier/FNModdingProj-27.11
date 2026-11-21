// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/Locker/FortLockerSortFilterVM.h"

bool UFortLockerCategoryFilterVM::CanManageArchive(bool& bOutIsArchiving) const
{
	return false;
}

const UFortItemVM* UFortLockerCategoryFilterVM::GetFirstActualValidItem(bool bGetEquippedItem) const
{
	return nullptr;
}

const UFortItemVM* UFortLockerCategoryFilterVM::GetFirstValidItem(bool bGetEquippedItem) const
{
	return nullptr;
}

bool UFortLockerCategoryFilterVM::IsFiltering() const
{
	return false;
}

const UFortLockerCategoryFilterConfig* UFortLockerFilterItemVM::GetConfig() const
{
	return nullptr;
}

const UFortLockerCategoryConfig* UFortLockerSearchTextVM::GetConfig() const
{
	return nullptr;
}

const UFortLockerCategorySortConfig* UFortLockerSortItemVM::GetConfig() const
{
	return nullptr;
}
