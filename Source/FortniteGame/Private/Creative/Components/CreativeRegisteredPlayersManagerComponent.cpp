// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativeRegisteredPlayersManagerComponent.h"
#include "Net/UnrealNetwork.h"

void UCreativeRegisteredPlayersManagerComponent::GetRegisteredPlayers(TArray<AFortPlayerState*>& OutPlayerStateArray)
{
}

void UCreativeRegisteredPlayersManagerComponent::OnMinigameEnded()
{
}

void UCreativeRegisteredPlayersManagerComponent::OnMinigameStarted()
{
}

void UCreativeRegisteredPlayersManagerComponent::OnPlayerRemoved(FUniqueNetIdRepl NetId, bool bIsLocalPlayer)
{
}

void UCreativeRegisteredPlayersManagerComponent::RegisterPlayer(AController* Controller)
{
}

void UCreativeRegisteredPlayersManagerComponent::UnregisterAllPlayers()
{
}

void UCreativeRegisteredPlayersManagerComponent::UnregisterPlayer(AController* Controller)
{
}

void UCreativeRegisteredPlayersManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCreativeRegisteredPlayersManagerComponent, RegisteredPlayers);
}
