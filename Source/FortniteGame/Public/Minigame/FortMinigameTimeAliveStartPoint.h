// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMinigameTimeAliveStartPoint.generated.h"

UENUM(BlueprintType)
enum class EFortMinigameTimeAliveStartPoint : uint8
{
	// Calculate the time alive stat from the time the round started

	RoundStart = 0 UMETA(DisplayName="Round Start"),
	// Calculate the time alive stat from the time the pawn was created

	PawnCreated = 1 UMETA(DisplayName="Player Spawn"),
};

