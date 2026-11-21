// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItem.h"
#include "EncounterItem.generated.h"

class ALivingWorldEncounterPrefab;
class UEncounterItemDefinition;
class UEncounterManagerComponent;

UCLASS(MinimalAPI, BlueprintType)
class UEncounterItem : public UFortItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UEncounterItemDefinition> EncounterItemDefinition;

	UPROPERTY()
	TWeakObjectPtr<ALivingWorldEncounterPrefab> EncounterPrefab;

	UPROPERTY(Export)
	TWeakObjectPtr<UEncounterManagerComponent> EncounterManager;

};

