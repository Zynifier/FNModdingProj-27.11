// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Harmonix/MusicalTimebase.h"
#include "HarmonixMidi/BarMap.h"
#include "HarmonixMidi/MidiSongPos.h"
#include "HarmonixMidi/MusicTimeSpan.h"
#include "HarmonixMidi/SectionMap.h"
#include "MusicClockComponent.generated.h"

class UAudioComponent;
class UMidiFile;
class UMusicClockComponent;
class UObject;
enum class ECalibratedMusicTimebase : uint8;
enum class EMusicClockState : uint8;

UENUM(BlueprintType)
enum class EMusicClockDriveMethod : uint8
{
	WallClock = 0,
	MetaSound = 1,
};

UENUM(BlueprintType)
enum class EMusicClockState : uint8
{
	Stopped = 0,
	Paused = 1,
	Running = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBarEvent, int32, BarNumber);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBeatEvent, int32, BeatNumber, int32, BeatInBar);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMusicClockConnected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMusicClockDisconnected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayStateEvent, EMusicClockState, State);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSectionEvent, FString, SectionName, float, SectionStartMs, float, SectionLengthMs);

UCLASS(PrioritizeCategories=("MusicClock"), ClassGroup=("MetaSoundMusic"), meta=(BlueprintSpawnableComponent, DisplayName="Music Clock", ScriptName="MusicClockComponent"))
class HARMONIXMETASOUND_API UMusicClockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Bar")
	float BarToMs(float Bar) const;

	UFUNCTION(BlueprintPure, Category="Beat")
	float BeatToMs(float Beat) const;

	UFUNCTION(BlueprintCallable, Category="MusicClock")
	bool ConnectToMetasoundOnAudioComponent(UAudioComponent* InAudioComponent);

	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void ConnectToWallClockForMidi(UMidiFile* InTempoMap);

	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void Continue();

	UFUNCTION(BlueprintCallable, Category="Audio|MusicClock", meta=(DefaultToSelf="WorldContextObject", WorldContext="WorldContextObject"))
	static UMusicClockComponent* CreateMetasoundDrivenMusicClock(UObject* WorldContextObject, UAudioComponent* InAudioComponent, FName MetasoundOuputPinName = FName(TEXT("Midi Clock")), bool Start = true);

	UFUNCTION(BlueprintCallable, Category="Audio|MusicClock", meta=(DefaultToSelf="WorldContextObject", WorldContext="WorldContextObject"))
	static UMusicClockComponent* CreateWallClockDrivenMusicClock(UObject* WorldContextObject, UMidiFile* WithTempoMap, bool Start = true);

	// Returns the fractional total bars from the beginning of the authored music content.
// NOTE: INCLUDES time for count-in and pickup bars.
// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetBarsIncludingCountIn(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="Beat")
	float GetBeatInBarAtMs(float Ms) const;

	// Returns the fractional total beats from the beginning of the authored music content.
// NOTE: INCLUDES time for count-in and pickup bars.
// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetBeatsIncludingCountIn(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="Count In")
	float GetCountInSeconds() const;

	UFUNCTION(BlueprintPure, Category="MusicClock")
	FMidiSongPos GetCurrentPlayerExperiencedSongPos();

	/** Returns the index of the current section for the provided time base. [0, Num-1] */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	int32 GetCurrentSectionIndex(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Returns the length of the current section in milliseconds */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetCurrentSectionLengthMs(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Returns the name of the section that we're currently in (intro, chorus, outro) */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	FString GetCurrentSectionName(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Returns the start time of the current section in milliseconds */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetCurrentSectionStartMs(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="MusicClock")
	FMidiSongPos GetCurrentSmoothedAudioRenderSongPos();

	// Returns the "classic" musical timestamp in the form Bar (int) & Beat (float). In this form...
//    - Bar 1, Beat 1.0 is the "beginning of the song" AFTER count-in/pickups
//    - Bar 0, Beat 1.0 would be one bar BEFORE the "beginning of the song"... eg. a bar of count-in or pickup.
//    - While Bar can be positive or negative, Beat is always >= 1.0 and is read as "beat in the bar". Again... '1' based!
// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	FMusicTimestamp GetCurrentTimestamp(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="MusicClock")
	FMidiSongPos GetCurrentVideoRenderSongPos();

	// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDeltaBar(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDeltaBeat(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Gets a value expressed in bars between 0-1 that indicates how much progress we made towards the current bar to the next one. */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDistanceFromCurrentBar(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Gets a value expressed in beats between 0-1 that indicates how much progress we made towards the current beat to the next one */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDistanceFromCurrentBeat(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Gets value expressed in bars between 0-1 that indicates how close we are to the closest bar (current bar or next bar). */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDistanceToClosestBar(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Gets a value expressed in beats between 0-1 that indicates how close we are to the closest beat (current beat or next beat). */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDistanceToClosestBeat(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Gets a value expressed in bars between 0-1 that indicates how close we are to the next bar. */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDistanceToNextBar(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Gets a value expressed in beats between 0-1 that indicates how close we are to the next beat. */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetDistanceToNextBeat(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="Bar")
	float GetMsPerBarAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Beat")
	float GetMsPerBeatAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Beat")
	float GetNumBeatsInBarAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Section")
	float GetNumSections() const;

	// Time from Bar 1 Beat 1. The classic "start of the song".
// NOTE: DOES NOT INCLUDE time for count-in and pickup bars.
// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetSecondsFromBarOne(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	// Time from the beginning of the authored music content.
// NOTE: INCLUDES time for count-in and pickup bars.
// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetSecondsIncludingCountIn(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="Section")
	float GetSectionEndMsAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Section")
	float GetSectionLengthMsAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Section")
	FString GetSectionNameAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Section")
	float GetSectionStartMsAtMs(float Ms) const;

	UFUNCTION(BlueprintPure, Category="Song Data")
	int32 GetSongLengthBars() const;

	UFUNCTION(BlueprintPure, Category="Song Data")
	float GetSongLengthBeats() const;

	UFUNCTION(BlueprintPure, Category="Song Data")
	float GetSongLengthMs() const;

	// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	const FMidiSongPos& GetSongPos(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	/** Returns the remaining time until the end of the MIDI in milliseconds based on the timestamp corresponding to the passed Timebase */// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float GetSongRemainingTime(ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintPure, Category="MusicClock")
	const TArray<FSongSection>& GetSongSections() const;

	UFUNCTION(BlueprintPure, Category="MusicClock")
	EMusicClockState GetState() const;

	// Note: Not const as it might cause the clock to update from its source.

	UFUNCTION(BlueprintPure, Category="MusicClock")
	float MeasureSpanProgress(const FMusicalTimeSpan& Span, ECalibratedMusicTimebase Timebase = ECalibratedMusicTimebase::VideoRenderTime);

	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void Pause();

	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void Start();

	UFUNCTION(BlueprintCallable, Category="MusicClock")
	void Stop();

	UFUNCTION(BlueprintPure, Category="Tick")
	float TickToMs(float Tick) const;

	UPROPERTY(EditDefaultsOnly, Category="MusicClock")
	EMusicClockDriveMethod DriveMethod;

	UPROPERTY(EditDefaultsOnly, Category="MusicClock", meta=(EditCondition="DriveMethod == EMusicClockDriveMethod::MetaSound"))
	FName MetasoundOutputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="MusicClock", meta=(EditCondition="DriveMethod == EMusicClockDriveMethod::MetaSound", EditInline="true"))
	TObjectPtr<UAudioComponent> MetasoundsAudioComponent;

	UPROPERTY(EditDefaultsOnly, Category="MusicClock", meta=(EditCondition="DriveMethod == EMusicClockDriveMethod::WallClock"))
	TObjectPtr<UMidiFile> TempoMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MusicClock|Defaults")
	float Tempo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MusicClock|Defaults")
	int32 TimeSignatureNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MusicClock|Defaults")
	int32 TimeSignatureDenom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="MusicClock")
	float CurrentBeatDurationSec;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="MusicClock")
	float CurrentBarDurationSec;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="MusicClock")
	float CurrentClockAdvanceRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MusicClock")
	bool RunPastMusicEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MusicClock")
	ECalibratedMusicTimebase TimebaseForBarAndBeatEvents;

	UPROPERTY(BlueprintAssignable, Category="MusicClock")
	FPlayStateEvent PlayStateEvent;

	UPROPERTY(BlueprintAssignable, Category="MusicClock")
	FBeatEvent BeatEvent;

	UPROPERTY(BlueprintAssignable, Category="MusicClock")
	FBarEvent BarEvent;

	UPROPERTY(BlueprintAssignable, Category="MusicClock")
	FSectionEvent SectionEvent;

	UPROPERTY(BlueprintAssignable, Category="MusicClock")
	FMusicClockConnected MusicClockConnectedEvent;

	UPROPERTY(BlueprintAssignable, Category="MusicClock")
	FMusicClockDisconnected MusicClockDisconnectedEvent;

	UPROPERTY(BlueprintGetter=GetCurrentSmoothedAudioRenderSongPos, Category="MusicClock")
	FMidiSongPos CurrentSmoothedAudioRenderSongPos;

	UPROPERTY(BlueprintGetter=GetCurrentVideoRenderSongPos, Category="MusicClock")
	FMidiSongPos CurrentVideoRenderSongPos;

	UPROPERTY(BlueprintGetter=GetCurrentPlayerExperiencedSongPos, Category="MusicClock")
	FMidiSongPos CurrentPlayerExperiencedSongPos;

};

