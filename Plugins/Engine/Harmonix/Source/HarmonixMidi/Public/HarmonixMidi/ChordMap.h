// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MusicMapBase.h"
#include "ChordMap.generated.h"

/**
 * Specifies the tonality of a given section of music.
 */
USTRUCT()
struct HARMONIXMIDI_API FChordMapPoint : public FMusicMapTimespanBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

};

/**
 * A collection of chords.
 * 
 * Constructed when a standard midi file is imported and is seen to
 * contain a 'chord track' that conforms to the Harmonix chord markup 
 * convention.
 */
USTRUCT()
struct HARMONIXMIDI_API FChordProgressionMap
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 TicksPerQuarterNote;

	UPROPERTY()
	TArray<FChordMapPoint> Points;

};

