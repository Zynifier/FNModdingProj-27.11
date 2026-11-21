// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortEncounterUtilityDesire.h"
#include "FortAIUtility.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_UtilitiesLocked.generated.h"

USTRUCT()
struct FFortEncounterLockedUtility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEncounterLockedUtility")
	TEnumAsByte<EFortAIUtility::Type> Utility;

	UPROPERTY(EditDefaultsOnly, Category="FortEncounterLockedUtility")
	TEnumAsByte<EFortEncounterUtilityDesire::Type> UtilityDesire;

};

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_UtilitiesLocked : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionEncounter_UtilitiesLocked")
	TArray<FFortEncounterLockedUtility> LockedUtilities;

};

