// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIStateChartManager.h"

int32 UUIStateChartManager::BP_AddStateChart(const UUIStateChart* StateChartAsset, ULocalPlayer* OwningLocalPlayer, const FGameplayTagContainer& AnimationHints, const FGameplayTag InitialStateTag, EUIStateTransitionUrgency Urgency)
{
	return int32();
}

bool UUIStateChartManager::BP_DeactivateStateChart(int32 Key, const FGameplayTagContainer& AnimationHints, const FUIStateChartContextChangeSet& ContextChanges, EUIStateTransitionUrgency Urgency)
{
	return false;
}

bool UUIStateChartManager::BP_DispatchTransitionEvent(const FGameplayTag TransitionTag, const ULocalPlayer* StateChartOwner, const FGameplayTagContainer& AnimationHints, const FUIStateChartContextChangeSet& ContextChanges, EUIStateTransitionUrgency Urgency, bool bBacktrack)
{
	return false;
}

void UUIStateChartManager::BP_ReactivateStateChart(int32 Key, const FGameplayTagContainer& AnimationHints, const FGameplayTag StateTag, EUIStateTransitionUrgency Urgency)
{
}

bool UUIStateChartManager::BP_RemoveStateChart(int32 Key, const FGameplayTagContainer& AnimationHints, const FUIStateChartContextChangeSet& ContextChanges, EUIStateTransitionUrgency Urgency)
{
	return false;
}

UUIStateChartContext* UUIStateChartManager::GetContext() const
{
	return nullptr;
}
