// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MusicMapBase.h"
#include "SectionMap.generated.h"

/**
 * A section in a piece of music has a name, a starting point, and a length
 */
USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FSongSection : public FMusicMapTimespanBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SongSection")
	FString Name;

};

/**
 * A map of sections in a piece of music
 */
USTRUCT()
struct HARMONIXMIDI_API FSectionMap
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 TicksPerQuarterNote;

	UPROPERTY()
	TArray<FSongSection> Points;

};

