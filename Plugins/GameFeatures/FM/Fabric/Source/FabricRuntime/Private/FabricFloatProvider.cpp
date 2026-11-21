// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricFloatProvider.h"

UFabricMetaSoundModulatorPatchWrapper* UFabricFloatProviderBase::GetAssociatedPatchWrapper() const
{
	return nullptr;
}

float UFabricFloatProviderBase::GetCurrentFloat() const
{
	return float();
}

FMidiSongPos UFabricFloatProviderBase::GetCurrentSongPos() const
{
	return FMidiSongPos();
}

FMidiSongPos UFabricFloatProviderBase::GetCurrentSongPosWithOffset(float OffsetSeconds) const
{
	return FMidiSongPos();
}

float UFabricFloatProviderBase::GetFloatAtSongPos(const FMidiSongPos& SongPos) const
{
	return float();
}

EFabricFloatProviderType UFabricFloatProviderBase::GetFloatProviderType() const
{
	return EFabricFloatProviderType();
}

void UFabricFloatProviderBase::SetAssociatedPatchWrapper(UFabricMetaSoundModulatorPatchWrapper* PatchWrapper)
{
}

void UFabricFloatProviderBase::SetMusicClock(UMusicClockComponent* NewMusicClock)
{
}

void UFabricFloatProviderBase::SetProviderEnabled(bool bInIsEnabled)
{
}
