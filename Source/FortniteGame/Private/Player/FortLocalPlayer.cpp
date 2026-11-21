// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortLocalPlayer.h"

UFortClientSettingsRecord* UFortLocalPlayer::GetClientSettings() const
{
	return nullptr;
}

UFortContentControlsManager* UFortLocalPlayer::GetContentControlsManager() const
{
	return nullptr;
}

UFortContentControlsManager* UFortLocalPlayer::GetContentControlsManagerEvenIfUninitialized() const
{
	return nullptr;
}

UFortGameUserSettings* UFortLocalPlayer::GetLocalSettings() const
{
	return nullptr;
}

UFortSupervisedSettingsManager* UFortLocalPlayer::GetSupervisedSettingsManager() const
{
	return nullptr;
}
