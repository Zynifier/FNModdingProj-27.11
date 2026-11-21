// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortCardPackItem.h"

bool UFortCardPackItem::CanStoreOpen() const
{
	return false;
}

void UFortCardPackItem::GetChoiceItems(TArray<UFortItem*>& ChoiceAttributes) const
{
}

void UFortCardPackItem::GetChoices(TArray<UFortAccountItemDefinition*>& Choices) const
{
}

bool UFortCardPackItem::IsChoicePack() const
{
	return false;
}
