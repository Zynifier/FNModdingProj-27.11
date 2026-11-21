// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariable.h"
#include "EncounterVariable_Integer.generated.h"

USTRUCT(meta=(DisplayName="Integer"))
struct FEncounterVariable_Integer : public FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_Integer"))
	FDataTableRowHandle RowValue;

};

