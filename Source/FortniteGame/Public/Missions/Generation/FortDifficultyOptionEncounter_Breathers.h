// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Missions/FortDifficultyOptionEncounter.h"
#include "FortDifficultyOptionEncounter_Breathers.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionEncounter_Breathers : public UFortDifficultyOptionEncounter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortDifficultyOptionEncounter_Breathers")
	bool bUseBreathers;

	UPROPERTY(EditAnywhere, Category="FortDifficultyOptionEncounter_Breathers", meta=(EditCondition="bUseBreathers"))
	FCurveTableRowHandle LowPlayerPerformanceBreatherTimeSecondsCurve;

	UPROPERTY(EditAnywhere, Category="FortDifficultyOptionEncounter_Breathers", meta=(EditCondition="bUseBreathers"))
	FCurveTableRowHandle NormalPlayerPerformanceBreatherTimeSecondsCurve;

	UPROPERTY(EditAnywhere, Category="FortDifficultyOptionEncounter_Breathers", meta=(EditCondition="bUseBreathers"))
	FCurveTableRowHandle HighPlayerPerformanceBreatherTimeSecondsCurve;

};

