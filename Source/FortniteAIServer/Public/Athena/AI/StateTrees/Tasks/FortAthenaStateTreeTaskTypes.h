// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaStateTreeTaskTypes.generated.h"

UENUM()
enum class EFortAthenaStateTreeTaskFeatureExecutionMode : int32
{
	DoNotExecute = 0,
	ExecuteOnEnter = 1,
	ExecuteOnExit = 2,
};

