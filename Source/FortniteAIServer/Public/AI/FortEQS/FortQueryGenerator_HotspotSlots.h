// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_HotspotSlots.generated.h"

class AFortAIHotSpot;
class UEnvQueryContext;

UCLASS(meta=(DisplayName="Hotspot Slots"))
class UFortQueryGenerator_HotspotSlots : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Generator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

	UPROPERTY(EditDefaultsOnly, Category="Generator", meta=(EditCondition="!bUseTetherZone"))
	FAIDataProviderFloatValue Radius;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	uint8 bUseTetherZone : 1;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TSubclassOf<AFortAIHotSpot> HotspotClass;

};

