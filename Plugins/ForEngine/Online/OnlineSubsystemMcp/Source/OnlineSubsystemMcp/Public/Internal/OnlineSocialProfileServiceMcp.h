// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSocialProfileServiceMcp.generated.h"

UENUM()
enum class ESocialProfilePrivacySettingBadges : uint8
{
	FriendsOnly = 0,
	Private = 1,
};

UENUM()
enum class ESocialProfilePrivacySettingLevel : uint8
{
	Public = 0,
	FriendsOnly = 1,
	Private = 2,
};

