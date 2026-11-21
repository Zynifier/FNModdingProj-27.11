// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MusicMapBase.h"
#include "TempoMap.generated.h"

/**
 * A position in a song where the tempo is specified (the rate at which the music plays)
 */
USTRUCT()
struct HARMONIXMIDI_API FTempoInfoPoint : public FMusicMapTimespanBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Ms;

	// The time at which the tempo is changing

	UPROPERTY()
	int32 MidiTempo;

};

/**
 * A TempoMap that can change over time; the graph of the correspondence
 * between time and tick has multiple line segments.
 *
 * The tempo changes are specified by adding (tick, tempo) pairs, 
 */
USTRUCT()
struct HARMONIXMIDI_API FTempoMap
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 TicksPerQuarterNote;

	UPROPERTY()
	TArray<FTempoInfoPoint> Points;

};

