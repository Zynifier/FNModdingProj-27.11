// Copyright Epic Games, Inc. All Rights Reserved.

#include "ViewModels/Items/FortItemVM.h"

bool UFortItemVM::CanEquip() const
{
	return false;
}

const UFortLockerCategoryConfig* UFortItemVM::GetItemCategory() const
{
	return nullptr;
}

const FFortLockerCategorySlotInfo& UFortItemVM::GetItemSlotInfo() const
{
	static FFortLockerCategorySlotInfo Dummy;
	return Dummy;
}

FString UFortItemVM::GetItemTemplateId() const
{
	return FString();
}

bool UFortItemVM::IsItemNew() const
{
	return false;
}

bool UFortItemVM::IsItemVisible() const
{
	return false;
}

void UFortItemVM::MarkAsSeen(bool bShouldDeferMarking)
{
}
