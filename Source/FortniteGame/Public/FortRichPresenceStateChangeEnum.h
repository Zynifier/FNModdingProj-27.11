// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRichPresenceStateChangeEnum.generated.h"

UENUM()
enum class ERichPresenceStateChange : uint8
{
	// Default option to just update current state basics like status and session

	AutoUpdate = 0,
	// Client became idle

	Idle = 1,
	// Client is active again

	Active = 2,
	// Client started doing something important, do not disturb

	Busy = 3,
	// Client returned to doing not important things

	NotBusy = 4,
};

