// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricProgressorManager.h"

int32 UFabricProgressorManager::GetGlobalPresetNumber() const
{
	return int32();
}

const FFabricProgressionPreset& UFabricProgressorManager::GetGlobalProgression() const
{
	static FFabricProgressionPreset Dummy;
	return Dummy;
}

bool UFabricProgressorManager::HasActiveGlobalProgression() const
{
	return false;
}

bool UFabricProgressorManager::IsProgressionGlobal(const FFabricProgressionPreset& InProgression)
{
	return false;
}

void UFabricProgressorManager::SetGlobalProgression(const FFabricProgressionPreset& InProgression, int32 InPresetNumber)
{
}
