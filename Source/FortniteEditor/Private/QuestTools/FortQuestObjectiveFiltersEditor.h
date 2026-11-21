// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "FortQuestObjectiveFiltersEditor.generated.h"

class UDataTable;
class UFortDynamicEntryBox;
class UFortQuestItemDefinition;
class UQuestEditorButton;

UCLASS(Abstract)
class UFortQuestObjectiveFiltersEditor : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddQuestItemObjectiveFilter();

	UFUNCTION(BlueprintCallable)
	void InitQuestObjectiveFiltersEditor(UFortQuestItemDefinition* InQuestItem, int32 InObjectiveIdx);

	UFUNCTION(BlueprintCallable)
	void RefreshObjectiveFilters();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestObjectiveFiltersEditor", meta=(BindWidget, EditInline="true"))
	UFortDynamicEntryBox* DynamicEntryBox_ObjectiveFilters;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortQuestObjectiveFiltersEditor")
	TObjectPtr<UFortQuestItemDefinition> QuestItem;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortQuestObjectiveFiltersEditor")
	int32 ObjectiveIdx;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestObjectiveFiltersEditor")
	TSoftObjectPtr<UDataTable> DefaultValuesDataTable;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UQuestEditorButton> Button_PasteObjectiveFilter;

};

