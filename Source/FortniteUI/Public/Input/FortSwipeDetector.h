// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortSwipeDetector.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEUI_API FFortSwipeDetector
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Swipe Detection", meta=(ClampMin="0", UIMin="0"))
	FVector2D SwipeThreshold;

};

