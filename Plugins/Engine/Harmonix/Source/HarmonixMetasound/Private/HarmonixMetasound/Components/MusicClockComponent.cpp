// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixMetasound/Components/MusicClockComponent.h"

float UMusicClockComponent::BarToMs(float Bar) const
{
	return float();
}

float UMusicClockComponent::BeatToMs(float Beat) const
{
	return float();
}

bool UMusicClockComponent::ConnectToMetasoundOnAudioComponent(UAudioComponent* InAudioComponent)
{
	return false;
}

void UMusicClockComponent::ConnectToWallClockForMidi(UMidiFile* InTempoMap)
{
}

void UMusicClockComponent::Continue()
{
}

UMusicClockComponent* UMusicClockComponent::CreateMetasoundDrivenMusicClock(UObject* WorldContextObject, UAudioComponent* InAudioComponent, FName MetasoundOuputPinName, bool Start)
{
	return nullptr;
}

UMusicClockComponent* UMusicClockComponent::CreateWallClockDrivenMusicClock(UObject* WorldContextObject, UMidiFile* WithTempoMap, bool Start)
{
	return nullptr;
}

float UMusicClockComponent::GetBarsIncludingCountIn(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetBeatInBarAtMs(float Ms) const
{
	return float();
}

float UMusicClockComponent::GetBeatsIncludingCountIn(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetCountInSeconds() const
{
	return float();
}

FMidiSongPos UMusicClockComponent::GetCurrentPlayerExperiencedSongPos()
{
	return FMidiSongPos();
}

int32 UMusicClockComponent::GetCurrentSectionIndex(ECalibratedMusicTimebase Timebase)
{
	return int32();
}

float UMusicClockComponent::GetCurrentSectionLengthMs(ECalibratedMusicTimebase Timebase)
{
	return float();
}

FString UMusicClockComponent::GetCurrentSectionName(ECalibratedMusicTimebase Timebase)
{
	return FString();
}

float UMusicClockComponent::GetCurrentSectionStartMs(ECalibratedMusicTimebase Timebase)
{
	return float();
}

FMidiSongPos UMusicClockComponent::GetCurrentSmoothedAudioRenderSongPos()
{
	return FMidiSongPos();
}

FMusicTimestamp UMusicClockComponent::GetCurrentTimestamp(ECalibratedMusicTimebase Timebase)
{
	return FMusicTimestamp();
}

FMidiSongPos UMusicClockComponent::GetCurrentVideoRenderSongPos()
{
	return FMidiSongPos();
}

float UMusicClockComponent::GetDeltaBar(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDeltaBeat(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDistanceFromCurrentBar(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDistanceFromCurrentBeat(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDistanceToClosestBar(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDistanceToClosestBeat(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDistanceToNextBar(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetDistanceToNextBeat(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetMsPerBarAtMs(float Ms) const
{
	return float();
}

float UMusicClockComponent::GetMsPerBeatAtMs(float Ms) const
{
	return float();
}

float UMusicClockComponent::GetNumBeatsInBarAtMs(float Ms) const
{
	return float();
}

float UMusicClockComponent::GetNumSections() const
{
	return float();
}

float UMusicClockComponent::GetSecondsFromBarOne(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetSecondsIncludingCountIn(ECalibratedMusicTimebase Timebase)
{
	return float();
}

float UMusicClockComponent::GetSectionEndMsAtMs(float Ms) const
{
	return float();
}

float UMusicClockComponent::GetSectionLengthMsAtMs(float Ms) const
{
	return float();
}

FString UMusicClockComponent::GetSectionNameAtMs(float Ms) const
{
	return FString();
}

float UMusicClockComponent::GetSectionStartMsAtMs(float Ms) const
{
	return float();
}

int32 UMusicClockComponent::GetSongLengthBars() const
{
	return int32();
}

float UMusicClockComponent::GetSongLengthBeats() const
{
	return float();
}

float UMusicClockComponent::GetSongLengthMs() const
{
	return float();
}

const FMidiSongPos& UMusicClockComponent::GetSongPos(ECalibratedMusicTimebase Timebase)
{
	static FMidiSongPos Dummy;
	return Dummy;
}

float UMusicClockComponent::GetSongRemainingTime(ECalibratedMusicTimebase Timebase)
{
	return float();
}

const TArray<FSongSection>& UMusicClockComponent::GetSongSections() const
{
	static TArray<FSongSection> Dummy;
	return Dummy;
}

EMusicClockState UMusicClockComponent::GetState() const
{
	return EMusicClockState();
}

float UMusicClockComponent::MeasureSpanProgress(const FMusicalTimeSpan& Span, ECalibratedMusicTimebase Timebase)
{
	return float();
}

void UMusicClockComponent::Pause()
{
}

void UMusicClockComponent::Start()
{
}

void UMusicClockComponent::Stop()
{
}

float UMusicClockComponent::TickToMs(float Tick) const
{
	return float();
}
