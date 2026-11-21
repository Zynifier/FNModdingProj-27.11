// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayDataTracker/FortGameplayDataTrackerComponent.h"
#include "Net/UnrealNetwork.h"

UFortGameplayDataTrackerComponent::UFortGameplayDataTrackerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortGameplayDataTrackerComponent::AddDataAccumulation(FFortGameplayDataTrackerAccumulation Accumulation)
{
	return false;
}

float UFortGameplayDataTrackerComponent::GetAccumulationValue(const FGameplayTag& AccumulationTag) const
{
	return float();
}

float UFortGameplayDataTrackerComponent::GetEventValue(const FGameplayTag& EventTag) const
{
	return float();
}

void UFortGameplayDataTrackerComponent::HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortGameplayDataTrackerComponent::OnRep_EventValues()
{
}

bool UFortGameplayDataTrackerComponent::RegisterForAccumulationRangeEvents(const FGameplayTag& AccumulationTag, const FGameplayTag& RangeTag, FFortTrackedGameplayDataRangeChanged Delegate)
{
	return false;
}

bool UFortGameplayDataTrackerComponent::RegisterForEventValueRange(const FGameplayTag& Event, FFortGameplayDataTrackedRange Range, FFortTrackedGameplayDataRangeChanged Delegate)
{
	return false;
}

void UFortGameplayDataTrackerComponent::TriggerEvent(const FGameplayTag& EventTag, float Value)
{
}

void UFortGameplayDataTrackerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameplayDataTrackerComponent, ReplicatedEventValues);
}
