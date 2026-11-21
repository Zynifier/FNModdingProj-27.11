// Copyright Epic Games, Inc. All Rights Reserved.

#include "CollectionBook/FortCollectionBookSlotWidget.h"

int32 UFortCollectionBookSlotWidget::GetNumItemsToSlot() const
{
	return int32();
}

const FName& UFortCollectionBookSlotWidget::GetSlotRowName() const
{
	static FName Dummy;
	return Dummy;
}

UFortItem* UFortCollectionBookSlotWidget::GetSlottedItemRepresentation() const
{
	return nullptr;
}

void UFortCollectionBookSlotWidget::HandleResearchItemComplete(const UFortAccountItem* ResearchedItem, const FString& SlotId)
{
}

void UFortCollectionBookSlotWidget::HandleSlottedItemOperationComplete(const UFortAccountItem* NewItem, FName TemplateId)
{
}

void UFortCollectionBookSlotWidget::HandleUnslotItemComplete(const UFortAccountItem* UnslottedItem, const UFortAccountItem* OldItem, FName SlotId)
{
}

bool UFortCollectionBookSlotWidget::HasItemsToSlot() const
{
	return false;
}

bool UFortCollectionBookSlotWidget::IsItemSlotted() const
{
	return false;
}

void UFortCollectionBookSlotWidget::OnItemDestroyed()
{
}
