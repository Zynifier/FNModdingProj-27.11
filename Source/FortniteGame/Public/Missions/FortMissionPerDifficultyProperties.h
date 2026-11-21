// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Environment/FortWindManager.h"
#include "FortTimeOfDayCollection.h"
#include "FortMissionPerDifficultyProperties.generated.h"

USTRUCT()
struct FMissionPerDifficultyProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MissionPerDifficultyProperties", meta=(ShowOnlyInnerProperties))
	TArray<FDataTableRowHandle> ValidDifficulties;

	UPROPERTY(EditDefaultsOnly, Category="MissionPerDifficultyProperties", meta=(ShowOnlyInnerProperties))
	FFortTimeOfDayTheme OverrideTimeOfDayTheme;

	UPROPERTY(EditDefaultsOnly, Category="MissionPerDifficultyProperties", meta=(ShowOnlyInnerProperties))
	FFortGlobalWindInfo OverrideGlobalWindInfo;

};

