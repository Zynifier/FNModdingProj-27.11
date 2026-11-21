// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortContentControlsManager.h"

bool UFortContentControlsManager::GetCanAcceptFriendRequest() const
{
	return false;
}

bool UFortContentControlsManager::GetCanSeeMatureLanguage() const
{
	return false;
}

bool UFortContentControlsManager::GetCanUseTextChat() const
{
	return false;
}

void UFortContentControlsManager::SetCanAcceptFriendRequest(bool bInValue)
{
}

void UFortContentControlsManager::SetCanDisplayMyUserName(bool bInValue)
{
}

void UFortContentControlsManager::SetCanSeeMatureLanguage(bool bInValue)
{
}

void UFortContentControlsManager::SetCanSeeOtherPlayersNames(bool bInValue)
{
}

void UFortContentControlsManager::SetCanUseTextChat(bool bInValue)
{
}

void UFortContentControlsManager::SetPlaytimeReportingFrequency(const FString& InValue)
{
}

void UFortContentControlsManager::SetRequirePinToAddFriend(bool bInValue)
{
}

void UFortContentControlsManager::SetUserGeneratedContentViewable(const FString& InValue)
{
}

void UFortContentControlsManager::SetVoiceChatSettings(ESocialCommsPermission InValue)
{
}
