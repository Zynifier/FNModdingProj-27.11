// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_LWMEncounter.generated.h"

class UFortAthenaLivingWorldEncounter;

USTRUCT()
struct FEncounterVarRow_LWMEncounter : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> Value;

};

