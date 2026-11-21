// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EncounterVariableSelections.generated.h"

USTRUCT(meta=(Hidden))
struct FEncounterVariableSelections
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EncounterVariableSelections")
	FGameplayTag VarName;

};

