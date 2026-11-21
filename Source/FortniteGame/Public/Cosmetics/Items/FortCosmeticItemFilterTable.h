// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortCosmeticItemFilterTable.generated.h"

class UDataTable;

USTRUCT()
struct FCosmeticFilterTagDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticFilterTagDataRow")
	TArray<FText> SearchQueries;

};

UCLASS()
class UFortCosmeticItemFilterTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCosmeticItemFilterTable")
	TArray<TObjectPtr<UDataTable>> FilterTagTables;

};

