// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDynamicBackgroundKey.generated.h"

UENUM(BlueprintType)
enum class EDynamicBackgroudKey : uint8
{
	Lobby = 0,
	Vault = 1,
	Max_None = 2 UMETA(Hidden),
};

