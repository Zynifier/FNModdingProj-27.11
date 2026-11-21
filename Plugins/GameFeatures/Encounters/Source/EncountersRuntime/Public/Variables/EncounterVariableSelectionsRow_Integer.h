// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariableSelectionsRow.h"
#include "EncounterVariableSelectionsRow_Integer.generated.h"

USTRUCT()
struct FEncounterVariableSelectionsRow_Integer : public FEncounterVariableSelectionsRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_Integer"))
	FDataTableRowHandle RowValue;

};

