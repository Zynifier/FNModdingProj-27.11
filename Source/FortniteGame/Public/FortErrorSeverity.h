// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortErrorSeverity.generated.h"

UENUM(BlueprintType)
enum class EFortErrorSeverity : uint8
{
	// Unknown error state, may not be an error

	Unspecified = 0,
	// Error is logged but not shown to user

	Silent = 1,
	// Error should be shown to user but not block input

	Passive = 2,
	// Error is modal and requires a player decision

	Blocking = 3,
	// Error is severe

	SevereBlocking = 4,
};

