// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAutorunAnalytics.generated.h"

UENUM()
enum class EAutorunActivationMode : uint8
{
	None = 0,
	DoubleTap = 1,
	LockZoneButton = 2,
};

USTRUCT()
struct FAutorunUsageData
{
	GENERATED_BODY()

};

