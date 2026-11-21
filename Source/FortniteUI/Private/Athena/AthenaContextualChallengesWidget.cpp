// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaContextualChallengesWidget.h"

float UAthenaContextualChallengesWidget::GetOutroDelay() const
{
	return float();
}

void UAthenaContextualChallengesWidget::HandleNewContextualObjectives(const TArray<UFortQuestItem*>& InContextualQuests)
{
}

void UAthenaContextualChallengesWidget::HandleToggleFullscreenMap(bool bFullscreenMapVisible)
{
}

bool UAthenaContextualChallengesWidget::ShouldOutroAutomatically() const
{
	return false;
}
