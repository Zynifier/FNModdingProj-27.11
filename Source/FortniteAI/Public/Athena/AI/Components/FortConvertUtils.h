// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortConvertUtils.generated.h"

UENUM()
enum class EConvertedType : uint8
{
	NPC = 0,
	Creature = 1,
	All = 2,
	Unknown = 3,
};

UENUM(BlueprintType)
enum class EUnconvertReason : uint8
{
	StealByOtherPlayer = 0,
	ConverterDeath = 1,
	ConvertedDeath = 2,
	TooManyConverted = 3,
	TooFarFromConverter = 4,
	GameplayTagBlockConvert = 5,
	EndPlay = 6,
	Dismiss = 7,
	Unknown = 8,
};

