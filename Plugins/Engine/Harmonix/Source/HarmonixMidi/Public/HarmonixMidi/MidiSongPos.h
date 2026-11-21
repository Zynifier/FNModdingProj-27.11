// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/BarMap.h"
#include "HarmonixMidi/BeatMap.h"
#include "MidiSongPos.generated.h"

/////////////////////////////////////////////////////////////////////////////
// Position within a song (midi info)
//

USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FMidiSongPos
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	float SecondsFromBarOne;

	// total seconds from bar 1 beat 1. (negative for count-in and/or pickup bars)

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	float SecondsIncludingCountIn;

	// total seconds from the beginning of the musical content (ie. includes all count-in and pickup bars)

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	int32 TimeSigNumerator;

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	int32 TimeSigDenominator;

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	float Tempo;

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	float BarsIncludingCountIn;

	// total bars from the beginning of the song.

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	float BeatsIncludingCountIn;

	// total beats from the beginning of the song.

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	EMusicalBeatType BeatType;

	UPROPERTY(BlueprintReadOnly, Category="MidiSongPosition")
	FMusicTimestamp Timestamp;

};

