// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MusicMapBase.generated.h"

/**
 * FMusicMapPointBase represents a span in a midi file defined by a start tick and a length.
 * This is a base class for many types of map points we recognize in midi files (e.g. chord,
 * section, tempo, pulse, etc.)
 */
USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FMusicMapTimespanBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Timespan")
	int32 StartTick;

	UPROPERTY(BlueprintReadOnly, Category="Timespan")
	int32 LengthTicks;

};

