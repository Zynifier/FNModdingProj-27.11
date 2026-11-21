// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortMigrationDataTable.generated.h"

USTRUCT()
struct FFortMigrationDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Migration")
	FString OldItemTemplate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Migration")
	FString NewItemTemplate;

};

