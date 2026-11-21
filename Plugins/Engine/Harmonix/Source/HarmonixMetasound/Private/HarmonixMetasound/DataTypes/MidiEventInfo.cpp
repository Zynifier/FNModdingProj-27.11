// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixMetasound/DataTypes/MidiEventInfo.h"

int32 UMidiEventInfoBlueprintLibrary::GetChannel(const FMidiEventInfo& Event)
{
	return int32();
}

FMidiEventInfo UMidiEventInfoBlueprintLibrary::GetMidiEventInfo(const FMetaSoundOutput& Output, bool& Success)
{
	return FMidiEventInfo();
}

int32 UMidiEventInfoBlueprintLibrary::GetNoteNumber(const FMidiEventInfo& Event)
{
	return int32();
}

int32 UMidiEventInfoBlueprintLibrary::GetVelocity(const FMidiEventInfo& Event)
{
	return int32();
}

bool UMidiEventInfoBlueprintLibrary::IsMidiEventInfo(const FMetaSoundOutput& Output)
{
	return false;
}

bool UMidiEventInfoBlueprintLibrary::IsNote(const FMidiEventInfo& Event)
{
	return false;
}

bool UMidiEventInfoBlueprintLibrary::IsNoteOff(const FMidiEventInfo& Event)
{
	return false;
}

bool UMidiEventInfoBlueprintLibrary::IsNoteOn(const FMidiEventInfo& Event)
{
	return false;
}
