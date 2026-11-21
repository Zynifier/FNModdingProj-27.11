// Copyright Epic Games, Inc. All Rights Reserved.

#include "GridPicker/FortGridWidgetBase.h"

UFortGridPickerTile* UFortGridWidgetBase::GetTileForObject(const UObject* Object)
{
	return nullptr;
}

TArray<UFortGridPickerTile*> UFortGridWidgetBase::GetTiles()
{
	return TArray<UFortGridPickerTile*>();
}

void UFortGridWidgetBase::SetClearWidgetType(TSubclassOf<UFortGridPickerTile> InClearWidgetType)
{
}

void UFortGridWidgetBase::SetDataProvider(const TArray<UObject*>& Data)
{
}

void UFortGridWidgetBase::SetPeekOverflowTilePercentage(float Percent)
{
}

void UFortGridWidgetBase::SetTileHeight(float Height)
{
}

void UFortGridWidgetBase::SetTilePadding(FMargin Padding)
{
}

void UFortGridWidgetBase::SetTilesAcross(int32 Across)
{
}

void UFortGridWidgetBase::SetTilesDown(int32 Down)
{
}

void UFortGridWidgetBase::SetTileWidth(float Width)
{
}
