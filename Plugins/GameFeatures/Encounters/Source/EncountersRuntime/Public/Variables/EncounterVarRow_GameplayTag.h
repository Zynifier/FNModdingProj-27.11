// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_GameplayTag.generated.h"

USTRUCT()
struct FEncounterVarRow_GameplayTag : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTag Value;

};

