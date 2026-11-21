// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "MidiClockUpdateSubsystem.generated.h"

/**
 * Handles updating low-resolution play cursors associated with a MIDI clock.
 * Long story short, because FMidiClock instances do not have their lifecycle managed by the garbage collector,
 * we need a way to tick them on the game thread while avoiding races. This gives us a way to register clocks to be
 * ticked from within their constructors/destructor, and provides no user-facing API.
 */
UCLASS()
class HARMONIXMETASOUND_API UMidiClockUpdateSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

};

