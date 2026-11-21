// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AI/HotSpots/AIHotSpotSlotGenerator.h"
#include "AIHotSpotSlotGenerator_OnBoundingBox.generated.h"

class UAIHotSpotSlot;

UENUM()
enum class EBoundingBoxSlotDirectionCalculation : uint8
{
	Auto = 0,
	FaceWall = 1,
	FaceAwayFromWall = 2,
	FaceCenter = 3,
};

UCLASS()
class UAIHotSpotSlotGenerator_OnBoundingBox : public UAIHotSpotSlotGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Generator")
	TSubclassOf<UAIHotSpotSlot> SlotClass;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(EditCondition="bLimitMaxExtent"))
	FVector MaxExtent;

	UPROPERTY(EditAnywhere, Category="Generator")
	float ExpandBy;

	UPROPERTY(EditAnywhere, Category="Generator")
	float OffsetFromEdge;

	UPROPERTY(EditAnywhere, Category="Generator", meta=(ClampMin="0.0", UIMin="0.0"))
	float Spacing;

	UPROPERTY()
	uint8 bLimitMaxExtent : 1;

	UPROPERTY(EditAnywhere, Category="Generator")
	uint8 bMustHitFocusActor : 1;

	UPROPERTY(EditAnywhere, Category="Generator")
	EBoundingBoxSlotDirectionCalculation SlotDirectionCalculation;

};

