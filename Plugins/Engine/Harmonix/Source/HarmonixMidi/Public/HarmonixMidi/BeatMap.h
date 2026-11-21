// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MusicMapBase.h"
#include "BeatMap.generated.h"

UENUM(BlueprintType)
enum class EMusicalBeatType : uint8
{
	Downbeat = 0,
	Strong = 1,
	Normal = 2,
};

/**
 * A point in the music representing a "beat".
 * 
 * Type may be 'Downbeat', 'Strong', or 'Normal' beat. 
 * 
 * This is very useful for odd time signatures like 5/8 where the music's
 * beat might be on the 1st and 3rd eighth notes or the 1st and 4th eighth notes
 */
USTRUCT()
struct HARMONIXMIDI_API FBeatMapPoint : public FMusicMapTimespanBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PulseBar;

	UPROPERTY()
	EMusicalBeatType Type;

};

/**
 * Pulse Bars are groupings of beats where the first beat in the group has been marked up as a
 * 'Downbeat' type.
 */
USTRUCT()
struct HARMONIXMIDI_API FPulseBar
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 StartTick;

	UPROPERTY()
	int32 LengthTicks;

	UPROPERTY()
	int32 FirstIncludedBeatIndex;

	UPROPERTY()
	int32 LastIncludedBeatIndex;

};

/**
 * A map of 'beats' in a piece of music.
 */
USTRUCT()
struct HARMONIXMIDI_API FBeatMap
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 TicksPerQuarterNote;

	UPROPERTY()
	TArray<FBeatMapPoint> Points;

	UPROPERTY()
	TArray<FPulseBar> Bars;

};

