// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMetaSoundTypes.generated.h"

UENUM(BlueprintType)
enum class EFortAudioAffiliation : uint8
{
	Local = 0,
	Friendly = 1,
	Enemy = 2,
	Neutral = 3,
};

