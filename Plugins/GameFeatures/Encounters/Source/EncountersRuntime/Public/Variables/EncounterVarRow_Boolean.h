// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_Boolean.generated.h"

USTRUCT()
struct FEncounterVarRow_Boolean : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	bool bValue;

};

