// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUIMessageManager.h"

UFortUIMessageItemWidget* UFortUIMessageManager::AddMessageItem(TSubclassOf<UFortUIMessageItemWidget> MessageItemClass, APlayerController* OwningPlayer, FName MessageID, int32 StackCount)
{
	return nullptr;
}

UFortUIMessageItemWidget* UFortUIMessageManager::GetNextMessageInQueue()
{
	return nullptr;
}

int32 UFortUIMessageManager::GetNumDisplayedItems() const
{
	return int32();
}

void UFortUIMessageManager::HandleMessageDisplayed(UFortUIMessageItemWidget* MessageItem)
{
}

void UFortUIMessageManager::HandleMessageRemoved(UFortUIMessageItemWidget* MessageItem)
{
}
