// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_MemorySampler.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_MemorySampler::BeginMemorySampling()
{
}

void UFortControllerComponent_MemorySampler::ClientBroadcastResults_Implementation(bool bSuccess, int32 MemoryValue, int32 MemoryThreshold)
{
}

void UFortControllerComponent_MemorySampler::ClientEndMemorySampling_Implementation()
{
}

void UFortControllerComponent_MemorySampler::ClientNotifyPreBeginSampling_Implementation()
{
}

void UFortControllerComponent_MemorySampler::ClientNotifyRefreshMemoryTracker_Implementation()
{
}

void UFortControllerComponent_MemorySampler::EndMemorySampling()
{
}

void UFortControllerComponent_MemorySampler::OnRep_MemorySamplerProgress() const
{
}

void UFortControllerComponent_MemorySampler::OnRep_MemorySamplerState()
{
}

void UFortControllerComponent_MemorySampler::ServerAckClientReadyForSampling_Implementation(bool bRequiresSpatialSampling)
{
}

void UFortControllerComponent_MemorySampler::ServerBeginMemorySampling_Implementation()
{
}

void UFortControllerComponent_MemorySampler::ServerEndMemorySampling_Implementation()
{
}

void UFortControllerComponent_MemorySampler::ServerReleaseSamplingLocation_Implementation(int32 MemoryValue, const TArray<FFortActorTemplateStats>& ActorStats)
{
}

void UFortControllerComponent_MemorySampler::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_MemorySampler, MemorySamplerState);
	DOREPLIFETIME(UFortControllerComponent_MemorySampler, MemorySamplerProgress);
}
