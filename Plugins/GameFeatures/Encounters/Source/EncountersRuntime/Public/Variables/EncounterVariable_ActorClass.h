// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Variables/EncounterVariable.h"
#include "EncounterVariable_ActorClass.generated.h"

USTRUCT(meta=(DisplayName="Actor Class"))
struct FEncounterVariable_ActorClass : public FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/EncountersRuntime.EncounterVarRow_ActorClass"))
	FDataTableRowHandle RowValue;

};

