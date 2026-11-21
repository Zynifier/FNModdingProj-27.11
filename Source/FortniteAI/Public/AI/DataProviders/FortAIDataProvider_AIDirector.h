// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "FortAIDataProvider_AIDirector.generated.h"

UCLASS(AutoExpandCategories=("Provider"), meta=(DisplayName="AI Director"))
class UFortAIDataProvider_AIDirector : public UAIDataProvider
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float AIRelevantDistanceToPlayer;

	UPROPERTY()
	float EncounterRelevantDistanceToPlayer;

};

