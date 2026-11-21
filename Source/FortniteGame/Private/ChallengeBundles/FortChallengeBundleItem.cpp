// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChallengeBundles/FortChallengeBundleItem.h"

bool UFortChallengeBundleItem::CanLevelUpBundle() const
{
	return false;
}

void UFortChallengeBundleItem::GetAchievedCount(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount) const
{
}

UFortChallengeBundleItemDefinition* UFortChallengeBundleItem::GetChallengeDefinitionBP() const
{
	return nullptr;
}

float UFortChallengeBundleItem::GetPercentageComplete() const
{
	return float();
}

void UFortChallengeBundleItem::GetQuests(const UFortQuestManager* QuestManager, TArray<UFortQuestItem*>& OwnedQuests, TArray<UFortQuestItemDefinition*>& UnownedQuests, bool bGetAllQuestsInChain, bool bIgnoreInvalidGrantedQuests) const
{
}

bool UFortChallengeBundleItem::IsComplete() const
{
	return false;
}
