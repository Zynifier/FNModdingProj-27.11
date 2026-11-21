// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "FortCommonQuestTagQueryMenu.generated.h"

class UDataTable;
class UQuestEditorButton;

USTRUCT()
struct FCommonQuestTagQueryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CommonQuestTagQueryData")
	FText TextDataTableName;

	UPROPERTY(EditAnywhere, Category="CommonQuestTagQueryData")
	TSoftObjectPtr<UDataTable> DataTable;

};

UCLASS(Abstract)
class UFortCommonQuestTagQueryMenu : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UQuestEditorButton> Button_TagQueryMenu;

	UPROPERTY(EditDefaultsOnly, Category="FortCommonQuestTagQueryMenu")
	TMap<FName, FCommonQuestTagQueryData> TagQueryDataTables;

private:
	UPROPERTY()
	FGameplayTagQuery TagQueryExportText_Helper;

};

