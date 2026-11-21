// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortPerkWidget_NUI.h"

bool UFortPerkWidget_NUI::GetIcon(FSlateBrush& Brush) const
{
	return false;
}

EFortItemTier UFortPerkWidget_NUI::GetPerkTier() const
{
	return EFortItemTier();
}

int32 UFortPerkWidget_NUI::GetRequiredLevel() const
{
	return int32();
}

EFortSupportBonusType UFortPerkWidget_NUI::GetSupportBonusType() const
{
	return EFortSupportBonusType();
}

UFortTooltipContext* UFortPerkWidget_NUI::GetTooltipContext()
{
	return nullptr;
}

FText UFortPerkWidget_NUI::GetTooltipTitle() const
{
	return FText();
}

void UFortPerkWidget_NUI::HandleAbilityKitTooltipLoaded()
{
}

bool UFortPerkWidget_NUI::HasAbility() const
{
	return false;
}

bool UFortPerkWidget_NUI::IsPerkEmpty() const
{
	return false;
}

bool UFortPerkWidget_NUI::IsPerkHighlighted() const
{
	return false;
}

bool UFortPerkWidget_NUI::IsPerkUnlocked() const
{
	return false;
}

bool UFortPerkWidget_NUI::IsTierPerk() const
{
	return false;
}

void UFortPerkWidget_NUI::RequestCombinedTooltipDescription()
{
}

void UFortPerkWidget_NUI::RequestTooltipDescription()
{
}

void UFortPerkWidget_NUI::SetTooltipContext(const UFortTooltipContext* InTooltipContext)
{
}
