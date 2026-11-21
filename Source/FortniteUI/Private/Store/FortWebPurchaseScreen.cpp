// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortWebPurchaseScreen.h"

bool UFortWebPurchaseScreen::CanShowBottomBar() const
{
	return false;
}

bool UFortWebPurchaseScreen::CanShowChatWidget() const
{
	return false;
}

bool UFortWebPurchaseScreen::CanShowTopBar() const
{
	return false;
}

void UFortWebPurchaseScreen::Dismiss()
{
}

void UFortWebPurchaseScreen::Display(UWidget* WebWidget)
{
}
