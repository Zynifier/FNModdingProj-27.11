// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricUserOptionSaveComponent.h"

FString UFabricUserOptionSaveComponent::GetOverrideForParam(const FString& Param) const
{
	return FString();
}

bool UFabricUserOptionSaveComponent::HasOverrideForParam(const FString& Param) const
{
	return false;
}

bool UFabricUserOptionSaveComponent::IsApplyingOverrides()
{
	return false;
}

void UFabricUserOptionSaveComponent::OnAnyOptionUpdated()
{
}

void UFabricUserOptionSaveComponent::SetMusicClock(UMusicClockComponent* MusicClockComponent)
{
}

void UFabricUserOptionSaveComponent::SetPreset(int32 PresetIndex)
{
}

void UFabricUserOptionSaveComponent::SetSaveSlot(int32 SaveSlotIndex)
{
}
