// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSubGameTypes.generated.h"

UENUM(BlueprintType)
enum class ESubGame : uint8
{
	Campaign = 0,
	Athena = 1,
	Invalid = 2,
	Count = 2,
	/**
	 * @james.tan https://jira.it.epicgames.net/browse/FORT-275503 
	 * Added after Count so that the size of ABuildingContainer would not change. Creative is not treated as a "true" subgame, but is 
	 * used to identify Creative initially so that additional content can be installed if required.
	 */
	Creative = 3,
};

UENUM(BlueprintType)
enum class ESubGameAccessStatus : uint8
{
	Disabled = 0,
	LimitedAccess = 1,
	OpenAccess = 2,
};

UENUM(BlueprintType)
enum class ESubGameMatchmakingStatus : uint8
{
	Disabled = 0,
	Enabled = 1,
};

