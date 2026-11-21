// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortAccountItem.h"

FDateTime UFortAccountItem::GetCreationTime() const
{
	return FDateTime();
}

TArray<FFortItemQuantityPair> UFortAccountItem::GetRecyclingRefunds() const
{
	return TArray<FFortItemQuantityPair>();
}

TArray<FFortItemQuantityPair> UFortAccountItem::GetRefundResults() const
{
	return TArray<FFortItemQuantityPair>();
}

bool UFortAccountItem::HasBeenSeenLocally() const
{
	return false;
}

bool UFortAccountItem::IsArchived() const
{
	return false;
}

bool UFortAccountItem::IsFavorite() const
{
	return false;
}

bool UFortAccountItem::IsRefundable() const
{
	return false;
}

void UFortAccountItem::MarkItemAsSeenBP()
{
}
