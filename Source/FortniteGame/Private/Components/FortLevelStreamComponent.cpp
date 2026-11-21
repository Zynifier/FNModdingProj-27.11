// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortLevelStreamComponent.h"
#include "Net/UnrealNetwork.h"

void UFortLevelStreamComponent::ClientHasFinishedLevelStreaming(AFortPlayerState* StreamedInPlayer)
{
}

bool UFortLevelStreamComponent::IsLoaded() const
{
	return false;
}

bool UFortLevelStreamComponent::IsLoading() const
{
	return false;
}

bool UFortLevelStreamComponent::IsUnloaded() const
{
	return false;
}

void UFortLevelStreamComponent::OnLevelLoaded()
{
}

void UFortLevelStreamComponent::OnLevelShown()
{
}

void UFortLevelStreamComponent::OnRep_LevelStreamingData()
{
}

void UFortLevelStreamComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortLevelStreamComponent, LevelStreamingData);
}
