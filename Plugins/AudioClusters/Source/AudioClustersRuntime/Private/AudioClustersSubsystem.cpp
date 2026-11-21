// Copyright Epic Games, Inc. All Rights Reserved.

#include "AudioClustersSubsystem.h"

bool UAudioClustersSubsystem::AddConfigMap(UAudioClusterConfigMap* Map)
{
	return false;
}

bool UAudioClustersSubsystem::Register(const FAudioClusterActorInfo& ActorInfo)
{
	return false;
}

bool UAudioClustersSubsystem::RegisterOneShot(const FAudioClusterOneShotInfo& OneShotInfo)
{
	return false;
}

bool UAudioClustersSubsystem::RemoveConfigMap(UAudioClusterConfigMap* Map)
{
	return false;
}

void UAudioClustersSubsystem::SetListenerPosition(const FVector& InListenerPosition)
{
}

bool UAudioClustersSubsystem::SetParam(const FGameplayTag& Tag, double Value)
{
	return false;
}

bool UAudioClustersSubsystem::Unregister(const FAudioClusterActorInfo& ActorInfo)
{
	return false;
}

void UAudioClustersSubsystem::UpdateClusters(float DeltaTimeSeconds)
{
}
