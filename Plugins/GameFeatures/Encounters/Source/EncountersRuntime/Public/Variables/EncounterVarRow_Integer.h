// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_Integer.generated.h"

USTRUCT()
struct FEncounterVarRow_Integer : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	int32 Value;

};

