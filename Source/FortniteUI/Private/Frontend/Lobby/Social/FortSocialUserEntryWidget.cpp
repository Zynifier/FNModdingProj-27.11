// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Lobby/Social/FortSocialUserEntryWidget.h"

UFortSocialUser* UFortSocialUserEntryWidget::GetSocialUser() const
{
	return nullptr;
}

UUserWidget* UFortSocialUserEntryWidget::HandleGetMenuContext()
{
	return nullptr;
}

void UFortSocialUserEntryWidget::HandleMenuOpenChanged(bool bIsMenuOpen)
{
}

void UFortSocialUserEntryWidget::SetSocialUserFromOwningPlayer()
{
}

void UFortSocialUserEntryWidget::SpawnSocialActionMenu(UMenuAnchor* MenuAnchor, TSubclassOf<USocialActionMenu> ActionMenuClass)
{
}
