// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortArrayElementPositionEnum.generated.h"

UENUM(BlueprintType)
enum class EFortArrayElementPosition : uint8
{
	None = 0,
	First = 1,
	Last = 2,
	Random = 3,
};

