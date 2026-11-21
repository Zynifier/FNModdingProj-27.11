// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariableSelectionsRow.h"
#include "EncounterVariableSelectionsRow_ActorClass.generated.h"

USTRUCT()
struct FEncounterVariableSelectionsRow_ActorClass : public FEncounterVariableSelectionsRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_ActorClass"))
	FDataTableRowHandle RowValue;

};

