// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/HotSpots/AIHotSpotSlotGenerator_OnBoundingBox.h"
#include "FortAIHotSpotSlotGenerator_OnBoundingBox.generated.h"

UCLASS()
class UFortAIHotSpotSlotGenerator_OnBoundingBox : public UAIHotSpotSlotGenerator_OnBoundingBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AIHotSpot")
	float DistanceForRangedSlots;

	UPROPERTY(EditAnywhere, Category="AIHotSpot")
	float DistanceForHugeSlots;

};

