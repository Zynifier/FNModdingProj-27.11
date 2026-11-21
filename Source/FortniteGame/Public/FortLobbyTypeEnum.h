// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLobbyTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EFortLobbyType : uint8
{
	Default = 0,
	Tournament = 1,
	Creative = 2,
	Division = 3,
};

