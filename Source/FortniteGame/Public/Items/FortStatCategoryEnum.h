// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortStatCategoryEnum.generated.h"

UENUM(BlueprintType)
enum class EStatCategory : uint8
{
	Combat = 0,
	Building = 1,
	Utility = 2,
	Max_None = 3 UMETA(hidden),
};

