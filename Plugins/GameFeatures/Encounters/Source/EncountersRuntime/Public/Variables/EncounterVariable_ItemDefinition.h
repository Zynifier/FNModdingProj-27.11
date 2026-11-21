// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariable.h"
#include "EncounterVariable_ItemDefinition.generated.h"

USTRUCT(meta=(DisplayName="Item Definition"))
struct FEncounterVariable_ItemDefinition : public FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_ItemDefinition"))
	FDataTableRowHandle RowValue;

};

