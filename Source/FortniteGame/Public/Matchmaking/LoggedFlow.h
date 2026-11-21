// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LoggedFlow.generated.h"

UENUM()
enum class EFlowState : uint8
{
	NotExecuted = 0,
	InProgress = 1,
	Success = 2,
	SuccessWithWarnings = 3,
	Canceled = 4,
	Failed = 5,
};

