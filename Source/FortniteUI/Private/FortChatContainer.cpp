// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortChatContainer.h"

const FText UFortChatContainer::GetTextChatDisabledText() const
{
	return FText();
}

UUserWidget* UFortChatContainer::HandleGetMenuContentForAnchor()
{
	return nullptr;
}

bool UFortChatContainer::IsTextChatRestricted() const
{
	return false;
}
