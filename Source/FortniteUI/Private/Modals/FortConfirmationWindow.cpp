// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modals/FortConfirmationWindow.h"

void UFortConfirmationWindow::BotClickButton()
{
}

const FFortDialogDescription_NUI& UFortConfirmationWindow::GetConfirmationDescription() const
{
	static FFortDialogDescription_NUI Dummy;
	return Dummy;
}

void UFortConfirmationWindow::HandleCancelButtonClicked(UCommonButtonBase* Buttton)
{
}

void UFortConfirmationWindow::HandleDeclineActionClicked(UCommonButtonBase* ButtonClicked)
{
}

void UFortConfirmationWindow::HandleInputSuspensionChanged(bool bIsInputSuspended)
{
}
