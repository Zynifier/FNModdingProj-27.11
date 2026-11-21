// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreatureManagerTypes.generated.h"

UENUM(BlueprintType)
enum class ECreatureManagerAffectedTargets : uint8
{
	NewPawnsOnly = 0,
	NewAndExistingPawns = 1,
};

UENUM(BlueprintType)
enum class EScoreDistributionType : uint8
{
	Default = 0,
	DivideByDamage = 1,
	DivideEvenly = 2,
	AllToEliminator = 3,
};

