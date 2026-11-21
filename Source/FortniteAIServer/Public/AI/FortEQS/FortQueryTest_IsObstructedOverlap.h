// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/Tests/EnvQueryTest_Trace.h"
#include "FortQueryTest_IsObstructedOverlap.generated.h"

UCLASS(MinimalAPI)
class UFortQueryTest_IsObstructedOverlap : public UEnvQueryTest_Trace
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Trace")
	FAIDataProviderBoolValue OverrideContextLocationXWithItemLocationX;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Trace")
	FAIDataProviderBoolValue OverrideContextLocationYWithItemLocationY;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Trace")
	FAIDataProviderBoolValue OverrideContextLocationZWithItemLocationZ;

};

