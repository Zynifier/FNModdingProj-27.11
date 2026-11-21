// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariableSelectionsRow.h"
#include "EncounterVariableSelectionsRow_LWMEncounter.generated.h"

USTRUCT()
struct FEncounterVariableSelectionsRow_LWMEncounter : public FEncounterVariableSelectionsRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_LWMEncounter"))
	FDataTableRowHandle RowValue;

};

