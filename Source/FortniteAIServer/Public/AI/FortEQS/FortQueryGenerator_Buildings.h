// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "AI/FortAITypes.h"
#include "Building/EditMode/BuildingEditModeMetadata_Floor.h"
#include "FortQueryGenerator_Buildings.generated.h"

class UEnvQueryContext;
class UFortAIAssignmentSettings;

UCLASS(meta=(DisplayName="Goals: Structural Buildings"))
class UFortQueryGenerator_Buildings : public UEnvQueryGenerator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier AssignmentIdentifier;

	UPROPERTY(EditAnywhere, Category="Assignment")
	TObjectPtr<UFortAIAssignmentSettings> AssignmentSettings;

	UPROPERTY(EditAnywhere, Category="Generator")
	TSubclassOf<UEnvQueryContext> BuildingGridVolumeCenter;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue HorizontalBuildingCellRadius;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue BuildingCellsAbove;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue BuildingCellsBelow;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue bIncludeWalls;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue bIncludeFloors;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	TArray<EFloorPatternType> FloorPatternsToIgnore;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue bIncludeCenterCell;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderIntValue MaxBuildingActorsPerVolumeCenterToCollect;

};

