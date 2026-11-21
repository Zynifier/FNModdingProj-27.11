// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCompletionResult.generated.h"

UENUM(BlueprintType)
enum class EFortCompletionResult : uint8
{
	Win = 0,
	Loss = 1,
	Draw = 2,
	Undefined = 3,
};

