// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemMcpTypesPublic.generated.h"

UENUM()
enum class EMutualFriendsPrivacyPolicy : uint8
{
	/** Anyone can see their mutual friends with you. */
	All = 0,
	/** Only friends can see their mutual friends with you. */
	Friends = 1,
	/** No one can see their mutual friends with you. */
	None = 2,
	/** Invalid enum type, may be used as a number of enumerations. */
	InvalidOrMax = 3,
};

