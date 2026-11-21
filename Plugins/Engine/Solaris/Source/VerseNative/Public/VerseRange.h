// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseRange.generated.h"

// Used to represent integer range values in Verse (e.g. 1..24).
// The notional range is inclusive of the left bound and exclusive of the right bound.
// If Right <= Left, the range is empty.

USTRUCT()
struct FVerseIntRange
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int64 Left;

	UPROPERTY()
	int64 Right;

};

