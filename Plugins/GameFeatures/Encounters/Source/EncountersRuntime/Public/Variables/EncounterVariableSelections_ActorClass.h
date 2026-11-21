// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVariableSelections.h"
#include "EncounterVariableSelections_ActorClass.generated.h"

class UDataTable;

USTRUCT(meta=(DisplayName="Actor Class"))
struct FEncounterVariableSelections_ActorClass : public FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RequiredAssetDataTags="RowStructure=/Script/EncountersRuntime.EncounterVariableSelectionsRow_ActorClass"))
	TObjectPtr<UDataTable> ValueChoiceTable;

};

