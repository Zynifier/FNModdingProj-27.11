// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortLootLevel.generated.h"

USTRUCT()
struct FFortLootLevelData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootLevel")
	FName Category;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootLevel")
	int32 LootLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootLevel")
	int32 MinItemLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootLevel")
	int32 MaxItemLevel;

};

