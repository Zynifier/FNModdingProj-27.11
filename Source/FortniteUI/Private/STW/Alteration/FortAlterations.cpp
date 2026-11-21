// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Alteration/FortAlterations.h"

UFortAlterationItemDefinition* UFortAlterationInfo::GetAlterationDefintion() const
{
	return nullptr;
}

UFortItem* UFortAlterationInfo::GetCorrespondingItem() const
{
	return nullptr;
}

float UFortAlterationInfo::GetCurrentPipCount(float MaxPips) const
{
	return float();
}

EFortRarity UFortAlterationInfo::GetRarity() const
{
	return EFortRarity();
}

int32 UFortAlterationInfo::GetRequiredLevel() const
{
	return int32();
}

int32 UFortAlterationInfo::GetSlotIndex() const
{
	return int32();
}

bool UFortAlterationInfo::IsAlterationHighlighted() const
{
	return false;
}

bool UFortAlterationInfo::IsAlterationUnlocked() const
{
	return false;
}

bool UFortAlterationInfo::IsFreeAlterationChoice() const
{
	return false;
}
