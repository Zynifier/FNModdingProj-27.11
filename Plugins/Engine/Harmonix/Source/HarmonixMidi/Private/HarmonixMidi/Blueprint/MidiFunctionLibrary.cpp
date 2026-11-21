// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixMidi/Blueprint/MidiFunctionLibrary.h"

FMidiNote UMidiNoteFunctionLibrary::ByteToMidiNote(uint8 InByte)
{
	return FMidiNote();
}

FMidiNote UMidiNoteFunctionLibrary::GetMaxMidiNote()
{
	return FMidiNote();
}

uint8 UMidiNoteFunctionLibrary::GetMaxNoteNumber()
{
	return uint8();
}

uint8 UMidiNoteFunctionLibrary::GetMaxNoteVelocity()
{
	return uint8();
}

int32 UMidiNoteFunctionLibrary::GetMaxNumNotes()
{
	return int32();
}

FMidiNote UMidiNoteFunctionLibrary::GetMinMidiNote()
{
	return FMidiNote();
}

uint8 UMidiNoteFunctionLibrary::GetMinNoteNumber()
{
	return uint8();
}

uint8 UMidiNoteFunctionLibrary::GetMinNoteVelocity()
{
	return uint8();
}

FMidiNote UMidiNoteFunctionLibrary::IntToMidiNote(int32 InInt)
{
	return FMidiNote();
}

FMidiNote UMidiNoteFunctionLibrary::MakeLiteralMidiNote(FMidiNote Value)
{
	return FMidiNote();
}

uint8 UMidiNoteFunctionLibrary::MidiNoteToByte(const FMidiNote& InMidiNote)
{
	return uint8();
}

int32 UMidiNoteFunctionLibrary::MidiNoteToInt(const FMidiNote& InMidiNote)
{
	return int32();
}

float UMusicalTickFunctionLibrary::GetQuarterNotesPerTick()
{
	return float();
}

float UMusicalTickFunctionLibrary::GetTicksPerQuarterNote()
{
	return float();
}

int32 UMusicalTickFunctionLibrary::GetTicksPerQuarterNoteInt()
{
	return int32();
}

float UMusicalTickFunctionLibrary::QuarterNoteToTick(float InQuarterNote)
{
	return float();
}

float UMusicalTickFunctionLibrary::TickToQuarterNote(float InTick)
{
	return float();
}
