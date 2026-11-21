// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "AI/AIHotSpotSlot.h"
#include "FortQueryTest_HotspotSlotState.generated.h"

UCLASS()
class UFortQueryTest_HotspotSlotState : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Hotspot")
	EAIHotSpotSlot SlotState;

};

