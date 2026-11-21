// Copyright Epic Games, Inc. All Rights Reserved.

#include "LevelStreaming/VerseLevelStreamingComponentBase.h"
#include "Net/UnrealNetwork.h"

void UVerseLevelStreamingComponentBase::OnLevelShown_Client()
{
}

void UVerseLevelStreamingComponentBase::OnLevelShown_Server()
{
}

void UVerseLevelStreamingComponentBase::OnLevelUnloaded_Client()
{
}

void UVerseLevelStreamingComponentBase::OnLevelUnloaded_Server()
{
}

void UVerseLevelStreamingComponentBase::OnRep_NewLevel()
{
}

void UVerseLevelStreamingComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseLevelStreamingComponentBase, NewLevel);
}

void UVerseLevelStreamingPlayerControllerRpcComponent::TellServer_ClientLevelLoaded_Implementation(UVerseLevelStreamingComponentBase* LevelStreamingComponent)
{
}

void UVerseLevelStreamingPlayerControllerRpcComponent::TellServer_ClientLevelUnloaded_Implementation(UVerseLevelStreamingComponentBase* LevelStreamingComponent)
{
}
