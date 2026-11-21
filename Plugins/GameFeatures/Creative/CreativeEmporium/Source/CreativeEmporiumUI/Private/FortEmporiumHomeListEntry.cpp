// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumHomeListEntry.h"

UFortEmporiumHomeListEntry::UFortEmporiumHomeListEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

EFortItemCardSize UFortEmporiumHomeListEntry::GetCardSizeForCategory() const
{
	return EFortItemCardSize();
}

bool UFortEmporiumHomeListEntry::GetCollapseBorderPadFlagForCategory() const
{
	return false;
}
