// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Components/FortAIComponent_Voice.h"
#include "Net/UnrealNetwork.h"

UFortTaggedSoundBank* UFortAIComponent_Voice::GetVoiceSoundBank() const
{
	return nullptr;
}

void UFortAIComponent_Voice::SetVoiceSoundBank(UFortTaggedSoundBank* InSoundBank)
{
}

void UFortAIComponent_Voice::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAIComponent_Voice, VoiceSoundBank);
}
