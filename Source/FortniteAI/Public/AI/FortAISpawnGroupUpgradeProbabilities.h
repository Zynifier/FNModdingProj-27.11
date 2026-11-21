// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAIDirector.h"
#include "FortAISpawnGroupUpgradeProbabilities.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAISpawnGroupUpgradeProbabilities : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeProbabilities")
	bool bIsGuaranteedUpgrade;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeProbabilities")
	TArray<FFortAIPawnUpgradeProbability> UpgradeProbabilities;

};

