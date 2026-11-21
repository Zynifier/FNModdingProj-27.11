// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Settings/FortInputOptions.h"

void UFortInputOptions::ChangeBinding(bool bIsPrimarySlot, int32 Input, FKey NewKey)
{
}

void UFortInputOptions::ConstructKeyBindList()
{
}

FFortActionBeingUnbound UFortInputOptions::GetActionBeingUnbound(bool bIsPrimarySlot, int32 Input, FKey NewKey) const
{
	return FFortActionBeingUnbound();
}

TArray<UFortOptionsMenuInputData*> UFortInputOptions::GetActionItemsInGroup(const EFortInputActionGroup InputActionGroup) const
{
	return TArray<UFortOptionsMenuInputData*>();
}

FText UFortInputOptions::GetBoundKeyNameBP(int32 RowIndex, bool IsPrimary) const
{
	return FText();
}

int32 UFortInputOptions::GetInputDataIndexForActionName(const FName ActionName) const
{
	return int32();
}

FText UFortInputOptions::GetInputDisplayTextBP(int32 RowIndex) const
{
	return FText();
}

UWidget* UFortInputOptions::GetListWidget(UObject* Item)
{
	return nullptr;
}
