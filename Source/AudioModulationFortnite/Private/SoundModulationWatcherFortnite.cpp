// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoundModulationWatcherFortnite.h"

bool USoundModulationWatcher::ClearModulator()
{
	return false;
}

const USoundModulatorBase* USoundModulationWatcher::GetModulator() const
{
	return nullptr;
}

float USoundModulationWatcher::GetValue() const
{
	return float();
}

bool USoundModulationWatcher::SetModulator(const USoundModulatorBase* InModulator)
{
	return false;
}
