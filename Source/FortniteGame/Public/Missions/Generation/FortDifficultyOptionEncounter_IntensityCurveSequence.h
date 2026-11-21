// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_IntensityCurveSequence.generated.h"

class UFortIntensityCurveSequence;

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_IntensityCurveSequence : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_IntensityCurveSequence")
	TObjectPtr<UFortIntensityCurveSequence> CurveSequence;

};

