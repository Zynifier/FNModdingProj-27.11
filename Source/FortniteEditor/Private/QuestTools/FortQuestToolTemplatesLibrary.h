// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/PrimaryAssetId.h"
#include "FortQuestToolTemplatesLibrary.generated.h"

class UDataTable;
class UFortQuestItemDefinition;

USTRUCT(BlueprintType)
struct FFortQuestToolTemplatesRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestToolTemplatesRow")
	int32 SeasonNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestToolTemplatesRow")
	FName QuestTemplateTypeName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestToolTemplatesRow", meta=(AllowedTypes="Quest"))
	FPrimaryAssetId ItemTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestToolTemplatesRow")
	bool bHideTemplate;

};

USTRUCT(BlueprintType)
struct FFortQuestToolTemplatesRowDataPair
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortQuestToolTemplatesRowDataPair")
	FName RowName;

	UPROPERTY(BlueprintReadWrite, Category="FortQuestToolTemplatesRowDataPair")
	FFortQuestToolTemplatesRow RowData;

};

UCLASS()
class UFortQuestToolTemplatesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Quest Tool Templates Library")
	static TMap<FName, FFortQuestToolTemplatesRow> GetQuestTemplateNamesFromTableForType(const UDataTable* QuestTemplatesTable, const FName QuestTemplateTypeName);

	UFUNCTION(BlueprintCallable, Category="Fort Quest Tool Templates Library")
	static TArray<FFortQuestToolTemplatesRowDataPair> GetQuestTemplateRowsBySeasonNumber(const UDataTable* QuestTemplatesTable, const int32 SeasonNum);

	UFUNCTION(BlueprintCallable, Category="Fort Quest Tool Templates Library")
	static UFortQuestItemDefinition* LoadQuestTemplateFromRow(const FFortQuestToolTemplatesRow& RowData);

	UFUNCTION(BlueprintCallable, Category="Fort Quest Tool Templates Library")
	static UFortQuestItemDefinition* LoadQuestTemplateFromTableByRowName(const UDataTable* QuestTemplatesTable, const FName TemplateRowName);

	UFUNCTION(BlueprintCallable, Category="Fort Quest Tool Templates Library")
	static UFortQuestItemDefinition* LoadQuestTemplateFromTableBySeasonAndType(const UDataTable* QuestTemplatesTable, const int32 SeasonNum, const FName QuestTemplateTypeName);

};

