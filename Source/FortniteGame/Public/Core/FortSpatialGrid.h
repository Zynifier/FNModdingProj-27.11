// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSpatialGrid.generated.h"

USTRUCT()
struct FFortSpatialCellIndex
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 X;

	UPROPERTY()
	int32 Y;

	UPROPERTY()
	int32 Z;


	FORTNITEGAME_API bool operator==(const FFortSpatialCellIndex& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FFortSpatialCellIndex& Value);
};

USTRUCT()
struct FFortSpatialGrid
{
	GENERATED_BODY()

};

