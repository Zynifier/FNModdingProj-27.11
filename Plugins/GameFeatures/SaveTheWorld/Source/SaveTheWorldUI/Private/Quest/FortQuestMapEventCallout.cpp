// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quest/FortQuestMapEventCallout.h"

void UFortQuestMapEventCallout::DeactivateCallout()
{
}

int32 UFortQuestMapEventCallout::GetEventCount() const
{
	return int32();
}

bool UFortQuestMapEventCallout::GetIsExpanded() const
{
	return false;
}

bool UFortQuestMapEventCallout::GetIsFaded() const
{
	return false;
}

UFortQuestItemDefinition* UFortQuestMapEventCallout::GetRequiredQuestForCurrentEvent() const
{
	return nullptr;
}

bool UFortQuestMapEventCallout::IsCurrentEventUnlocked() const
{
	return false;
}

void UFortQuestMapEventCallout::PlayFadeIn()
{
}

void UFortQuestMapEventCallout::PlayFadeOut()
{
}

void UFortQuestMapEventCallout::ResetCallout()
{
}

void UFortQuestMapEventCallout::SetIsExpanded(bool Expanded)
{
}

void UFortQuestMapEventCallout::SetIsFaded(bool Faded)
{
}

void UFortQuestMapEventCallout::UpdateActiveEvents()
{
}

void UFortQuestMapEventCallout::UpdateCalloutData()
{
}

void UFortQuestMapEventCallout::UpdateGoButtonBangState(bool bClear)
{
}
