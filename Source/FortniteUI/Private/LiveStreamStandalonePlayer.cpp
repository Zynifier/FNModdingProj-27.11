// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiveStreamStandalonePlayer.h"

ULiveStreamStandalonePlayer::ULiveStreamStandalonePlayer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ULiveStreamStandalonePlayer::BlockPlayer(ELiveStreamStandaloneBlocked BlockedReason)
{
}

void ULiveStreamStandalonePlayer::CheckMediaStarted()
{
}

void ULiveStreamStandalonePlayer::DisableSharing(bool bInDisable)
{
}

void ULiveStreamStandalonePlayer::FireStandalonePIPAnalytics(bool bInStarted)
{
}

bool ULiveStreamStandalonePlayer::GetPIPIgnorePartySync()
{
	return false;
}

bool ULiveStreamStandalonePlayer::GetPIPStandaloneError()
{
	return false;
}

bool ULiveStreamStandalonePlayer::GetPlayerIsBlocked()
{
	return false;
}

void ULiveStreamStandalonePlayer::OnRetrieveVideoUrlFailure(const FString& Url)
{
}

void ULiveStreamStandalonePlayer::OnRetrieveVideoUrlSuccess(const FString& Url)
{
}

void ULiveStreamStandalonePlayer::Play()
{
}

void ULiveStreamStandalonePlayer::ResetPIPState()
{
}

void ULiveStreamStandalonePlayer::SetPIPCDNDistribution(const TArray<float>& Weights)
{
}

void ULiveStreamStandalonePlayer::SetPIPIgnorePartySync(bool bIgnore)
{
}

void ULiveStreamStandalonePlayer::SetPIPLive(bool bInLive)
{
}

void ULiveStreamStandalonePlayer::SetPIPMediaID(const FString& InVideoUID)
{
}

void ULiveStreamStandalonePlayer::SetPIPStartTime(float InStartTime)
{
}

void ULiveStreamStandalonePlayer::Stop()
{
}

void ULiveStreamStandalonePlayer::UnblockPlayer(ELiveStreamStandaloneBlocked BlockedReason)
{
}
