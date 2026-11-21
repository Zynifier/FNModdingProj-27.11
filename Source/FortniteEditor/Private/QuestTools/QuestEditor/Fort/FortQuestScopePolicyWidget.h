// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "FortQuestScopePolicyWidget.generated.h"

class UComboBoxString;
class UWidget;

UCLASS(Abstract)
class UFortQuestScopePolicyWidget : public UQuestEditorSubWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitQuestParticipantScope();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestScopePolicyWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UComboBoxString> ComboBox_ParticipantScope;

private:
	UFUNCTION()
	UWidget* GenerateWidgetForOption(const FString& Option);

	UFUNCTION()
	void HandleParticipantScopeChanged(const FString& SelectedScope, ESelectInfo::Type SelectionType);

};

