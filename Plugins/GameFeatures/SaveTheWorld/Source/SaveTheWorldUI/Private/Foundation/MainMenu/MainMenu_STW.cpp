// Copyright Epic Games, Inc. All Rights Reserved.

#include "Foundation/MainMenu/MainMenu_STW.h"

bool UMainMenu_STW::IsActiveTabMainShop() const
{
	return false;
}

bool UMainMenu_STW::ShouldShowLeaveExperienceButton() const
{
	return false;
}

void UMainMenu_STW::TryShowModal(TSoftClassPtr<UCommonActivatableWidget>& ModalWidgetClass)
{
}

void UMainMenu_STW::TryShowPrimaryContent(TSoftClassPtr<UCommonActivatableWidget>& ContentWidgetClass)
{
}
