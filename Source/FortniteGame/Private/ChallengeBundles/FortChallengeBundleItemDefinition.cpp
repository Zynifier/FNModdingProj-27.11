// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChallengeBundles/FortChallengeBundleItemDefinition.h"

int32 UFortChallengeBundleItemDefinition::GetBundleLevelForQuest(const UFortQuestItemDefinition* QuestDef) const
{
	return int32();
}

FString UFortChallengeBundleItemDefinition::GetCalendarEventName() const
{
	return FString();
}

TArray<FAthenaRewardItemReference> UFortChallengeBundleItemDefinition::GetCompletionRewards() const
{
	return TArray<FAthenaRewardItemReference>();
}

const FFortChallengeSetStyle& UFortChallengeBundleItemDefinition::GetDisplayStyle() const
{
	static FFortChallengeSetStyle Dummy;
	return Dummy;
}

FString UFortChallengeBundleItemDefinition::GetEventName(bool bGetExpirationEvent) const
{
	return FString();
}

const FGameplayTag& UFortChallengeBundleItemDefinition::GetGoalCardPinSeasonItemTag() const
{
	static FGameplayTag Dummy;
	return Dummy;
}

FString UFortChallengeBundleItemDefinition::GetHexCodeForStyleColor(EBundleStyleColor DesiredColor) const
{
	return FString();
}

const TSoftObjectPtr<UObject>& UFortChallengeBundleItemDefinition::GetNotificationIconOverride() const
{
	static TSoftObjectPtr<UObject> Dummy;
	return Dummy;
}

int32 UFortChallengeBundleItemDefinition::GetNumQuests() const
{
	return int32();
}

int32 UFortChallengeBundleItemDefinition::GetNumVisibleQuests() const
{
	return int32();
}

void UFortChallengeBundleItemDefinition::GetQuests(const UFortQuestManager* QuestManager, const TArray<UFortQuestItem*>& GrantedQuests, TArray<UFortQuestItem*>& OwnedQuests, TArray<UFortQuestItemDefinition*>& UnownedQuests, bool bGetAllQuestsInChain) const
{
}

int32 UFortChallengeBundleItemDefinition::GetRewardCompletionThreshold() const
{
	return int32();
}

int32 UFortChallengeBundleItemDefinition::GetTotalNumberOfQuests() const
{
	return int32();
}

bool UFortChallengeBundleItemDefinition::IsLinearChainQuest(const UFortQuestItemDefinition* InQuestDef, int32& ChainLength, int32& ChainPos) const
{
	return false;
}
