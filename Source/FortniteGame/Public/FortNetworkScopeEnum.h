// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortNetworkScopeEnum.generated.h"

UENUM(BlueprintType)
enum class EFortNetworkScope : uint8
{
	Neither = 0,
	Client = 1,
	Server = 2,
	Both = 3,
};

