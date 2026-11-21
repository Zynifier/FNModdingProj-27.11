// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_Integer.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="Integer"))
struct FEncounterVariableSelections_Integer : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_Integer"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

