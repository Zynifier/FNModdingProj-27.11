// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortBadgeItemDefinition.h"

EStatCategory UFortBadgeItemDefinition::GetBadgeScoreCategory() const
{
	return EStatCategory();
}

int32 UFortBadgeItemDefinition::GetBadgeScoreThreshold() const
{
	return int32();
}

int32 UFortBadgeItemDefinition::GetMissionPoints() const
{
	return int32();
}

int32 UFortBadgeItemDefinition::GetScoreAwarded(const APlayerController* PlayerController) const
{
	return int32();
}

int32 UFortBadgeItemDefinition::GetUIMissionPointsOffset() const
{
	return int32();
}
