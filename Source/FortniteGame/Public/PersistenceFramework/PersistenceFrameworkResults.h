// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFrameworkResults.generated.h"

UENUM()
enum class EPersistenceFrameworkResult : uint8
{
	/** The operation failed */
	Failed = 0,
	/** The operation Succeeded */
	Success = 1,
	/** The operation is not yet done */
	InProgress = 2,
	/** The operation cannot be done because system not ready */
	NotReady = 3,
};

UENUM()
enum class EPersistenceFrameworkServiceLatentResult : uint8
{
	/** The operation ended with failure */
	EndedTickingWithFailure = 0,
	/** The operation ended with success */
	EndedTickingWithSuccess = 1,
	/** The operation is continuing and needs ticking */
	ContinueTicking = 2,
};

UENUM()
enum class EPersistenceFrameworkState : uint8
{
	/** Not setup done */
	NotReady = 0,
	/** initialized to start persistence operations */
	ReadyForPersistence = 1,
	/** Deinitialized. Likely to be removed/deleted */
	DeInitialized = 2,
};

