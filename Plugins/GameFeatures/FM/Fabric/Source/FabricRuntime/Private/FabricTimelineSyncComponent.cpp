// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricTimelineSyncComponent.h"
#include "Net/UnrealNetwork.h"

void UFabricTimelineSyncComponent::OnRep_ServerCurrentSongPos()
{
}

void UFabricTimelineSyncComponent::OnTimelinePlayingChanged(EMusicClockState State)
{
}

void UFabricTimelineSyncComponent::SetFabricMetaSoundManager(UFabricMetaSoundManagerComponent* MusicManagerComponent)
{
}

void UFabricTimelineSyncComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFabricTimelineSyncComponent, ServerCurrentSongRenderPos);
}
