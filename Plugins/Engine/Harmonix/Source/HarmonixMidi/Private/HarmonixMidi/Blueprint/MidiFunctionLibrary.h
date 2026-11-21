// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HarmonixMidi/Blueprint/MidiNote.h"
#include "MidiFunctionLibrary.generated.h"

/**
* Function library for FMidiNote and various midi note constants
*/
UCLASS()
class HARMONIXMIDI_API UMidiNoteFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Midi", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="byte to FMidiNote"))
	static FMidiNote ByteToMidiNote(uint8 InByte);

	UFUNCTION(BlueprintPure, Category="Midi")
	static FMidiNote GetMaxMidiNote();

	UFUNCTION(BlueprintPure, Category="Midi")
	static uint8 GetMaxNoteNumber();

	UFUNCTION(BlueprintPure, Category="Midi")
	static uint8 GetMaxNoteVelocity();

	UFUNCTION(BlueprintPure, Category="Midi")
	static int32 GetMaxNumNotes();

	UFUNCTION(BlueprintPure, Category="Midi")
	static FMidiNote GetMinMidiNote();

	UFUNCTION(BlueprintPure, Category="Midi")
	static uint8 GetMinNoteNumber();

	UFUNCTION(BlueprintPure, Category="Midi")
	static uint8 GetMinNoteVelocity();

	UFUNCTION(BlueprintPure, Category="Midi", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="int64 to FMidiNote"))
	static FMidiNote IntToMidiNote(int32 InInt);

	UFUNCTION(BlueprintPure, Category="Midi")
	static FMidiNote MakeLiteralMidiNote(FMidiNote Value);

	UFUNCTION(BlueprintPure, Category="Midi", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="FMidiNote To byte"))
	static uint8 MidiNoteToByte(const FMidiNote& InMidiNote);

	UFUNCTION(BlueprintPure, Category="Midi", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="FMidiNote To int64"))
	static int32 MidiNoteToInt(const FMidiNote& InMidiNote);

};

/**
* Function library for converting Ticks to Beats and Beats to Ticks and other midi constants
*/
UCLASS()
class HARMONIXMIDI_API UMusicalTickFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Midi")
	static float GetQuarterNotesPerTick();

	UFUNCTION(BlueprintPure, Category="Midi")
	static float GetTicksPerQuarterNote();

	UFUNCTION(BlueprintPure, Category="Midi")
	static int32 GetTicksPerQuarterNoteInt();

	UFUNCTION(BlueprintPure, Category="Midi")
	static float QuarterNoteToTick(float InQuarterNote);

	UFUNCTION(BlueprintPure, Category="Midi")
	static float TickToQuarterNote(float InTick);

};

