// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPersistenceTypes.generated.h"

class UFortItemDefinition;
class UFortMinigameStatFilter;

USTRUCT()
struct FSaveRestrictions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SaveRestrictions")
	TArray<TSubclassOf<UFortMinigameStatFilter>> StatsToSave;

	UPROPERTY(EditDefaultsOnly, Category="SaveRestrictions")
	TArray<TSubclassOf<UFortMinigameStatFilter>> StatsAllowedToSavePostDeath;

	UPROPERTY(EditDefaultsOnly, Category="SaveRestrictions")
	TArray<TSubclassOf<UFortItemDefinition>> ItemClassesNotToSave;

};

