// Copyright Epic Games, Inc. All Rights Reserved.

#include "TemporaryItems/FortTemporaryItemsRow.h"

UFortTemporaryItemsRow::UFortTemporaryItemsRow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FText UFortTemporaryItemsRow::GetCategoryText(const EAthenaCustomizationCategory InCategory) const
{
	return FText();
}

void UFortTemporaryItemsRow::SetTileView(UTileView* InTileView)
{
}
