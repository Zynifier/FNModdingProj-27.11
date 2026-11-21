// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ProfileStats/AthenaProfileStatContext.h"

float UAthenaBaseStatView::GetStat(const FGameplayTag& InStat) const
{
	return float();
}

const FDateTime UAthenaMatchStatView::GetMatchEndTime() const
{
	return FDateTime();
}

FString UAthenaMatchStatView::GetMatchID() const
{
	return FString();
}

TArray<UAthenaWeaponStatView*> UAthenaMatchStatView::GetSortedWeaponViews(const FGameplayTag& InStat) const
{
	return TArray<UAthenaWeaponStatView*>();
}

UAthenaWeaponStatView* UAthenaMatchStatView::GetWeaponViewHighestStat(const FGameplayTag& InStat) const
{
	return nullptr;
}

TArray<UAthenaWeaponStatView*> UAthenaMatchStatView::GetWeaponViews() const
{
	return TArray<UAthenaWeaponStatView*>();
}

TArray<UAthenaMatchStatView*> UAthenaMatchSetStatView::GetBestMatchViews() const
{
	return TArray<UAthenaMatchStatView*>();
}

UAthenaSeasonStats* UAthenaMatchSetStatView::GetOwningSeason()
{
	return nullptr;
}

UAthenaMatchStatView* UAthenaProfileStatContext::CreateCurrentMatchStatView()
{
	return nullptr;
}

UAthenaMatchSetStatView* UAthenaProfileStatContext::CreateMatchStatView(UAthenaSeasonStats* StatSet, FName Bucket)
{
	return nullptr;
}

TArray<UAthenaMatchStatView*> UAthenaProfileStatContext::CreateMatchViews(const TArray<FAthenaMatchStats>& InRecentMatches)
{
	return TArray<UAthenaMatchStatView*>();
}

UFortWeaponItemDefinition* UAthenaWeaponStatView::GetWeaponDefinition() const
{
	return nullptr;
}
