// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/SingleIndexSelectionModel.h"

void ISingleIndexSelectionModel::AddOnNavigationChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const
{
}

void ISingleIndexSelectionModel::AddOnNumItemsChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const
{
}

void ISingleIndexSelectionModel::AddOnSelectedIndexChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const
{
}

EIndexNavigationResult ISingleIndexSelectionModel::CanMoveDelta(int32 InDelta) const
{
	return EIndexNavigationResult();
}

int32 ISingleIndexSelectionModel::GetNumItems() const
{
	return int32();
}

int32 ISingleIndexSelectionModel::GetSelectedIndex() const
{
	return int32();
}

void ISingleIndexSelectionModel::RemoveOnNavigationChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const
{
}

void ISingleIndexSelectionModel::RemoveOnNumItemsChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const
{
}

void ISingleIndexSelectionModel::RemoveOnSelectedIndexChangedDelegate(const FIndexSelectionModelChangedDelegate& InDelegate) const
{
}

void ISingleIndexSelectionModel::SetSelectedIndex(int32 Value)
{
}

EIndexNavigationResult ISingleIndexSelectionModel::TryMoveDelta(int32 InDelta)
{
	return EIndexNavigationResult();
}
