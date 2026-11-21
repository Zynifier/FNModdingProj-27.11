// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EncounterFactionRow.generated.h"

class UEncounterFactionData;

USTRUCT()
struct FEncounterFactionRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TObjectPtr<UEncounterFactionData> FactionData;

	UPROPERTY(EditAnywhere, Category="Encounter")
	float Weight;

};

