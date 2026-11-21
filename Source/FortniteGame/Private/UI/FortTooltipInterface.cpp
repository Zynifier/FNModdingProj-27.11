// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortTooltipInterface.h"

UFortTooltipDisplayStatsList* IFortTooltipInterface::GetDisplayStats() const
{
	return nullptr;
}

TSubclassOf<UFortTooltip> IFortTooltipInterface::GetTooltip(bool bSummaryTooltip) const
{
	return TSubclassOf<UFortTooltip>();
}
