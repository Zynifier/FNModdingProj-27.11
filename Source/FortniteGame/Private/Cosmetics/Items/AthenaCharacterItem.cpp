// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaCharacterItem.h"

UFortHero* UAthenaCosmeticAccountItem::GetHero() const
{
	return nullptr;
}

FText UAthenaCosmeticAccountItem::GetLockerDescriptionText() const
{
	return FText();
}

FText UAthenaCosmeticAccountItem::GetLockerItemTypeText() const
{
	return FText();
}

bool UAthenaCosmeticAccountItem::HasCosmeticVariance() const
{
	return false;
}

bool UAthenaCosmeticAccountItem::HasMultipleVariants()
{
	return false;
}
