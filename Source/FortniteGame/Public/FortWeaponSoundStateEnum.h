// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponSoundStateEnum.generated.h"

UENUM(BlueprintType)
namespace EFortWeaponSoundState
{
	enum Type
	{
		Normal = 0,
		LowAmmo = 1,
		Degraded = 2,
		Max_None = 3 UMETA(DisplayName="None"),
	};
}

