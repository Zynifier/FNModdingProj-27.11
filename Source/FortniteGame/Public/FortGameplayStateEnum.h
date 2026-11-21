// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayStateEnum.generated.h"

UENUM(BlueprintType)
namespace EFortGameplayState
{
	enum Type
	{
		// Normal gameplay is occurring

		NormalGameplay = 0,
		// Gameplay has not yet started, players loading in

		WaitingToStart = 1,
		// When the zone is complete, players deciding on next action

		EndOfZone = 2,
		// Entering zone from the lobby

		EnteringZone = 3,
		// We are transitioning out of the zone

		LeavingZone = 4,
		// No valid state

		Invalid = 5,
	};
}

