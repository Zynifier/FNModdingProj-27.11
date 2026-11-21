// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/CreativePlayerReplicationProxy.h"
#include "Net/UnrealNetwork.h"

void ACreativePlayerReplicationProxy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACreativePlayerReplicationProxy, ProxyManagerOwnerComponent);
}
