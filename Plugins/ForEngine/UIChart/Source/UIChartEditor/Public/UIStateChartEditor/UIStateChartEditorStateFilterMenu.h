// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "UIStateChartEditorStateFilterMenu.generated.h"

class UEditableTextBox;
class UListView;
class UUIStateChartEditorStateInfo;
class UWidget;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorStateFilterMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIStateChartEditorStateFilterMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void FocusSearchBox();

	UFUNCTION()
	void HandleSearchTextChanged(const FText& InText);

	UFUNCTION()
	void HandleSearchTextCommitted(const FText& InText, ETextCommit::Type InCommitMethod);

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorStateFilterMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableTextBox> SearchBox;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorStateFilterMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> OptionsListView;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorStateFilterMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TypingPrompt;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorStateFilterMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> EmptyResultsMessage;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorStateInfo*> StateInfoList;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorStateInfo*> FilteredStateInfoList;

};

