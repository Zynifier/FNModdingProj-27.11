// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ParticipantFlow.generated.h"

UENUM()
enum class EParticipantFlowState : uint8
{
	NONE = 0,
	Initializing = 1,
	WaitingFor_BroadcastBeginChange = 2,
	WaitingFor_Precommit = 3,
	WaitingFor_Commit = 4,
};

