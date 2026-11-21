// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_Boolean.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="Boolean"))
struct FEncounterVariableSelections_Boolean : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_Boolean"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

