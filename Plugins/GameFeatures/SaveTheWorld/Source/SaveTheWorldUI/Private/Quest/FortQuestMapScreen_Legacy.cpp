// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quest/FortQuestMapScreen_Legacy.h"

void UFortQuestMapScreen_Legacy::CheckForNewMainQuest()
{
}

bool UFortQuestMapScreen_Legacy::GetBeyondCutoffQuest() const
{
	return false;
}

EFrontEndCamera UFortQuestMapScreen_Legacy::GetCurrentPageCameraMode() const
{
	return EFrontEndCamera();
}

void UFortQuestMapScreen_Legacy::HandleEventQuestMapActivate()
{
}

void UFortQuestMapScreen_Legacy::HandleMapViewerNavigationRequest(EViewerNavigationDirection Direction)
{
}

void UFortQuestMapScreen_Legacy::HandleQuestIndexSelectionModelChanged(bool bUpdateButtonSelection)
{
}

void UFortQuestMapScreen_Legacy::HandleRequestCurrentQuestNavigation()
{
}

void UFortQuestMapScreen_Legacy::InitializeQuestData()
{
}

bool UFortQuestMapScreen_Legacy::IsBeyondQuest(UFortQuestItemDefinition* QuestDef) const
{
	return false;
}

bool UFortQuestMapScreen_Legacy::IsEventFlagActive(const FString& EventFlag)
{
	return false;
}

void UFortQuestMapScreen_Legacy::SetBeyondCutoffQuest(bool bBeyondCutoff)
{
}

void UFortQuestMapScreen_Legacy::SetIgnorePageNavigation(bool bIgnoreNavigation)
{
}

void UFortQuestMapScreen_Legacy::SetQuestMapViewer(UFortQuestMapViewer_Legacy* Value)
{
}

void UFortQuestMapScreen_Legacy::ToggleQuestMapState()
{
}
