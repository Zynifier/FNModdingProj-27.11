// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLeaderboardMetricEnum.generated.h"

UENUM()
enum class EFortLeaderboardMetric : uint8
{
	/** Just the regular old score a player has (eg, Wax) */
	Score = 0,
	/** Number of eliminations. */
	Kills = 1,
	/** The team score used in win condition logic.  Calculated by AFortGameModeAthena::CalculateTeamScore()
	  * and replicated via AFortPlayerStateAthena::TeamScore. */
	TeamScore = 2,
};

