// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Map/AthenaQuestCategoryCompletedTracker.h"

UAthenaQuestCategoryCompletedTracker::UAthenaQuestCategoryCompletedTracker(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UAthenaQuestCategoryCompletedTracker::GetIsProgressBarEnabled() const
{
	return false;
}
