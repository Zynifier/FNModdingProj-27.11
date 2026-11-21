// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialToolkit.h"
#include "FortSocialToolkit.generated.h"

UENUM()
enum class EAcceptFriendInviteFailureReason : uint8
{
	InviterTooManyFriends = 0,
	SelfTooManyFriends = 1,
	MissingPin = 2,
	InvalidPin = 3,
	PinAttemptsExceeded = 4,
	UnknownError = 5,
};

UENUM()
enum class EGenericPinFailureReason : uint8
{
	InvalidPin = 0,
	PinAttemptsExceeded = 1,
	UnknownError = 2,
};

UENUM()
enum class ESendFriendInviteFailureReason : uint8
{
	NotFound = 0,
	AlreadyFriends = 1,
	InvitePending = 2,
	AddingSelfFail = 3,
	AddingBlockedFail = 4,
	AutoDeclined = 5,
	BlockedByTarget = 6,
	InviteeInboxFull = 7,
	SelfOutboxFull = 8,
	MissingPin = 9,
	InvalidPin = 10,
	PinAttemptsExceeded = 11,
	UnknownError = 12,
};

UENUM()
enum class EUnlockGameModeFailureReason : uint8
{
	InvalidPin = 0,
	PinAttemptsExceeded = 1,
	UnknownError = 2,
};

UCLASS(MinimalAPI)
class UFortSocialToolkit : public USocialToolkit
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	float SocialProfileSettingsSaveDelay;

	UPROPERTY(Config)
	float MutualFriendsSettingSaveDelay;

	UPROPERTY(Config)
	float RebootRallyPlatformFriendsQueryDelay;

	UPROPERTY(Config)
	float RebootRallyReQueryDelay;

	UPROPERTY(Config)
	float LfgSettingsSaveDelay;

	UPROPERTY(Config)
	bool bAutoRecreatePartiesDuringLogin;

	UPROPERTY(Config)
	bool bEnableDisplayNamesPrivacy;

};

