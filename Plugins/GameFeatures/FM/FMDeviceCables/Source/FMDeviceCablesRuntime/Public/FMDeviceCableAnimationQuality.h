// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FMDeviceCableAnimationQuality.generated.h"

UENUM()
enum class EFMDeviceCableAnimationQuality : uint8
{
	High = 0,
	// Allow texture renders

	Med = 1,
	// Allow scalar values

	Low = 2,
};

