// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIStateChartContext.h"

void UUIStateChartContext::BP_ApplyCommonChanges(const FUIStateChartContextChangeSet& ContextChanges)
{
}

void UUIStateChartContext::BP_ApplyPlayerChanges(const ULocalPlayer* LocalPlayer, const FUIStateChartContextChangeSet& ContextChanges)
{
}

void UUIStateChartContext::BP_ClearCommonValue(const FGameplayTag Key)
{
}

void UUIStateChartContext::BP_ClearEntry(const FGameplayTag Key)
{
}

void UUIStateChartContext::BP_ClearPlayerValue(const ULocalPlayer* LocalPlayer, const FGameplayTag& Key)
{
}

UUIStateChartContextEntry* UUIStateChartContext::BP_FindEntry(const FGameplayTag Key) const
{
	return nullptr;
}

void UUIStateChartContext::BP_SetCommonBoolValue(const FGameplayTag Key, bool Value)
{
}

void UUIStateChartContext::BP_SetCommonFloatValue(const FGameplayTag Key, float Value)
{
}

void UUIStateChartContext::BP_SetCommonIntValue(const FGameplayTag Key, int32 Value)
{
}

void UUIStateChartContext::BP_SetCommonStringValue(const FGameplayTag Key, const FString Value)
{
}

void UUIStateChartContext::BP_SetPlayerBoolValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, bool Value)
{
}

void UUIStateChartContext::BP_SetPlayerFloatValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, float Value)
{
}

void UUIStateChartContext::BP_SetPlayerStringValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, const FString Value)
{
}

void UUIStateChartContext::BP_SetPlayerValue(const ULocalPlayer* LocalPlayer, const FGameplayTag Key, int32 Value)
{
}
