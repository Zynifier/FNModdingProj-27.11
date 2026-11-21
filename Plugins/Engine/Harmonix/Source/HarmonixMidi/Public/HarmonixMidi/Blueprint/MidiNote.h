// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MidiNote.generated.h"

/**
* Helper struct for getting and assigning MidiNote values
* Uses custom detail customization and custom pins for convenience in Editor
* 
* has a one property
* uint8 NoteNumber
* ranging from Midi::kMinNote to Midi::kMaxNote [0 - 127]
*/
USTRUCT(BlueprintType)
struct HARMONIXMIDI_API FMidiNote
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Midi")
	uint8 NoteNumber;

};

