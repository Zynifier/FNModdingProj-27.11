// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variables/EncounterVarRow.h"
#include "EncounterVarRow_ActorClass.generated.h"

class AActor;

USTRUCT()
struct FEncounterVarRow_ActorClass : public FEncounterVarRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TSoftClassPtr<AActor> Value;

};

