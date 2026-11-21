// Copyright Epic Games, Inc. All Rights Reserved.

#include "Upgrades/FortUpgradeScreenBase_Legacy.h"

bool UFortUpgradeScreenBase_Legacy::AreUpgradesRespecTokensAvailable() const
{
	return false;
}

bool UFortUpgradeScreenBase_Legacy::CanPreview() const
{
	return false;
}

int32 UFortUpgradeScreenBase_Legacy::GetUpgradesRespecTokenCount() const
{
	return int32();
}

void UFortUpgradeScreenBase_Legacy::HandleTabSelected(FName TabId)
{
}

bool UFortUpgradeScreenBase_Legacy::IsPreviewing() const
{
	return false;
}

void UFortUpgradeScreenBase_Legacy::RefreshFocus()
{
}

void UFortUpgradeScreenBase_Legacy::TogglePreview()
{
}

void UFortUpgradeScreenBase_Legacy::UseUpgradesRespecToken()
{
}
