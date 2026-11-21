// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "DebugMinimapData.generated.h"

USTRUCT()
struct FDebugMinimapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DebugMinimapData")
	bool bIsOverridden;

	UPROPERTY(EditDefaultsOnly, Category="DebugMinimapData")
	FSlateBrush DebugMinimapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="DebugMinimapData")
	FVector2D DebugMinimapIconScale;

	UPROPERTY(EditDefaultsOnly, Category="DebugMinimapData")
	FSlateBrush DebugCompassIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="DebugMinimapData")
	FVector2D DebugCompassIconScale;

};

