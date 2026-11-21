// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "AthenaInventoryDropStackSizeRow.generated.h"

USTRUCT()
struct FAthenaInventoryDropStackSizeRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaInventoryDropStackSizeRow")
	FGameplayTagContainer ItemTags;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryDropStackSizeRow", meta=(ClampMin="1"))
	int32 StackSize;

};

