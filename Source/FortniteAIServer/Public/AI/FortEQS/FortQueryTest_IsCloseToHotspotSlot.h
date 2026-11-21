// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_IsCloseToHotspotSlot.generated.h"

class AFortAIHotSpot;

UCLASS()
class UFortQueryTest_IsCloseToHotspotSlot : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Hotspot")
	TSubclassOf<AFortAIHotSpot> HotspotClass;

	UPROPERTY(EditDefaultsOnly, Category="Hotspot")
	FAIDataProviderFloatValue Radius;

	UPROPERTY(EditDefaultsOnly, Category="Hotspot")
	bool bIgnoreItemsWithSlotData;

};

