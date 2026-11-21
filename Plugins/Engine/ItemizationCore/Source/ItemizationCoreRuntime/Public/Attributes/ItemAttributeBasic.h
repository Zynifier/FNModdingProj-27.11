// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemAttributeBasic.generated.h"

UENUM(BlueprintType)
enum class EAttributeApplicationRule : uint8
{
	ItemEntryOnly = 0,
	ComponentOnly = 1,
	Anywhere = 2,
};

UENUM(BlueprintType)
enum class EAttributeBasicCalculateLogic : uint8
{
	ReturnFirstFound = 0,
	AddAllFound = 1,
	MultiplyAllFound = 2,
};

UENUM(BlueprintType)
enum class EAttributeBasicFirstFoundLogic : uint8
{
	PrioritizeItemEntry = 0,
	PrioritizeComponent = 1,
};

UENUM(BlueprintType)
enum class EAttributeBasicNotFoundResult : uint8
{
	ReturnInitial = 0,
	ReturnZero = 1,
};

