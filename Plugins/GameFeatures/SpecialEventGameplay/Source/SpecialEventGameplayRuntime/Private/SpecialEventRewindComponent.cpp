// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventRewindComponent.h"
#include "Net/UnrealNetwork.h"

void USpecialEventRewindComponent::OnRep_StateData(const FSpecialEventRewindComponentStateData& OldStateData)
{
}

bool USpecialEventRewindComponent::TryStartRewinding(const float Duration, const float PlaybackSpeed)
{
	return false;
}

void USpecialEventRewindComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpecialEventRewindComponent, StateData);
	DOREPLIFETIME(USpecialEventRewindComponent, ReplicatedRewindDuration);
}
