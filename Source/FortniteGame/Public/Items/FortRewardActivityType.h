// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRewardActivityType.generated.h"

UENUM()
namespace EFortRewardActivityType
{
	enum Type
	{
		// General rewards gained during normal gameplay

		General = 0,
		// Rewards earned by completing a primary mission

		MissionPrimary = 1,
		// Rewards earned by completing an optional/secondary mission

		MissionSecondary = 2,
		// Rewards earned from leveling up your account

		AccountLevelUp = 3,
		Max_None = 4 UMETA(DisplayName="None"),
	};
}

