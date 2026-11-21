// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseRational.generated.h"

// Used to represent integer rational numbers in Verse.

USTRUCT()
struct FVerseRational
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int64 Numerator;

	UPROPERTY()
	int64 Denominator;

};

