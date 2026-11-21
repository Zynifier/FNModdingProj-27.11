// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EncounterVariable.generated.h"

USTRUCT(meta=(Hidden))
struct FEncounterVariable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EncounterVariable")
	FGameplayTag VarName;

};

