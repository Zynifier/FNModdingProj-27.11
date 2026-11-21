// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_HotspotSlotOrientation.generated.h"

class UEnvQueryContext;

UCLASS()
class UFortQueryTest_HotspotSlotOrientation : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Hotspot")
	TSubclassOf<UEnvQueryContext> FaceToward;

	UPROPERTY(EditDefaultsOnly, Category="Hotspot")
	FAIDataProviderFloatValue DotThreshold;

};

