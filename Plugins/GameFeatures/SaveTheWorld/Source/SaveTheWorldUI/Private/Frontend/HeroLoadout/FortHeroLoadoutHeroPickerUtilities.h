// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemTiles/FortItemFiltering.h"
#include "ItemTiles/FortItemSorting.h"
#include "FortHeroLoadoutHeroPickerUtilities.generated.h"

USTRUCT(BlueprintType)
struct FFortHeroLoadoutHeroPickerTabConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortItemFilterDefinition Filter;

	UPROPERTY()
	FFortItemSorterDefinition Sorter;

};

UCLASS()
class UFortHeroLoadoutHeroPickerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};

