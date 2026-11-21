// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortHomebase/FortHomebaseContext.h"

void UHomeBaseContext::BroadcastSquadSlotMarkedAsSeen()
{
}

void UHomeBaseContext::ClearHeroLoadout(UFortCampaignHeroLoadoutItem* HeroLoadout)
{
}

bool UHomeBaseContext::DoesTeamMeetMaximumHomebaseRatingRequirement(int32 MaximumAllowedHomebaseRating, bool bUsePhoenixStats) const
{
	return false;
}

bool UHomeBaseContext::DoesTeamMeetRequiredHomebaseRating(int32 RequiredHomebaseRating, bool bUsePhoenixStats) const
{
	return false;
}

FName UHomeBaseContext::GetActiveDefenderSquadId() const
{
	return FName();
}

UFortCampaignHeroLoadoutItem* UHomeBaseContext::GetActiveHeroLoadout() const
{
	return nullptr;
}

void UHomeBaseContext::GetAllResourceCollectorRewardEstimates(TArray<FFortItemQuantityPair>& OutEstimates)
{
}

int32 UHomeBaseContext::GetCurrentDeployedDefenderCount() const
{
	return int32();
}

FName UHomeBaseContext::GetHomebaseDefenderSquadId() const
{
	return FName();
}

bool UHomeBaseContext::GetLocalPlayerHomebaseRating(int32& Rating, float& ProgressFraction, bool bUsePhoenixStats) const
{
	return false;
}

bool UHomeBaseContext::GetLocalTeamHomebaseRating(int32& Rating, float& ProgressFraction, bool bUsePhoenixStats) const
{
	return false;
}

int32 UHomeBaseContext::GetMaxDeployableDefenderCount() const
{
	return int32();
}

FName UHomeBaseContext::GetMissionDefenderSquadId() const
{
	return FName();
}

int32 UHomeBaseContext::GetNumAccountLimitedItems()
{
	return int32();
}

void UHomeBaseContext::GetResourceCollectorRateInfo(UFortCollectedResourceItem* CollectorType, float& RatePerSecond, int32& MaxCapacity)
{
}

void UHomeBaseContext::GetResourceCollectorRewardsEstimate(UFortCollectedResourceItem* CollectorType, FFortItemQuantityPair& OutEstimate)
{
}

void UHomeBaseContext::GetResourceCollectorRewardsEstimates(const TArray<UFortCollectedResourceItem*>& CollectorTypes, TArray<FFortItemQuantityPair>& OutEstimates)
{
}

void UHomeBaseContext::GetStaticSetBonusData(const FGameplayTag& InSetBonusTag, FWorkerSetBonusData& OutSetBonusData, FFortMultiSizeBrush& OutBrush)
{
}

bool UHomeBaseContext::GetTeamHomebaseRating(const FUniqueNetIdRepl& PlayerId, int32& Rating, float& ProgressFraction, bool bUsePhoenixStats) const
{
	return false;
}

bool UHomeBaseContext::GetTotalHomebaseRating(const FUniqueNetIdRepl& UniqueId, int32& Rating, float& ProgressFraction, bool bUsePhoenixStats) const
{
	return false;
}

int32 UHomeBaseContext::GetTotalSkillPointsEarned() const
{
	return int32();
}

bool UHomeBaseContext::HasHeroUnlockedCommanderPerk(UFortHero* Hero) const
{
	return false;
}

void UHomeBaseContext::SetActiveHeroLoadout(UFortCampaignHeroLoadoutItem* HeroLoadout)
{
}

bool UHomeBaseContext::TryGetHomebaseSquadData(const FName SquadId, FHomebaseSquad& OutHomebaseSquad) const
{
	return false;
}
