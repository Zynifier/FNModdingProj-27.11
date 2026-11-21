// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariable.h"
#include "EncounterVariable_Boolean.generated.h"

USTRUCT(meta=(DisplayName="Boolean"))
struct FEncounterVariable_Boolean : public FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_Boolean"))
	FDataTableRowHandle RowValue;

};

