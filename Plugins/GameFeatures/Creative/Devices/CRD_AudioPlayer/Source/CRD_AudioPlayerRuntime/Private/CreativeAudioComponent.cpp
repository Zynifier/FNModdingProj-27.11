// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeAudioComponent.h"
#include "Net/UnrealNetwork.h"

void UCreativeAudioComponent::OnAllPlayersUnregistered()
{
}

void UCreativeAudioComponent::OnAudioLoadComplete(FSoftObjectPath Audio)
{
}

void UCreativeAudioComponent::OnEnabledStateChanged(bool bIsEnabled)
{
}

void UCreativeAudioComponent::OnMinigameEnded()
{
}

void UCreativeAudioComponent::OnMinigameStarted()
{
}

void UCreativeAudioComponent::OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState)
{
}

void UCreativeAudioComponent::OnPlayerAdded(FUniqueNetIdRepl NetId, bool bIsLocalPlayer)
{
}

void UCreativeAudioComponent::OnPlayerRegistered(const AFortPlayerState* PlayerState)
{
}

void UCreativeAudioComponent::OnPlayerRemoved(FUniqueNetIdRepl NetId, bool bIsLocalPlayer)
{
}

void UCreativeAudioComponent::OnPlayerUnregistered(const AFortPlayerState* PlayerState)
{
}

void UCreativeAudioComponent::OnProxyDataChanged(ACreativePlayerReplicationProxy* ProxyData)
{
}

void UCreativeAudioComponent::OnRep_RegisteredPlayerIds()
{
}

void UCreativeAudioComponent::OnRep_ServerInstigatorData()
{
}

void UCreativeAudioComponent::PlayAudio(AController* Player)
{
}

void UCreativeAudioComponent::ResetDevice()
{
}

void UCreativeAudioComponent::RetryClientPlayAudio(const FCreativeAudioPlayerData& InstigatorData)
{
}

void UCreativeAudioComponent::RetryUpdateAutoplayStatusOnMinigameAdd(AFortMinigame* Minigame)
{
}

void UCreativeAudioComponent::SetProperties(const TSoftObjectPtr<USoundBase>& Audio, const float Volume, const float PlaybackSpeed, const float NewFadeInDuration, const float NewFadeOutDuration, const bool bEnableVolumeAttenuation, const bool bEnableSpatialization, const float StereoSpread, const EAttenuationDistanceModel DistanceModel, const float AttenuationMinDistance, const float AttenuationFalloffDistance, const bool bNewSyncPlayerAudio, const bool bNewRestartAudioOnPlay, const int32 NewCanBeHeardBy, const int32 NewPlayLocation, const int32 NewAutoplayOptions)
{
}

void UCreativeAudioComponent::StopAudio(AController* Player)
{
}

void UCreativeAudioComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCreativeAudioComponent, ServerInstigatorData);
	DOREPLIFETIME(UCreativeAudioComponent, RegisteredPlayerIds);
}
