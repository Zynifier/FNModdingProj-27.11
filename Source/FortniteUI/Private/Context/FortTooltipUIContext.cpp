// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortTooltipUIContext.h"

bool UFortTooltipUIContext::GetCombinedDescription(const UObject* Object, const UFortTooltipContext* TooltipContext, FText& OutDescription, bool bSummaryDescription) const
{
	return false;
}

TArray<FFortDisplayAttribute> UFortTooltipUIContext::GetComparisonStats(const UObject* Object, const UObject* ComparisonObject, const UFortTooltipContext* TooltipContext, bool bUseSummaryTooltip) const
{
	return TArray<FFortDisplayAttribute>();
}

bool UFortTooltipUIContext::GetDescription(const UObject* Object, const UFortTooltipContext* TooltipContext, TArray<FText>& OutDescription, bool bSummaryDescription) const
{
	return false;
}

bool UFortTooltipUIContext::GetDisplayNameAndMultiBrushForTag(const FGameplayTag& Tag, FText& OutDisplayName, FFortMultiSizeBrush& OutBrush) const
{
	return false;
}

TArray<FGameplayAttribute> UFortTooltipUIContext::GetTooltipAttributes(const UObject* Object)
{
	return TArray<FGameplayAttribute>();
}

UFortTooltipLoadingWrapper* UFortTooltipUIContext::GetTooltipLoadingWrapper(const UObject* Object, bool bSummaryDescription) const
{
	return nullptr;
}

bool UFortTooltipUIContext::GetTooltipStat(const UObject* Object, UFortTooltipContext* TooltipContext, const FGameplayTag Token, FFortDisplayAttribute& OutDisplayAttribute, bool bUseSummaryTooltip) const
{
	return false;
}

TArray<FFortDisplayAttribute> UFortTooltipUIContext::GetTooltipStats(const UObject* Object, const UFortTooltipContext* TooltipContext, bool bSummaryStats) const
{
	return TArray<FFortDisplayAttribute>();
}

bool UFortTooltipUIContext::GetUIDataForTag(const FGameplayTag& Tag, FFortTagUIData& OutData) const
{
	return false;
}

TArray<FFortDisplayAttribute> UFortTooltipUIContext::GetUpgradeStats(const UObject* Object, UFortTooltipContext* TooltipContext, const int32 UpgradeLevelDelta, bool bUseSummaryTooltip) const
{
	return TArray<FFortDisplayAttribute>();
}

bool UFortTooltipUIContext::HasTooltipStats(const UObject* Object)
{
	return false;
}
