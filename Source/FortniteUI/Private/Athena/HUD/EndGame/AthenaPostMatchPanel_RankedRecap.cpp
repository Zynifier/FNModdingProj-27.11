// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/EndGame/AthenaPostMatchPanel_RankedRecap.h"

float UAthenaPostMatchPanel_RankedRecap::GetFailsafeDelayDuration() const
{
	return float();
}

bool UAthenaPostMatchPanel_RankedRecap::GetUnrankedTierData(FFortHabaneroTier& OutUnrankedTierData)
{
	return false;
}

void UAthenaPostMatchPanel_RankedRecap::PlayQuestsIntro() const
{
}

void UAthenaPostMatchPanel_RankedRecap::QueryProgress()
{
}
