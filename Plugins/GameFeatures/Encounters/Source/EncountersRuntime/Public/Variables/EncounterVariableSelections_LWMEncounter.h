// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_LWMEncounter.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="LWM Encounter"))
struct FEncounterVariableSelections_LWMEncounter : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_LWMEncounter"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

