// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HotSpots/AIHotSpotManager.h"
#include "AIHotSpotManagerProxy.generated.h"

class AAIHotSpot;

USTRUCT(BlueprintType)
struct FAIHotSpotSlotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Hotspot")
	TObjectPtr<AAIHotSpot> HotSpot;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Hotspot")
	int32 SlotIndex;

};

UCLASS()
class UAIHotSpotManagerProxy : public UAIHotSpotManager
{
	GENERATED_BODY()

};

