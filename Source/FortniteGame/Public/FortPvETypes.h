// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPvETypes.generated.h"

UENUM(BlueprintType)
enum class EFortIdleDetectionState : uint8
{
	Disabled = 0,
	Default = 1,
	Suspicious = 2,
	Problematic = 3,
	Inactive = 4,
};

