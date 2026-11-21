// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPhysicsSimSize.generated.h"

UENUM(BlueprintType)
enum class EFortPhysicsSimSize : uint8
{
	Small = 0,
	Average = 1,
	Medium = 2,
	Large = 3,
	Huge = 4,
	Giant = 5,
	Enormous = 6,
	Invalid = 7,
};

