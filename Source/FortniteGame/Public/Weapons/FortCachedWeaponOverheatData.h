// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCachedWeaponOverheatData.generated.h"

USTRUCT()
struct FFortCachedWeaponOverheatData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float TimeWeaponWasUnequipped;

	UPROPERTY()
	float OverheatValueAtUneqip;

	UPROPERTY()
	float OverheatValue;

	UPROPERTY()
	float TimeOverheatedBegan;

	UPROPERTY()
	float TimeHeatWasLastAdded;

};

