// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortCollectionBookSlotSourceData.generated.h"

USTRUCT(BlueprintType)
struct FFortCollectionBookSlotSourceData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookSlotSourceData")
	FText Description;

};

