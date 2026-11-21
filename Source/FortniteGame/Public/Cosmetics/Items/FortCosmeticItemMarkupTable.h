// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortCosmeticItemMarkupTable.generated.h"

class UDataTable;

USTRUCT()
struct FCosmeticMarkupTagDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticMarkupTagDataRow")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticMarkupTagDataRow")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticMarkupTagDataRow")
	FText HelpText;

};

USTRUCT()
struct FCosmeticSetDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticSetDataRow")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticSetDataRow")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CosmeticSetDataRow")
	FText Description;

};

UCLASS()
class UFortCosmeticItemMarkupTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCosmeticItemMarkupTable")
	TArray<TObjectPtr<UDataTable>> SetDescriptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCosmeticItemMarkupTable")
	TArray<TObjectPtr<UDataTable>> MarkupTagDescriptions;

};

