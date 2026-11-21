// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemTypeEnum.h"
#include "FortItemFiltering.generated.h"

USTRUCT(BlueprintType)
struct FFortItemFilterDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortItemFilterDefinition")
	TArray<EFortItemType> ItemTypeFilters;

	UPROPERTY(EditAnywhere, Category="FortItemFilterDefinition")
	bool bRequiresItemDetails;

};

