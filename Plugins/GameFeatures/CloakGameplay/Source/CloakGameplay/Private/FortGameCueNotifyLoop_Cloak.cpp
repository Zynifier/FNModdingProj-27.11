// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameCueNotifyLoop_Cloak.h"

bool AFortGameCueNotifyLoop_Cloak::GetCurrentModifierValues(float& OutVisibilityMultiplier, float& OutVisibilityAddition, const FName& ModifierName) const
{
	return false;
}

bool AFortGameCueNotifyLoop_Cloak::SetModifierCanBeEnabled(const FName& ModifierName, const bool bNewCanBeEnabled)
{
	return false;
}

bool AFortGameCueNotifyLoop_Cloak::SetModifierEnabled(const FName& ModifierName, const bool bNewEnabled)
{
	return false;
}

float AFortGameCueNotifyLoop_Cloak::TickVisibilityLevel(const float DeltaSeconds)
{
	return float();
}
