// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "WorldConditionQuery.h"
#include "EncounterVariableSelectionsRow.generated.h"

USTRUCT()
struct FEncounterVariableSelectionsRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagQuery RequiredCapabilities;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FWorldConditionQueryDefinition WorldConditionDefinition;

	UPROPERTY(EditAnywhere, Category="Encounter")
	float Weight;

};

