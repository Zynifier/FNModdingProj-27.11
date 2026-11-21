// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaAILootOctree.generated.h"

UENUM()
enum class ELootElementType : uint8
{
	Pickup = 0,
	Chest = 1,
	SupplyDrop = 2,
	Invalid = 255,
};

