// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationBaseWidget.h"

uint8 UInfiltrationBaseWidget::GetAttackingTeam() const
{
	return uint8();
}

EIntelStateEnum UInfiltrationBaseWidget::GetCurrentIntelState() const
{
	return EIntelStateEnum();
}

int32 UInfiltrationBaseWidget::GetCurrentRound() const
{
	return int32();
}

uint8 UInfiltrationBaseWidget::GetDefendingTeam() const
{
	return uint8();
}

float UInfiltrationBaseWidget::GetGroundTimeRemaining() const
{
	return float();
}

bool UInfiltrationBaseWidget::GetIsCurrentlyDefended() const
{
	return false;
}

int32 UInfiltrationBaseWidget::GetNumOfRounds() const
{
	return int32();
}

bool UInfiltrationBaseWidget::IsBeingHeldByLocalPlayer() const
{
	return false;
}

bool UInfiltrationBaseWidget::IsLocalPlayerAttacking() const
{
	return false;
}

bool UInfiltrationBaseWidget::IsLocalPlayerDefending() const
{
	return false;
}
