// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_Float.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="Float"))
struct FEncounterVariableSelections_Float : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_Float"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

