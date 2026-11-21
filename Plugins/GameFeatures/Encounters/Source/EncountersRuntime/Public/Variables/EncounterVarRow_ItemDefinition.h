// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_ItemDefinition.generated.h"

class UFortWorldItemDefinition;

USTRUCT()
struct FEncounterVarRow_ItemDefinition : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TSoftObjectPtr<UFortWorldItemDefinition> Value;

};

