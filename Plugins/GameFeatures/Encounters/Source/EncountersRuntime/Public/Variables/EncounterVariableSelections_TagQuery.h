// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_TagQuery.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="TagQuery"))
struct FEncounterVariableSelections_TagQuery : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_TagQuery"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

