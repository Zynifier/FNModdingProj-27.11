// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "FortDifficultyEncounterSettings.generated.h"

class UFortDifficultyOptionEncounter;

UCLASS()
class UFortDifficultyEncounterSettings : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Difficulty Options")
	TArray<TObjectPtr<UFortDifficultyOptionEncounter>> DifficultyOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning settings")
	FEncounterEnvironmentQueryInfo OverrideEncounterEnvironmentQueryInfo;

	UPROPERTY(EditAnywhere, Category="Spawning settings")
	FFortEncounterSettings EncounterSettings;

	UPROPERTY(EditDefaultsOnly, Category="Spawning settings")
	TEnumAsByte<EFortEncounterSpawnLimitType::Type> SpawnLimitMode;

	UPROPERTY(EditDefaultsOnly, Category="Spawning settings")
	TEnumAsByte<EFortEncounterPacingMode::Type> PacingMode;

};

