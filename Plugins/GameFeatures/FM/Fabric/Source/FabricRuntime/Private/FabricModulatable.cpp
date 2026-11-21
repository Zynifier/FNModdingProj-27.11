// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricModulatable.h"

AActor* UFabricModulatable::GetModulatedActor() const
{
	return nullptr;
}

bool UFabricModulatable::GetModulatedBool(const FString& Param, const FMidiSongPos& SongPos, bool& OutBool) const
{
	return false;
}

bool UFabricModulatable::GetModulatedEnum(const FString& Param, const FMidiSongPos& SongPos, uint8& OutEnum) const
{
	return false;
}

bool UFabricModulatable::GetModulatedFloat(const FString& Param, const FMidiSongPos& SongPos, float& OutFloat) const
{
	return false;
}

bool UFabricModulatable::GetModulatedInt(const FString& Param, const FMidiSongPos& SongPos, int32& OutInt) const
{
	return false;
}

bool UFabricModulatable::GetModulatedString(const FString& Param, const FMidiSongPos& SongPos, FString& OutString) const
{
	return false;
}

TScriptInterface<IFabricModulator> UFabricModulatable::GetModulator(const FString& Param) const
{
	return TScriptInterface<IFabricModulator>();
}

bool UFabricModulatable::IsParamModulated(const FString& Param) const
{
	return false;
}

void UFabricModulatable::OnAnyOptionUpdated()
{
}

void UFabricModulatable::OnModulatedPropertyChanged(const FString& Value, UObject* ModulatorObject)
{
}

void UFabricModulatable::OnModulatorFloatProviderConnectionChanged(bool bConnected, UObject* ModulatorObject)
{
}

void UFabricModulatable::OnOptionsLoaded()
{
}
