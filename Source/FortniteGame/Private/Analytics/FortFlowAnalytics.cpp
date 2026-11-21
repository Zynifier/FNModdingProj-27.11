// Copyright Epic Games, Inc. All Rights Reserved.

#include "Analytics/FortFlowAnalytics.h"

void UFortFlowAnalytics::FireEvent_AddImpression_BP(const FString& SectionID, const TArray<FFlowAnalyticsImpressionSectionContent>& SectionContents)
{
}

void UFortFlowAnalytics::FireEvent_ElementInteracted_BP(const UWidget* Element, const FString& AdditionalDetails)
{
}

void UFortFlowAnalytics::FireEvent_ElementInteractedByName_BP(const AFortPlayerController* FortPC, const FString& ElementName, const FString& AdditionalDetails)
{
}

void UFortFlowAnalytics::FireEvent_FlushImpressions_BP(const AFortPlayerController* FortPC)
{
}

void UFortFlowAnalytics::FireEvent_MainViewOpened_BP(const UWidget* View, const TArray<UWidget*>& Elements, const FString& AdditionalDetails)
{
}

void UFortFlowAnalytics::FireEvent_SubViewOpened_BP(const UWidget* View, const TArray<UWidget*>& Elements, const FString& AdditionalDetails)
{
}
