// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPinModalTypes.generated.h"

UENUM(BlueprintType)
enum class EPinModalType : uint8
{
	AcceptFriendRequest = 0,
	SendFriendRequest = 1,
	UnlockWeaponsRequest = 2,
	UnlockGameModeRequest = 3,
	OpenParentalControlsRequest = 4,
	MAX = 5,
};

UENUM(BlueprintType)
enum class EPinModalValidityState : uint8
{
	None = 0,
	Requesting = 1,
	Success = 2,
	Invalid = 3,
};

