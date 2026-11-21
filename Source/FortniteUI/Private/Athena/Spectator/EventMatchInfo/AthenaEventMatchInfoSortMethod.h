// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaEventMatchInfoSortMethod.generated.h"

UENUM(BlueprintType)
enum class EAthenaEventMatchInfoSortMethod : uint8
{
	Eliminations = 0,
	Place = 1,
	Count = 2,
};

