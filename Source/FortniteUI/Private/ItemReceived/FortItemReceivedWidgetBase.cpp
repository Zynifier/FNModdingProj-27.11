// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemReceived/FortItemReceivedWidgetBase.h"

void UFortItemReceivedWidgetBase::ClosingGiftbox()
{
}

UFortItem* UFortItemReceivedWidgetBase::GetTemporaryInstance(const FFortReceivedItemLootInfo& ItemReference)
{
	return nullptr;
}

void UFortItemReceivedWidgetBase::OnGiftBoxItemSetInternal(bool bFromSelf)
{
}

void UFortItemReceivedWidgetBase::SetAlignmentOnSlot(UScrollBox* Widget, int32 Index)
{
}

void UFortItemReceivedWidgetBase::SetAlignmentOnSlots(UScrollBox* Widget)
{
}

void UFortItemReceivedWidgetBase::SetGiftBoxItem(UFortGiftBoxItem* GiftBoxItem)
{
}

void UItemCardWidgetBase::SetLootInfo(UFortGiftInfo* LootInfo)
{
}
