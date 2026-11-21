// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameActivityUtils.generated.h"

UENUM(BlueprintType)
enum class EFortActivityValidationResult : uint8
{
	NotFound = 0,
	InvalidKeyTooShort = 1,
	InvalidKeyCharacters = 2,
	IneligibleParty = 3,
	IslandPrivate = 4,
	Success = 5,
};

