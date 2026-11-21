// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortCollectionBookPageCategoryData.generated.h"

USTRUCT(BlueprintType)
struct FFortCollectionBookPageCategoryTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookPageCategoryTableRow")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookPageCategoryTableRow")
	int32 SortPriority;

};

