// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quest/FortQuestMapEventCallout_Legacy.h"

void UFortQuestMapEventCallout_Legacy::DeactivateCallout()
{
}

int32 UFortQuestMapEventCallout_Legacy::GetEventCount() const
{
	return int32();
}

bool UFortQuestMapEventCallout_Legacy::GetIsExpanded() const
{
	return false;
}

bool UFortQuestMapEventCallout_Legacy::GetIsFaded() const
{
	return false;
}

UFortQuestItemDefinition* UFortQuestMapEventCallout_Legacy::GetRequiredQuestForCurrentEvent() const
{
	return nullptr;
}

bool UFortQuestMapEventCallout_Legacy::IsCurrentEventUnlocked() const
{
	return false;
}

void UFortQuestMapEventCallout_Legacy::PlayFadeIn()
{
}

void UFortQuestMapEventCallout_Legacy::PlayFadeOut()
{
}

void UFortQuestMapEventCallout_Legacy::ResetCallout()
{
}

void UFortQuestMapEventCallout_Legacy::SetIsExpanded(bool Expanded)
{
}

void UFortQuestMapEventCallout_Legacy::SetIsFaded(bool Faded)
{
}

void UFortQuestMapEventCallout_Legacy::UpdateActiveEvents()
{
}

void UFortQuestMapEventCallout_Legacy::UpdateCalloutData()
{
}

void UFortQuestMapEventCallout_Legacy::UpdateGoButtonBangState(bool bClear)
{
}
