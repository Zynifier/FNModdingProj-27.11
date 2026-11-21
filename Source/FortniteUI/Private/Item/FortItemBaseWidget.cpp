// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/FortItemBaseWidget.h"

UFortItemDefinition* UFortItemBaseWidget::GetItemDefinition() const
{
	return nullptr;
}

int32 UFortItemBaseWidget::GetQuantity() const
{
	return int32();
}

FText UFortItemBaseWidget::GetRichDescription() const
{
	return FText();
}

void UFortItemBaseWidget::HandleItemCountChanged(UFortItemDefinition* Definition, int32 Delta)
{
}

void UFortItemBaseWidget::SetItemDefinitionToRepresent(UFortItemDefinition* InItemDefinition)
{
}

bool UFortItemBaseWidget::SetItemQuantityPairToRepresent(FFortItemQuantityPair InItemQuantityPair)
{
	return false;
}
