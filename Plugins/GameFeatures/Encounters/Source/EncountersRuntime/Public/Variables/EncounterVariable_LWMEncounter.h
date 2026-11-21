// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariable.h"
#include "EncounterVariable_LWMEncounter.generated.h"

USTRUCT(meta=(DisplayName="LWM Encounter"))
struct FEncounterVariable_LWMEncounter : public FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_LWMEncounter"))
	FDataTableRowHandle RowValue;

};

