// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCustomCharmTypeEnum.generated.h"

UENUM(BlueprintType)
namespace EFortCustomCharmType
{
	enum Type
	{
		Weapon = 0,
		Lapel = 1,
		Backpack1 = 2,
		Backpack2 = 3,
		NumTypes = 4 UMETA(Hidden),
	};
}

