// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortHidingProp.h"

void AFortHidingProp::SetInputEnabled(AFortPlayerPawn* TargetPlayerPawn, bool bEnabled)
{
}

bool AFortHidingProp::ShouldUseInteractionForExit() const
{
	return false;
}

void AFortHidingProp::UpdateHiddenPlayerStat(const TMap<AFortPawn*, double>& HiddenPlayerAndEnterTimes)
{
}
