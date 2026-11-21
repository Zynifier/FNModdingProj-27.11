// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationStatusWidget.h"

uint8 UInfiltrationStatusWidget::GetAttackingTeam() const
{
	return uint8();
}

int32 UInfiltrationStatusWidget::GetCurrentRound() const
{
	return int32();
}

uint8 UInfiltrationStatusWidget::GetDefendingTeam() const
{
	return uint8();
}

int32 UInfiltrationStatusWidget::GetNumOfRounds() const
{
	return int32();
}

USoundBase* UInfiltrationStatusWidget::GetSoundFromIntelState(EIntelStateEnum InState, bool bIsDefender) const
{
	return nullptr;
}

bool UInfiltrationStatusWidget::IsCurrentlyADraw() const
{
	return false;
}

bool UInfiltrationStatusWidget::IsLocalPlayerAttacking() const
{
	return false;
}

bool UInfiltrationStatusWidget::IsLocalPlayerDefending() const
{
	return false;
}
