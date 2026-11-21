// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeAudioMixerReplicationProxy.h"
#include "Net/UnrealNetwork.h"

void ACreativeAudioMixerReplicationProxy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACreativeAudioMixerReplicationProxy, bIsActive);
}
