// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MidiMsg.h"
#include "MidiEvent.generated.h"

/**
 * An FMidiEvent is a container for a tick and a midi message. 
 */
USTRUCT()
struct HARMONIXMIDI_API FMidiEvent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 Tick;

	UPROPERTY()
	FMidiMsg Message;

};

