// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_GameplayTag.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="GameplayTag"))
struct FEncounterVariableSelections_GameplayTag : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_GameplayTag"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

