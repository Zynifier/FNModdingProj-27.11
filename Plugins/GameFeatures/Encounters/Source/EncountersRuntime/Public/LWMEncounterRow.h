// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "LWMEncounterRow.generated.h"

class UFortAthenaLivingWorldEncounter;

USTRUCT()
struct FLWMEncounterRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> Encounter;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere, Category="Encounter")
	float Weight;

};

