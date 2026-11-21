// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/TopBar/FortMainMenu.h"

bool UFortMainMenu::NeedsCenterWidget() const
{
	return false;
}

void UFortMainMenu::RequestCloseMainMenu()
{
}

bool UFortMainMenu::ShouldShowLeaveExperienceButton() const
{
	return false;
}
