// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClassSelectorTypes.generated.h"

UENUM(BlueprintType)
enum class EClassSelectorDisplayMode : uint8
{
	ClassesOnly = 0,
	TeamsOnly = 1,
	TeamsAndClasses = 2,
};

