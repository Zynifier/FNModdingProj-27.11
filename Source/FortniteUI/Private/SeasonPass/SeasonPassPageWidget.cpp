// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeasonPass/SeasonPassPageWidget.h"

int32 USeasonPassPageWidget::GetCurrentSeasonNumber() const
{
	return int32();
}

bool USeasonPassPageWidget::OwnsSeasonPass() const
{
	return false;
}

bool USeasonPassPageWidget::ShouldPlayInto(int32 FirstLevel)
{
	return false;
}
