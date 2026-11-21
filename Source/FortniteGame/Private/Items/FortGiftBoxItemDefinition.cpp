// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortGiftBoxItemDefinition.h"

bool UFortGiftBoxItemDefinition::HasHeaderSubWidget() const
{
	return false;
}

bool UFortGiftBoxItemDefinition::HasPreMessageWidget() const
{
	return false;
}

bool UFortGiftBoxItemDefinition::TryLoadHeaderSubWidgetClass(TSubclassOf<UUserWidget>& OutWidgetClass)
{
	return false;
}

bool UFortGiftBoxItemDefinition::TryLoadPreMessageWidgetClass(TSubclassOf<UUserWidget>& OutWidgetClass)
{
	return false;
}
