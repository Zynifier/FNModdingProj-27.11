// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/Music/FortMusicManager.h"

UFortMusicVoice* AFortMusicManager::ChangePrimaryMusic(UFortMusicAsset* NewMusicAsset, bool bPlayStinger)
{
	return nullptr;
}

float AFortMusicManager::GetEventHeatPercent(EFortCombatEvents::Type CombatEvent)
{
	return float();
}

float AFortMusicManager::GetEventHeatPercentTotal(EFortCombatEvents::Type CombatEvent)
{
	return float();
}

const UFortMusicManagerBank* AFortMusicManager::GetMusicBank() const
{
	return nullptr;
}

float AFortMusicManager::GetPrimaryMusicVolume() const
{
	return float();
}

void AFortMusicManager::OnVoiceFinished(UFortMusicVoice* Voice)
{
}

UFortMusicVoice* AFortMusicManager::PlayMusicVoice(UFortMusicAsset* Asset)
{
	return nullptr;
}

void AFortMusicManager::PlayStinger_Implementation(UFortMusicAsset* NewMusicAsset)
{
}

void AFortMusicManager::SetMusicBank(UFortMusicManagerBank* Bank)
{
}

void AFortMusicManager::SetPrimaryMusicVolume(float InVolumeMultiplier)
{
}

void AFortMusicManager::StopMusicVoice(UFortMusicVoice* Voice)
{
}

void AFortMusicManager::StopPrimaryMusic(bool bPlayOutro)
{
}
