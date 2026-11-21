// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quest/FortQuestMapScreen.h"

void UFortQuestMapScreen::CheckForNewMainQuest()
{
}

bool UFortQuestMapScreen::GetBeyondCutoffQuest() const
{
	return false;
}

EFrontEndCamera UFortQuestMapScreen::GetCurrentPageCameraMode() const
{
	return EFrontEndCamera();
}

void UFortQuestMapScreen::HandleEventQuestMapActivate()
{
}

void UFortQuestMapScreen::HandleMapViewerNavigationRequest(EViewerNavigationDirection Direction)
{
}

void UFortQuestMapScreen::HandleQuestIndexSelectionModelChanged(bool bUpdateButtonSelection)
{
}

void UFortQuestMapScreen::InitializeQuestData()
{
}

bool UFortQuestMapScreen::IsBeyondQuest(UFortQuestItemDefinition* QuestDef) const
{
	return false;
}

bool UFortQuestMapScreen::IsEventFlagActive(const FString& EventFlag)
{
	return false;
}

void UFortQuestMapScreen::SetBeyondCutoffQuest(bool bBeyondCutoff)
{
}

void UFortQuestMapScreen::SetIgnorePageNavigation(bool bIgnoreNavigation)
{
}

void UFortQuestMapScreen::SetQuestMapViewer(UFortQuestMapViewer* Value)
{
}

void UFortQuestMapScreen::ShowQuestLog(UFortQuestItem* QuestItem)
{
}

void UFortQuestMapScreen::ToggleQuestMapState()
{
}

void UFortQuestMapScreen::UpdateInputActionStates(bool bShowingCallout)
{
}
