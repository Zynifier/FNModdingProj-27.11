// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortSupervisedSettingsManager.h"

bool UFortSupervisedSettingsManager::GetAllowCreativeExperiences() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetCanDisplayMyUserName() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetCanSeeOtherPlayersNames() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetFilterMatureLanguage() const
{
	return false;
}

EPartyType UFortSupervisedSettingsManager::GetPartyJoinabilityLimit() const
{
	return EPartyType();
}

bool UFortSupervisedSettingsManager::GetPlayerSurveysAllowed() const
{
	return false;
}

FString UFortSupervisedSettingsManager::GetPlaytimeReportingFrequency() const
{
	return FString();
}

bool UFortSupervisedSettingsManager::GetPRMExperienceAllowed() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetPRMFunctionalAllowed() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetPRMMarketingAllowed() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetRequirePinToAddFriend() const
{
	return false;
}

bool UFortSupervisedSettingsManager::GetShowSeasonalLevelInFeedLimit() const
{
	return false;
}

ESocialCommsPermission UFortSupervisedSettingsManager::GetTextChatSettings() const
{
	return ESocialCommsPermission();
}

ESocialCommsPermission UFortSupervisedSettingsManager::GetTextChatSettingsLimit() const
{
	return ESocialCommsPermission();
}

FString UFortSupervisedSettingsManager::GetUserGeneratedContentViewable() const
{
	return FString();
}

EVoiceChatRecordingPreference UFortSupervisedSettingsManager::GetVoiceChatRecordingPreference() const
{
	return EVoiceChatRecordingPreference();
}

ESocialCommsPermission UFortSupervisedSettingsManager::GetVoiceChatSettings() const
{
	return ESocialCommsPermission();
}

ESocialCommsPermission UFortSupervisedSettingsManager::GetVoiceChatSettingsLimit() const
{
	return ESocialCommsPermission();
}
