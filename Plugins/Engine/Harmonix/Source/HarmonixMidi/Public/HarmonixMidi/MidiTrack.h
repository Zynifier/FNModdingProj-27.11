// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MidiEvent.h"
#include "MidiTrack.generated.h"

/**
	* An FMidiTrack is a collection of FMidiEvents in chronological order.  
	* 
	* It can be created dynamically or be the end result of importing a 
	* standard midi file.
	*/
USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FMidiTrack
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FMidiEvent> Events;

	// All the midi events

	UPROPERTY()
	bool Sorted;

	// Are the events sorted.

	UPROPERTY()
	int32 PrimaryMidiChannel;

	// The midi channel of the first event on the track!

	UPROPERTY()
	TArray<FString> Strings;

};

