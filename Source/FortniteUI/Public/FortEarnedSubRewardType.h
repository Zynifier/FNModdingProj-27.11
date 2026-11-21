// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEarnedSubRewardType.generated.h"

UENUM(BlueprintType)
enum class EFortEarnedSubRewardType : uint8
{
	/** Player earned XP upon completion */
	XP = 0,
	/** Player earned Bars upon completion */
	Bars = 1,
};

