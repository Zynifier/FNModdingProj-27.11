// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixMetasound/Components/MusicTempometerComponent.h"

float UMusicTempometerComponent::GetBarProgress() const
{
	return float();
}

float UMusicTempometerComponent::GetBarsIncludingCountIn() const
{
	return float();
}

float UMusicTempometerComponent::GetBeatProgress() const
{
	return float();
}

float UMusicTempometerComponent::GetBeatsIncludingCountIn() const
{
	return float();
}

const UMusicClockComponent* UMusicTempometerComponent::GetClock() const
{
	return nullptr;
}

const UMusicClockComponent* UMusicTempometerComponent::GetClockNoMutex() const
{
	return nullptr;
}

UMaterialParameterCollection* UMusicTempometerComponent::GetMaterialParameterCollection() const
{
	return nullptr;
}

float UMusicTempometerComponent::GetSecondsFromBarOne() const
{
	return float();
}

float UMusicTempometerComponent::GetSecondsIncludingCountIn() const
{
	return float();
}

const FMidiSongPos& UMusicTempometerComponent::GetSongPos() const
{
	static FMidiSongPos Dummy;
	return Dummy;
}

float UMusicTempometerComponent::GetTempo() const
{
	return float();
}

float UMusicTempometerComponent::GetTimeSignatureDenominator() const
{
	return float();
}

float UMusicTempometerComponent::GetTimeSignatureNumerator() const
{
	return float();
}

FMusicTimestamp UMusicTempometerComponent::GetTimestamp() const
{
	return FMusicTimestamp();
}

void UMusicTempometerComponent::SetClock(UMusicClockComponent* InClockComponent)
{
}

void UMusicTempometerComponent::SetClockFromActor(AActor* Actor)
{
}

void UMusicTempometerComponent::SetMaterialParameterCollection(UMaterialParameterCollection* InMaterialParameterCollection)
{
}
