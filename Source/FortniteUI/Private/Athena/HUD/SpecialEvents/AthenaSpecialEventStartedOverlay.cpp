// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/SpecialEvents/AthenaSpecialEventStartedOverlay.h"

float UAthenaSpecialEventStartedOverlay::GetOutroDelay() const
{
	return float();
}

void UAthenaSpecialEventStartedOverlay::HandleDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool DisplayStatusUpdate, bool DisplayAnnouncementUpdate)
{
}

void UAthenaSpecialEventStartedOverlay::HandleShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData, const float EventTimeRemaining)
{
}
