// Copyright Epic Games, Inc. All Rights Reserved.

#include "UACNetworkComponent.h"
#include "Net/UnrealNetwork.h"

void UUACNetworkComponent::SendClientHello_Implementation(uint32 SessionKey)
{
}

void UUACNetworkComponent::SendPacketToClient_Implementation(uint8 EnhPacketType, const TArray<uint8>& Data)
{
}

void UUACNetworkComponent::SendPacketToServer_Implementation(uint8 EnhPacketType, const TArray<uint8>& Data)
{
}
bool UUACNetworkComponent::SendPacketToServer_Validate(uint8 EnhPacketType, const TArray<uint8>& Data)
{
	return true;
}

void UUACNetworkComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UUACNetworkComponent, PlayerID);
}
