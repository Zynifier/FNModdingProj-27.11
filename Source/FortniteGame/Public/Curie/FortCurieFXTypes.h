// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCurieFXTypes.generated.h"

UENUM(BlueprintType)
enum class EFortCurieNativeFXType : uint8
{
	None = 0,
	Electricity = 1,
	Fire = 2,
	Charred = 4,
	// Add an extra value to know where tag based options can start

	Max = 8,
};

