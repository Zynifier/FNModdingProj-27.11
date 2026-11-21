// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationRoundInfoWidget.h"

uint8 UInfiltrationRoundInfoWidget::GetAttackingTeam() const
{
	return uint8();
}

uint8 UInfiltrationRoundInfoWidget::GetDefendingTeam() const
{
	return uint8();
}

int32 UInfiltrationRoundInfoWidget::GetFirstRound() const
{
	return int32();
}

USoundBase* UInfiltrationRoundInfoWidget::GetRoundIntroFactionSound(bool bLocalTeamIsAttackers) const
{
	return nullptr;
}

void UInfiltrationRoundInfoWidget::GetRoundResultsText(FText& OutResultsText, bool bLocalTeamIsAttackers, bool bLocalTeamIsWinners) const
{
}

uint8 UInfiltrationRoundInfoWidget::GetViewingTeam() const
{
	return uint8();
}

bool UInfiltrationRoundInfoWidget::HasWinningTeam() const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::IsLocalPlayerAttacking() const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::IsLocalPlayerAttackingNextRound() const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::IsLocalPlayerDefending() const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::IsLocalPlayerDefendingNextRound() const
{
	return false;
}

void UInfiltrationRoundInfoWidget::SetWinningTeam(uint8 NewWinningTeam)
{
}

bool UInfiltrationRoundInfoWidget::ShouldModifyAttackingDefendingText(FText& OutAttackingDefendingText, bool bLocalTeamIsAttackers) const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::ShouldPlayFactionIntro() const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::ShouldPlayRoundEndStinger() const
{
	return false;
}

bool UInfiltrationRoundInfoWidget::ShouldSkipWinLossScreen() const
{
	return false;
}
