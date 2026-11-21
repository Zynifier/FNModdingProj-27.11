// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTeamEnum.generated.h"

UENUM(BlueprintType)
namespace EFortTeam
{
	enum Type
	{
		Spectator = 0,
		HumanCampaign = 1,
		Monster = 2,
		HumanPvP_Team1 = 3,
		HumanPvP_Team2 = 4,
		// This should always be last.

		MAX = 255 UMETA(DisplayName="None/Invalid"),
	};
}

UENUM(BlueprintType)
namespace EFortTeamAffiliation
{
	enum Type
	{
		Friendly = 0,
		Neutral = 1,
		Hostile = 2,
	};
}

