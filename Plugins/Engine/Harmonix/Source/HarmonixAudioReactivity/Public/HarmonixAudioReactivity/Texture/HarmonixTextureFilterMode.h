// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixTextureFilterMode.generated.h"

UENUM()
enum class EHarmonixTextureFilterMode : uint8
{
	/** Use point filtering when sampling this texture in a shader */
	Point = 0 UMETA(DisplayName="Point"),
	/** Use bilinear filtering when sampling this texture in a shader */
	Linear = 1 UMETA(DisplayName="Linear"),
	Count = 2 UMETA(Hidden),
	Invalid = 3 UMETA(Hidden),
};

