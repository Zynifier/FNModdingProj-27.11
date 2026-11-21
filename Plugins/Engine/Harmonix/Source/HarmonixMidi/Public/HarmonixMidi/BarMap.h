// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MusicMapBase.h"
#include "BarMap.generated.h"

/** A simple container for a musical time signature (numerator and denominator.) */
USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FTimeSignature
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int16 Numerator;

	UPROPERTY()
	int16 Denominator;

};

/** A time signature associated with a specific tick in a midi file. */
USTRUCT()
struct HARMONIXMIDI_API FTimeSignaturePoint : public FMusicMapTimespanBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BarIndex;

	// 0 based since it is internal!

	UPROPERTY()
	int32 BeatIndex;

	// 0 based since it is internal!

	UPROPERTY()
	FTimeSignature TimeSignature;

};

/** A map of time signatures changes in a song. */
USTRUCT()
struct HARMONIXMIDI_API FBarMap
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 StartBar;

	UPROPERTY()
	int32 TicksPerQuarterNote;

	UPROPERTY()
	TArray<FTimeSignaturePoint> Points;

};

USTRUCT(BlueprintType)
struct FMusicTimestamp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	int32 Bar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	float Beat;

};

