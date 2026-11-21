// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortQuestItemDefinition_AthenaEnums.generated.h"

UENUM(BlueprintType)
enum class EFortQuestSubtype : uint8
{
	None = 0,
	/* Weekly challenge */
	WeeklyChallenge = 1,
	/* Punch card quest */
	PunchCard = 2,
	/* Quick (or repeatable) challenge */
	QuickChallenge = 3,
	/* Milestone quest */
	Milestone = 4,
	/* This is the final quest in a milestone chain. */
	MilestoneCapper = 5,
	/* Urgent quest that should bring up the special event UI on the HUD */
	UrgentQuest = 6,
	/* Auto fill quest */
	Autofill = 7,
	/* Discovery quest */
	Discovery = 8,
};

