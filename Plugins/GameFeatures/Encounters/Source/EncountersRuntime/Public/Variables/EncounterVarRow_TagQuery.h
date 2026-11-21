// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_TagQuery.generated.h"

USTRUCT()
struct FEncounterVarRow_TagQuery : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagQuery Value;

};

