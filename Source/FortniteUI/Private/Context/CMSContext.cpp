// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/CMSContext.h"

FCreativeAdSource UCMSContext::GetLatestCreativeAds()
{
	return FCreativeAdSource();
}

FDynamicBackgroundsSource UCMSContext::GetLatestDynamicBackgrounds() const
{
	return FDynamicBackgroundsSource();
}

const FSubgameScreenSource UCMSContext::GetLatestSubgameInfo()
{
	return FSubgameScreenSource();
}

const FFortShowdownScoringRuleDisplayInfo UCMSContext::GetScoringRuleDisplayInfo(const FName RuleName) const
{
	return FFortShowdownScoringRuleDisplayInfo();
}

bool UCMSContext::GetSurvivalCMSText(FText& Title, FText& Body) const
{
	return false;
}

bool UCMSContext::HasScoringRuleDisplayInfo(const FName RuleName) const
{
	return false;
}

bool UCMSContext::IsNewPlaylistInformationAvailable() const
{
	return false;
}

void UCMSContext::MarkNewsAsShown()
{
}

void UCMSContext::MarkPlaylistInformationAsViewed()
{
}

bool UCMSContext::ShouldAutoOpenNews() const
{
	return false;
}
