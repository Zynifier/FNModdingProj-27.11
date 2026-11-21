// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CoordinatorFlow.generated.h"

UENUM()
enum class ECoordinatorFlowState : uint8
{
	NONE = 0,
	Initializing = 1,
	WaitingForRequest = 2,
	WaitingForConsensus_BeginChange = 3,
	WaitingForConsensus_Precommit = 4,
	Consensus_Success = 5,
	Consensus_Failed = 6,
};

