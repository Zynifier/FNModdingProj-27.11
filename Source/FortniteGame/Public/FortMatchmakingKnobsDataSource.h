// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingKnobsDataSource.generated.h"

UENUM()
namespace UFortMatchmakingKnobsDataSource
{
	enum Type
	{
		None = 0,
		Playlist = 1,
		Mutator = 2,
		GameMode = 3,
		Permissions = 4,
		UISettings = 5,
		CreativeGlobalOption = 6,
		MatchmakingGenerated = 7,
		Debug = 8,
		Max = 9,
	};
}

