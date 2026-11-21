// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativePropertySubcategoryHeaderListItem.h"

const FGameplayTag& UFortCreativePropertySubcategoryHeaderListItem::GetSubcategoryTag() const
{
	static FGameplayTag Dummy;
	return Dummy;
}

bool UFortCreativePropertySubcategoryHeaderListItem::IsExpanded() const
{
	return false;
}

void UFortCreativePropertySubcategoryHeaderListItem::SetIsExpanded(const bool bInIsExpanded)
{
}
