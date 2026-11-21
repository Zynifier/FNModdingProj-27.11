// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/FortQuestToolListEntry.h"
#include "FortQuestObjectiveEditor.generated.h"

class UCommonTextBlock;
class UCustomPropertyView;
class UFortQuestItemDefComponentObjectiveExtensionTabbedView;
class UFortQuestObjectiveFiltersEditor;
class UQuestEditorButton;

UCLASS(Abstract)
class UFortQuestObjectiveEditor : public UFortQuestToolListEntry_Objective
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ObjectiveHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ObjectiveBackendName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UQuestEditorButton> Button_DuplicateObjective;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UQuestEditorButton> Button_RemoveObjective;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestItemDefComponentObjectiveExtensionTabbedView> TabbedView_ObjectiveExtension;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestObjectiveFiltersEditor> Editor_ObjectiveFilters;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCustomPropertyView> PropertyView_Objective;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestObjectiveEditor")
	FName ObjectiveBackendName;

};

