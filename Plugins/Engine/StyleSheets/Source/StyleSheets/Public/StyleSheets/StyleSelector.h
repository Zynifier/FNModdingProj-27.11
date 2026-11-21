// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StyleSelector.generated.h"

/**
 * Style selector item is used for creating style selectors in style sheets.
 * Targets should be always sorted based on EStyleSelectorTargetType and ascending order.
 * Editor guarantees targets are sorted when a new FStyleSelectorItem is created.
 * Another reason why FStyleSelectorItem exists instead of using FGameplayTagContainer is 
 * because FGameplayTagContainer creates another array for parent tags.
 */
USTRUCT()
struct FStyleSelectorItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TArray<FGameplayTag> Targets;

};

