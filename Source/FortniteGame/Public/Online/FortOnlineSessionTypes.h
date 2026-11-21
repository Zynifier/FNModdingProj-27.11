// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortOnlineSessionTypes.generated.h"

UENUM(BlueprintType)
namespace EMatchmakingState
{
	enum Type
	{
		// Not in any matchmaking (begin/end state machine)

		NotMatchmaking = 0,
		// In process of canceling matchmaking

		CancelingMatchmaking = 1,
		// Release a lock on the world

		ReleasingLock = 2,
		// Acquire a lock on the world

		AcquiringLock = 3,
		// Failed to acquire a lock on the world, game needs to make decision

		LockAcquistionFailure = 4,
		// Getting a list of empty servers

		FindingEmptyServer = 5,
		// Getting a list of available sessions

		FindingExistingSession = 6,
		// Testing empty server list

		TestingEmptyServers = 7,
		// Testing available session list 

		TestingExistingSessions = 8,
		// In process of joining a session

		JoiningExistingSession = 9,
		// Cleaning after no matches available, but not done matchmaking

		NoMatchesAvailable = 10,
		// Waiting for cleanup and continue

		CleaningUpExisting = 11,
		// Handling an error condition (end state machine)

		HandlingFailure = 12,
		// Successful join (end state machine)

		JoinSuccess = 13,
	};
}

