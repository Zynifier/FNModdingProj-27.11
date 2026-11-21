// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortPickerContext.h"

bool UFortPickerContext::DoesRadialCloseOnRelease() const
{
	return false;
}

void UFortPickerContext::GetAdjacentPickerWheelInformation(int32 Direction, FText& AdjacentTitle, bool& bCanPageThisDirection)
{
}

FText UFortPickerContext::GetCurrentPickerDisplayName()
{
	return FText();
}

int32 UFortPickerContext::GetCurrentWheelIndex() const
{
	return int32();
}

UFortItem* UFortPickerContext::GetListPickerOption(int32 Index) const
{
	return nullptr;
}

int32 UFortPickerContext::GetNumPickerOptions() const
{
	return int32();
}

void UFortPickerContext::GetPickerWheelAdjacency(bool& bCanPageLeft, bool& bCanPageRight)
{
}

void UFortPickerContext::GetRadialPickerOptionImageAndLabel(int32 Index, FText& Label, FSlateBrush& Brush, TSoftObjectPtr<UTexture2D>& Icon, bool& bOptionEnabled, bool& bIsLocked) const
{
}

void UFortPickerContext::GetRadialPickerOptionItem(int32 Index, UFortItem*& Item, bool& bOptionEnabled) const
{
}

void UFortPickerContext::LegacySwitchToAdjacentWheel(int32 SelectionDirection)
{
}

void UFortPickerContext::PickerCanceled()
{
}

void UFortPickerContext::PickerOptionAccepted(int32 Option)
{
}

void UFortPickerContext::RestoreInputAxes()
{
}

void UFortPickerContext::SetFortPickerData(UFortPickerData* Data)
{
}

void UFortPickerContext::ShowRadialPickerMenu(EFortPickerToDisplay PickerType, int32 WheelIndex, UObject* ContextObject)
{
}

bool UFortPickerContext::UseLeftThumbstick() const
{
	return false;
}
