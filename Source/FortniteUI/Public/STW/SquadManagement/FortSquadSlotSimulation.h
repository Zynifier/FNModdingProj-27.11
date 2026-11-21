// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSquadSlotSimulation.generated.h"

UENUM(BlueprintType)
enum class EFortSquadSlottingRestrictionReason : uint8
{
	ItemIsInInventoryOverflow = 0,
	MandatorySlotWouldBeEmptied = 1,
	ItemIsOnActiveExpedition = 2,
	HeroRequiresMissingGameplayTag = 3,
	HeroAlreadyEquippedInLoadout = 4,
};

