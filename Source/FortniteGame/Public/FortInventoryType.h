// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInventoryType.generated.h"

UENUM(BlueprintType)
namespace EFortInventoryType
{
	enum Type
	{
		World = 0,
		Account = 1,
		Outpost = 2,
		MAX = 3,
	};
}

