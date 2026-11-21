// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/Locker/FortLockerCategoryVM.h"

bool UFortLockerCategoryGroupVM::GetAreAnyItemsArchived() const
{
	return false;
}

bool UFortLockerCategoryGroupVM::GetAreAnyItemsNew() const
{
	return false;
}

const UFortLockerCategoryGroupConfig* UFortLockerCategoryGroupVM::GetConfig() const
{
	return nullptr;
}

FString UFortLockerCategoryItemVM::GetAnalyticsName() const
{
	return FString();
}

const FFortLockerCategorySlotInfo& UFortLockerCategoryItemVM::GetSlotInfo() const
{
	static FFortLockerCategorySlotInfo Dummy;
	return Dummy;
}

bool UFortLockerCategoryVM::GetAreAnyItemsArchived() const
{
	return false;
}

bool UFortLockerCategoryVM::GetAreAnyItemsNew() const
{
	return false;
}

bool UFortLockerCategoryVM::GetAreAnyItemsNotArchived() const
{
	return false;
}

const UFortLockerCategoryConfig* UFortLockerCategoryVM::GetConfig() const
{
	return nullptr;
}

int32 UFortLockerCategoryVM::GetItemsInCategoryCount() const
{
	return int32();
}
