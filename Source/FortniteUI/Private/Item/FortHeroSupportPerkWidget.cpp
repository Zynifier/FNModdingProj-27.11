// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/FortHeroSupportPerkWidget.h"

UFortHeroSupportPerkWidget::UFortHeroSupportPerkWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortHeroSupportPerkWidget::IsHeroInSupportSlot() const
{
	return false;
}

bool UFortHeroSupportPerkWidget::IsPerkActive() const
{
	return false;
}

bool UFortHeroSupportPerkWidget::IsPerkEmpty() const
{
	return false;
}

bool UFortHeroSupportPerkWidget::IsPerkHighlighted() const
{
	return false;
}

bool UFortHeroSupportPerkWidget::IsPerkInCorrectSlot() const
{
	return false;
}

bool UFortHeroSupportPerkWidget::IsPerkUnlocked() const
{
	return false;
}

void UFortHeroSupportPerkWidget::SetHeroToRepresent(const UFortHero* InHeroToRepresent)
{
}

void UFortHeroSupportPerkWidget::SetState(const EFortSupportPerkWidgetState InState)
{
}

void UFortHeroSupportPerkWidget::SetSupportTypeToRepresent(const EFortSupportBonusType InSupportTypeToRepresent)
{
}
