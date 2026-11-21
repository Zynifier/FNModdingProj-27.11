// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionBase.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "FortWorldConditionAthenaGamePhase.generated.h"

USTRUCT(meta=(DisplayName="Athena Game Phase"))
struct FFortWorldConditionAthenaGamePhase : public FWorldConditionCommonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortWorldConditionAthenaGamePhase")
	EAthenaGamePhaseStep PhaseStep;

	UPROPERTY(EditDefaultsOnly, Category="FortWorldConditionAthenaGamePhase")
	int32 SafeZonePhase;

};

