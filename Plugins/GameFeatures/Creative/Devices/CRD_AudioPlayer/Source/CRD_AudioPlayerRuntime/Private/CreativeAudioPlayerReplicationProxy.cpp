// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeAudioPlayerReplicationProxy.h"
#include "Net/UnrealNetwork.h"

void ACreativeAudioPlayerReplicationProxy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACreativeAudioPlayerReplicationProxy, InstigatorData);
}
