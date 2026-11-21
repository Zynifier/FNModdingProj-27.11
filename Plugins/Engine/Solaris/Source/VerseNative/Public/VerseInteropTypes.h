// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseInteropTypes.generated.h"

/** Corresponds to "false" in Verse, a type with no possible values. */
UENUM()
enum class EVerseFalse : uint8
{
	Value = 0,
};

/** Corresponds to "true" in Verse, a type with one possible value: false. */
UENUM()
enum class EVerseTrue : uint8
{
	Value = 0,
};

