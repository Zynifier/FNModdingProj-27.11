// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaActorSpawnerData.h"
#include "EncounterPrefabEntry.h"
#include "EncounterActorSpawnerData.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UEncounterActorSpawnerData : public UFortAthenaActorSpawnerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="EncounterActorSpawnerData")
	FEncounterPrefabEntry EncounterEntry;

};

