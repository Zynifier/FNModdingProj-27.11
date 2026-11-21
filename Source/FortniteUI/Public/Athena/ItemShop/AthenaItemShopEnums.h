// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaItemShopEnums.generated.h"

UENUM(BlueprintType)
enum class EItemShopCurrency : uint8
{
	VBucks = 0,
	RealMoney = 1,
};

UENUM(BlueprintType)
enum class EItemShopTileSize : uint8
{
	Mini = 0,
	Small = 1,
	Normal = 2,
	DoubleWide = 3,
	TripleWide = 4,
	Max = 5 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EViolatorIntensity : uint8
{
	Low = 0,
	Medium = 1,
	High = 2,
};

