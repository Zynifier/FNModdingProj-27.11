// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMCoreMusicManagerComponent.h"
#include "Net/UnrealNetwork.h"

void UFMCoreMusicManagerComponent::GetCurrentAudioState(EMusicKey& OutKey, EMusicKeyMode& OutKeyMode, int32& OutTempo) const
{
}

EMusicKey UFMCoreMusicManagerComponent::GetCurrentKey() const
{
	return EMusicKey();
}

EMusicKeyMode UFMCoreMusicManagerComponent::GetCurrentKeyMode() const
{
	return EMusicKeyMode();
}

int32 UFMCoreMusicManagerComponent::GetCurrentTempo() const
{
	return int32();
}

FFMCoreTimeSignature UFMCoreMusicManagerComponent::GetCurrentTimeSignature() const
{
	return FFMCoreTimeSignature();
}

void UFMCoreMusicManagerComponent::OnRep_ServerKeyChanged()
{
}

void UFMCoreMusicManagerComponent::OnRep_ServerModeChanged()
{
}

void UFMCoreMusicManagerComponent::OnRep_ServerTempoChanged()
{
}

void UFMCoreMusicManagerComponent::OnRep_ServerTimeSignatureChanged()
{
}

void UFMCoreMusicManagerComponent::TriggerKeyChange(EMusicKey InKey)
{
}

void UFMCoreMusicManagerComponent::TriggerModeChange(EMusicKeyMode InMode)
{
}

void UFMCoreMusicManagerComponent::TriggerTempoChange(int32 Bpm)
{
}

void UFMCoreMusicManagerComponent::TriggerTimeSignatureChange(int32 Numerator, int32 Denominator)
{
}

void UFMCoreMusicManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMCoreMusicManagerComponent, ServerKey);
	DOREPLIFETIME(UFMCoreMusicManagerComponent, ServerMode);
	DOREPLIFETIME(UFMCoreMusicManagerComponent, ServerTempo);
	DOREPLIFETIME(UFMCoreMusicManagerComponent, ServerTimeSignature);
}
