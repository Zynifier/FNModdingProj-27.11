// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortConversionControlItemDefinition.h"

EFortRarity UFortConversionControlItemDefinition::GetFirstConversionTier() const
{
	return EFortRarity();
}

EFortRarity UFortConversionControlItemDefinition::GetMaxConversionTier() const
{
	return EFortRarity();
}

int32 UFortConversionControlItemDefinition::GetPointsForTier(EFortRarity InTier) const
{
	return int32();
}

FGameplayTagContainer UFortConversionControlItemDefinition::GetRequiredCatalysts() const
{
	return FGameplayTagContainer();
}

UFortAccountItemDefinition* UFortConversionControlItemDefinition::GetRequiredItemDefinition() const
{
	return nullptr;
}

int32 UFortConversionControlItemDefinition::GetRequiredItemQuantity(int32 SacrificePoints) const
{
	return int32();
}

FText UFortConversionControlItemDefinition::GetRewardName() const
{
	return FText();
}

bool UFortConversionControlItemDefinition::GetTierFromSacrificePoints(int32 SacrificePoints, EFortRarity& CalculatedTier) const
{
	return false;
}
