// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativeProxyManagerComponent.h"

void UCreativeProxyManagerComponent::DestroyAllProxies()
{
}

void UCreativeProxyManagerComponent::DestroyProxyForPlayer(APlayerController* PlayerController)
{
}

void UCreativeProxyManagerComponent::DestroyProxyForUniqueNetId(const FUniqueNetIdRepl& Id)
{
}

ACreativePlayerReplicationProxy* UCreativeProxyManagerComponent::GetProxyForPlayer(APlayerController* PlayerController)
{
	return nullptr;
}

ACreativePlayerReplicationProxy* UCreativeProxyManagerComponent::GetProxyForUniqueNetId(const FUniqueNetIdRepl& Id)
{
	return nullptr;
}
