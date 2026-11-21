// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaCustomizationScreenBase.h"

void UAthenaCustomizationScreenBase::ActionBarToolTipSeen()
{
}

void UAthenaCustomizationScreenBase::QuickSaveToolTipSeen()
{
}

bool UAthenaCustomizationScreenBase::ShouldShowActionBarTooltip()
{
	return false;
}

bool UAthenaCustomizationScreenBase::ShouldShowQuickSaveTooltip() const
{
	return false;
}

bool UAthenaCustomizationScreenBase::ShouldShowTemporaryItemsTooltip() const
{
	return false;
}

void UAthenaCustomizationScreenBase::TemporaryItemsToolTipSeen()
{
}
