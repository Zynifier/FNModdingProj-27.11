// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSocialNotificationWidget.h"

bool UFortSocialNotificationWidget::GetIsInGame() const
{
	return false;
}

bool UFortSocialNotificationWidget::GetIsPlayerJoiningParty() const
{
	return false;
}

bool UFortSocialNotificationWidget::GetIsPlayerLeavingParty() const
{
	return false;
}

void UFortSocialNotificationWidget::HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget)
{
}

void UFortSocialNotificationWidget::HandleInputMethodChanged(ECommonInputType NewInputType)
{
}

void UFortSocialNotificationWidget::HoldAction()
{
}

void UFortSocialNotificationWidget::HoldPressed()
{
}

void UFortSocialNotificationWidget::HoldReleased()
{
}
