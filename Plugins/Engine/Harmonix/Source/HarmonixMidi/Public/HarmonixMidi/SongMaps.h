// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/BarMap.h"
#include "HarmonixMidi/BeatMap.h"
#include "HarmonixMidi/ChordMap.h"
#include "HarmonixMidi/SectionMap.h"
#include "HarmonixMidi/TempoMap.h"
#include "SongMaps.generated.h"

USTRUCT()
struct FSongLengthData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 LengthTicks;

	UPROPERTY()
	int32 LengthBars;

	UPROPERTY()
	int32 LastTick;

};

/**
 * FSongMaps encapsulates a number of other musical/midi map types
 * that are very useful for musical gameplay and interactivity. 
 * 
 * With this class and the current playback position of a piece of music you can
 * do things like determine the current Bar | Beat | Tick, song section, tempo,
 * chord, etc.
 */
USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FSongMaps
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 TicksPerQuarterNote;

	UPROPERTY()
	FTempoMap TempoMap;

	UPROPERTY()
	FBarMap BarMap;

	UPROPERTY()
	FBeatMap BeatMap;

	UPROPERTY()
	FSectionMap SectionMap;

	UPROPERTY()
	FChordProgressionMap ChordMap;

	UPROPERTY()
	TArray<FString> TrackNames;

private:
	UPROPERTY()
	FSongLengthData LengthData;

};

