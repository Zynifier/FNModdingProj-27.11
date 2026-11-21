// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIStateChartEditorStateContextMenu.generated.h"

class UButton;
class UUIStateChartEditorWidget;
class UUIStateConfiguration;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorStateContextMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIStateChartEditorStateContextMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void HandleConvertToParallelRegionRequested();

	UFUNCTION(BlueprintCallable)
	void HandleConvertToRegularChildRequested();

	UFUNCTION(BlueprintCallable)
	void HandleCreateChildRequested();

	UFUNCTION(BlueprintCallable)
	void HandleCreateParallelRegionRequested();

	UFUNCTION(BlueprintCallable)
	void HandleCreateParentRequested();

	UFUNCTION(BlueprintCallable)
	void HandleDeleteRequested();

	UFUNCTION(BlueprintCallable)
	void HandleMoveDownRequested();

	UFUNCTION(BlueprintCallable)
	void HandleMoveUpRequested();

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateContextMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> DeleteButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateContextMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> MoveUpButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateContextMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> MoveDownButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateContextMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> ConvertToRegularChildButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateContextMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> ConvertToParallelRegionButton;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateChartEditorWidget> StateChartEditorWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateConfiguration> StateConfiguration;

};

