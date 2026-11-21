// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/AIHotSpotManagerProxy.h"
#include "FortAIHotSpotManager.generated.h"

class UBuildingActorHotSpotConfig;

USTRUCT()
struct FAutoAcquireSlot : public FAIHotSpotSlotInfo
{
	GENERATED_BODY()

};

UCLASS()
class UFortAIHotSpotManager : public UAIHotSpotManagerProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSoftObjectPtr<UBuildingActorHotSpotConfig> FallbackHotspotConfig;

protected:
	UPROPERTY(Transient)
	TArray<FAutoAcquireSlot> AutoAcquireSlots;

};

