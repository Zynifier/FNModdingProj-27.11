// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortMissionConfigDataParams.generated.h"

class UFortMissionConfigData;

USTRUCT()
struct FFortMissionConfigDataBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ConfigParam")
	FGameplayTagQuery Query;

	UPROPERTY(EditDefaultsOnly, Category="ConfigParam")
	TSoftClassPtr<UFortMissionConfigData> ConfigDataClass;

};

USTRUCT()
struct FFortMissionConfigDataParams
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Configuration Parameters")
	TArray<FFortMissionConfigDataBucket> ConfigParams;

};

