// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "UIContextViewerWidget.generated.h"

class UListView;
class UUIContextViewerContextInfo;
class UUIStateChartManager;
class UWidget;
class UWorld;

UCLASS()
class UICHARTEDITOR_API UUIContextViewerWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void SearchForStateChartManager();

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> ContextListView;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIContextViewerWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> SearchForManagerButtonContainer;

	UPROPERTY(Transient)
	TSoftObjectPtr<UUIStateChartManager> StateChartManager;

	UPROPERTY(Transient)
	TSoftObjectPtr<UWorld> CurrentWorld;

	UPROPERTY()
	TArray<UUIContextViewerContextInfo*> ContextInfoList;

};

