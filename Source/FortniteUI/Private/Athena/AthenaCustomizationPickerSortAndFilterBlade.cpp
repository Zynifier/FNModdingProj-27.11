// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaCustomizationPickerSortAndFilterBlade.h"

void UAthenaCustomizationPickerSortAndFilterBlade::CloseBlade()
{
}

TArray<UUserWidget*> UAthenaCustomizationPickerSortAndFilterBlade::GetAllSortAndFilterButtons()
{
	return TArray<UUserWidget*>();
}

UCommonButtonBase* UAthenaCustomizationPickerSortAndFilterBlade::GetFilterButtonAtIndex(const int32 DesiredIndex) const
{
	return nullptr;
}

int32 UAthenaCustomizationPickerSortAndFilterBlade::GetNumFilters() const
{
	return int32();
}

int32 UAthenaCustomizationPickerSortAndFilterBlade::GetNumSorts() const
{
	return int32();
}

UCommonButtonBase* UAthenaCustomizationPickerSortAndFilterBlade::GetSortButtonAtIndex(const int32 DesiredIndex) const
{
	return nullptr;
}

void UAthenaCustomizationPickerSortAndFilterBlade::HandleCloseAnimationFinished()
{
}

bool UAthenaCustomizationPickerSortAndFilterBlade::IsBladeOpen() const
{
	return false;
}
