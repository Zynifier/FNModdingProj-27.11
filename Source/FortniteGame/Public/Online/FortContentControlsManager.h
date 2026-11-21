// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortSupervisedSettingsManager.h"
#include "FortContentControlsManager.generated.h"

enum class ESocialCommsPermission : uint8;

UCLASS(MinimalAPI)
class UFortContentControlsManager : public UFortSupervisedSettingsManager
{
	GENERATED_BODY()

public:
	UFUNCTION()
	bool GetCanAcceptFriendRequest() const;

	UFUNCTION()
	bool GetCanSeeMatureLanguage() const;

	UFUNCTION()
	bool GetCanUseTextChat() const;

	UFUNCTION()
	void SetCanAcceptFriendRequest(bool bInValue);

	UFUNCTION()
	void SetCanDisplayMyUserName(bool bInValue);

	UFUNCTION()
	void SetCanSeeMatureLanguage(bool bInValue);

	UFUNCTION()
	void SetCanSeeOtherPlayersNames(bool bInValue);

	UFUNCTION()
	void SetCanUseTextChat(bool bInValue);

	UFUNCTION()
	void SetPlaytimeReportingFrequency(const FString& InValue);

	UFUNCTION()
	void SetRequirePinToAddFriend(bool bInValue);

	UFUNCTION()
	void SetUserGeneratedContentViewable(const FString& InValue);

	UFUNCTION()
	void SetVoiceChatSettings(ESocialCommsPermission InValue);

};

