// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariable.h"
#include "EncounterVariable_Float.generated.h"

USTRUCT(meta=(DisplayName="Float"))
struct FEncounterVariable_Float : public FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_Float"))
	FDataTableRowHandle RowValue;

};

