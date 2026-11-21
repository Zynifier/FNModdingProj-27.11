// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLinkEntryEnums.generated.h"

UENUM(BlueprintType)
enum class ELinkEntryQueryResult : uint8
{
	Success = 0,
	PartialSuccess = 1,
	FailedQuery = 2,
	FailedParse = 3,
	NotAllowedOnPlatform = 4,
	CabinModeBlocked = 5,
	UnableToFind = 6,
	NotVisible = 7,
	FailedStringSanitization = 8,
	FailedSubModePopulation = 9,
	FailedSubModeSurfacePopulation = 10,
	FailedSubModeParsing = 11,
	FilteredOut = 12,
	RatingUnrated = 13,
	RatingRestricted = 14,
};

