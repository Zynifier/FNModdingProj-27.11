// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortTutorialContext.h"

bool UFortTutorialContext::CanStartTutorial(UFortQuestItem* Quest, FName WidgetName, ETutorialType TutorialType)
{
	return false;
}

void UFortTutorialContext::ClearTutorialCallouts()
{
}

void UFortTutorialContext::ContinueTutorial()
{
}

void UFortTutorialContext::DisableTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName, ETutorialType TutorialType)
{
}

void UFortTutorialContext::EnableTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName, ETutorialType TutorialType)
{
}

void UFortTutorialContext::FinishTutorial(UFortQuestItem* Quest, FName WidgetName, ETutorialType TutorialType)
{
}

void UFortTutorialContext::GetHiddenTutorialCallouts(TArray<FName>& WidgetNames)
{
}

void UFortTutorialContext::GetTutorialCallouts(TArray<FName>& WidgetNames)
{
}

bool UFortTutorialContext::GetTutorialData(const FName& TutorialObjectiveName, FFortUITutorialData& OutTutorialData) const
{
	return false;
}

void UFortTutorialContext::HideTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName, ETutorialType TutorialType)
{
}

bool UFortTutorialContext::IsObjectiveNextTutorialObjective(UFortQuestItem* Quest, FName TutorialObjectiveName)
{
	return false;
}

bool UFortTutorialContext::IsTutorialCalloutVisible(FName WidgetName)
{
	return false;
}

void UFortTutorialContext::OnNewAnnouncementStartedOnClient(AFortClientAnnouncement* NewAnnouncement)
{
}

bool UFortTutorialContext::ShouldPromptToSkipTutorial() const
{
	return false;
}

void UFortTutorialContext::SkipTutorial()
{
}

void UFortTutorialContext::StartTutorial(FName WidgetName, ETutorialType TutorialType)
{
}

void UFortTutorialContext::TryClearingPendingQuest(UFortQuestItem* Quest)
{
}

AFortClientAnnouncement* UFortTutorialContext::TryGetActivePrimaryAnnouncement() const
{
	return nullptr;
}

void UFortTutorialContext::UnhideAllTutorialCallouts()
{
}

void UFortTutorialContext::UnhideTutorialCallout(FName WidgetName, FName TutorialQuestObjectiveName, ETutorialType TutorialType)
{
}

void UFortTutorialContext::UpdateTutorialAnnouncement(FFortClientAnnouncementData_Tutorial AnnouncementData, bool bShow)
{
}
