// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/AthenaSeasonItemDefinition.h"

#if WITH_EDITOR
void UAthenaSeasonItemDefinition::CleanupScratchAssets()
{
}
#endif

bool UAthenaSeasonItemDefinition::IsUsingMidSeasonUpdatesDataAsset() const
{
	return false;
}

bool UAthenaSeasonItemDefinition::IsUsingProfileItemsToRemoveAtSeasonEndDataAsset() const
{
	return false;
}

bool UAthenaSeasonItemDefinition::IsUsingSeasonGrantsToEveryoneDataAsset() const
{
	return false;
}

#if WITH_EDITOR
UAthenaSeasonItemDefinition* UAthenaSeasonItemDefinition::NextSeasonCreate()
{
	return nullptr;
}
#endif

#if WITH_EDITOR
void UAthenaSeasonItemDefinition::NextSeasonPostCopy()
{
}
#endif

#if WITH_EDITOR
void UAthenaSeasonItemDefinition::SaveScratchAssets(bool bIncludeSelf, bool bWaitForCompletion)
{
}
#endif

#if WITH_EDITOR
void UAthenaSeasonItemDefinition::ShowBattlePassCurrenciesAndCosts() const
{
}
#endif
