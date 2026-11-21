// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "Missions/FortMissionPowerPointsInterface.h"
#include "FortDifficultyOption.generated.h"

class UCurveTable;

USTRUCT()
struct FFortMissionGenerationElementCostAndAvailabilityRow : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AvailabilityCurve")
	TObjectPtr<UCurveTable> AvailabilityCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AvailabilityCurve")
	FName AvailabilityCurveTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cost")
	float MinCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cost")
	float MaxCost;

};

UCLASS(Abstract)
class UFortDifficultyOption : public UObject, public IFortMissionPowerPointsInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CostAndAvailability")
	FDataTableRowHandle CostAndAvailability;

};

