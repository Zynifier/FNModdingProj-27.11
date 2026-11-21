// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiveStreamHUDElement.h"

void ULiveStreamHUDElement::FireMirroredPIPAnalytics(bool bInStarted)
{
}

int32 ULiveStreamHUDElement::GetMirrorScreen()
{
	return int32();
}

bool ULiveStreamHUDElement::GetPIPAutoClose()
{
	return false;
}

TArray<float> ULiveStreamHUDElement::GetPIPCDNWeights()
{
	return TArray<float>();
}

bool ULiveStreamHUDElement::GetPIPDisableInstructions()
{
	return false;
}

bool ULiveStreamHUDElement::GetPIPForceEnabled()
{
	return false;
}

bool ULiveStreamHUDElement::GetPIPLive()
{
	return false;
}

float ULiveStreamHUDElement::GetPIPStartTIme()
{
	return float();
}

FString ULiveStreamHUDElement::GetPIPVideoUID()
{
	return FString();
}

float ULiveStreamHUDElement::GetPIPVolumeMultiplier()
{
	return float();
}

bool ULiveStreamHUDElement::IsUsingMirrorScreen()
{
	return false;
}

void ULiveStreamHUDElement::SetMirroredPIPAnalyicsMetadata(const FName& MediaName, const int64 CurrentProgressTimecode, const FName& MediaPlayerName)
{
}

void ULiveStreamHUDElement::SetMirrorPIPAudioDisable(bool bInDisable)
{
}

void ULiveStreamHUDElement::SetMirrorPIPAudioSubmix(bool bInDefault, bool bForce)
{
}

void ULiveStreamHUDElement::SetMirrorScreen(int32 ScreenIndex)
{
}

void ULiveStreamHUDElement::SetPIPAutoClose(bool bAutoClose)
{
}

void ULiveStreamHUDElement::SetPIPCDNWeights(const TArray<float> InWeights)
{
}

void ULiveStreamHUDElement::SetPIPDisableInstructions(bool bDisable)
{
}

void ULiveStreamHUDElement::SetPIPEOSGSBlackout(bool bInEnable)
{
}

void ULiveStreamHUDElement::SetPIPForceEnabled(bool bForced)
{
}

void ULiveStreamHUDElement::SetPIPLive(bool bInLive)
{
}

void ULiveStreamHUDElement::SetPIPStartTime(float InStartTime)
{
}

void ULiveStreamHUDElement::SetPIPVideoUID(const FString& InVideoUID)
{
}

void ULiveStreamHUDElement::SetPIPVolumeMultiplier(float InMultiplayer)
{
}
