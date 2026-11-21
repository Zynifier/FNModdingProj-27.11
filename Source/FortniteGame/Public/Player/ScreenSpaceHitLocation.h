// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScreenSpaceHitLocation.generated.h"

USTRUCT()
struct FScreenSpaceHitLocation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector2D ScreenSpaceHitLocation;

	UPROPERTY()
	bool bWasCriticalHit;

};

