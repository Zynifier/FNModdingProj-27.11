// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralParameterModifierBlendMode.generated.h"

UENUM(BlueprintType)
enum class EProceduralParameterModifierBlendMode : uint8
{
	Min = 0,
	Max = 1,
	Additive = 2,
	Subtractive = 3,
	Multiply = 4,
	Interpolate = 5,
};

