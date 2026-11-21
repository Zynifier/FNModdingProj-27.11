// Copyright Epic Games, Inc. All Rights Reserved.

#include "Upgrades/FortUpgradeScreenBase.h"

bool UFortUpgradeScreenBase::AreUpgradesRespecTokensAvailable() const
{
	return false;
}

bool UFortUpgradeScreenBase::CanPreview() const
{
	return false;
}

int32 UFortUpgradeScreenBase::GetUpgradesRespecTokenCount() const
{
	return int32();
}

void UFortUpgradeScreenBase::HandleTabSelected(FName TabId)
{
}

bool UFortUpgradeScreenBase::IsPreviewing() const
{
	return false;
}

void UFortUpgradeScreenBase::RefreshFocus()
{
}

void UFortUpgradeScreenBase::TogglePreview()
{
}

void UFortUpgradeScreenBase::UseUpgradesRespecToken()
{
}
