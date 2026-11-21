// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaSeasonItemPageTypes.generated.h"

UENUM()
enum class EPageItemTileSize : uint8
{
	Size_1_x_1 = 0 UMETA(DisplayName="1 x 1"),
	Size_2_x_1 = 1 UMETA(DisplayName="2 x 1"),
	Size_2_x_2 = 2 UMETA(DisplayName="2 x 2"),
	Size_3_x_2 = 3 UMETA(DisplayName="3 x 2"),
	Size_3_x_3 = 4 UMETA(DisplayName="3 x 3"),
	Count = 5 UMETA(Hidden),
};

