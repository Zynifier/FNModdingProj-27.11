// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMapLocationStateType.generated.h"

UENUM(BlueprintType)
enum class EMapLocationStateType : uint8
{
	//~ each entry here adds 120 bytes per map location.

	Normal = 0,
	//~ each entry here adds 120 bytes per map location.

	Golden = 1,
	//~ each entry here adds 120 bytes per map location.

	Undiscovered = 2,
	//~ each entry here adds 120 bytes per map location.

	Max = 3 UMETA(Hidden),
};

