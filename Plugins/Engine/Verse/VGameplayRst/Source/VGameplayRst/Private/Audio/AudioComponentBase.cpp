// Copyright Epic Games, Inc. All Rights Reserved.

#include "Audio/AudioComponentBase.h"
#include "Net/UnrealNetwork.h"

void UAudioComponentBase::OnRep_ActiveSoundInfo()
{
}

void UAudioComponentBase::OnRep_SoundAsset()
{
}

void UAudioComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAudioComponentBase, SoundAsset);
	DOREPLIFETIME(UAudioComponentBase, ActiveSoundInfo);
}
