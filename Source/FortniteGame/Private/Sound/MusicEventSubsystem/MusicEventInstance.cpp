// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/MusicEventSubsystem/MusicEventInstance.h"

USoundBase* UMusicEventInstance::GetAsset() const
{
	return nullptr;
}

float UMusicEventInstance::GetAttenuationEval() const
{
	return float();
}

UAudioComponent* UMusicEventInstance::GetComponent() const
{
	return nullptr;
}

float UMusicEventInstance::GetDistSqToListener() const
{
	return float();
}

const FMusicEventData& UMusicEventInstance::GetEventData() const
{
	static FMusicEventData Dummy;
	return Dummy;
}

bool UMusicEventInstance::GetIsAudible() const
{
	return false;
}

bool UMusicEventInstance::GetIsInFront() const
{
	return false;
}

bool UMusicEventInstance::GetIsPlaying() const
{
	return false;
}

bool UMusicEventInstance::GetIsTickable() const
{
	return false;
}

bool UMusicEventInstance::GetIsWithinAttenuationThreshold() const
{
	return false;
}

float UMusicEventInstance::GetMaxDistance() const
{
	return float();
}

AActor* UMusicEventInstance::GetOwner() const
{
	return nullptr;
}

int32 UMusicEventInstance::GetPriority() const
{
	return int32();
}

float UMusicEventInstance::GetVolume() const
{
	return float();
}

void UMusicEventInstance::OnAudioComponentFinished()
{
}

void UMusicEventInstance::OnComponentOwnerEndPlay(AActor* Owner, EEndPlayReason::Type Reason)
{
}
