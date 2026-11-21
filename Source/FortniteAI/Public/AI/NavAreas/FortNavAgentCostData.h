// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortNavAgentCostData.generated.h"

class UNavArea;

UCLASS(MinimalAPI)
class UFortNavAgentCostData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	FName NavAgentName;

	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	TArray<TSubclassOf<UNavArea>> NavAreaStrengthBuckets;

};

