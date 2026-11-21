// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortServerTickRateEnum.generated.h"

UENUM(BlueprintType)
enum class EFortServerTickRate : uint8
{
	// Keep the default server tick rate (currently at 30hz in BR/Athena)

	UseDefault = 0 UMETA(DisplayName="Default (30hz)"),
	// Force the server to run at 20hz

	Twenty = 1 UMETA(DisplayName="20 hz"),
	// Force the server to run at 30hz

	Thirty = 2 UMETA(DisplayName="30 hz"),
};

