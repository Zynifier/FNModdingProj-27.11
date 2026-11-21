// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartEditorTransitionAddEditDialog.generated.h"

class UButton;
class UDetailsView;
class UMenuAnchor;
class UTextBlock;
class UUIStateChartEditorStateFilterMenu;
class UUIStateChartEditorStateInfo;
class UUIStateChartEditorTransitionAddEditScratch;
class UUIStateChartEditorTransitionInfo;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorTransitionAddEditDialog : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIStateChartEditorTransitionAddEditDialog(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void HandleCancelButtonPressed();

	UFUNCTION(BlueprintCallable)
	void HandleDetailsPropertyChanged();

	UFUNCTION(BlueprintCallable)
	void HandleDoneButtonPressed();

	UFUNCTION(BlueprintCallable)
	void HandleFilterMenuCreated(UUIStateChartEditorStateFilterMenu* InMenu, bool bIsSource);

	UFUNCTION()
	void HandleFilterMenuItemSelected(int32 InStateId);

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> SourceTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> SourceMenuAnchor;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TargetTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> TargetMenuAnchor;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> FinishButton;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> FinishButtonTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionAddEditDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDetailsView> TriggerPropertyView;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartEditorTransitionInfo> TransitionInfo;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorStateInfo*> StateInfoList;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartEditorTransitionAddEditScratch> ScratchTransitionValues;

};

UCLASS()
class UUIStateChartEditorTransitionAddEditScratch : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Transient, Category="UIStateChartEditorTransitionAddEditScratch", meta=(Categories="UI.Chart.TransitionTag"))
	FGameplayTag Trigger;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditorTransitionAddEditScratch")
	int32 SourceStateId;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditorTransitionAddEditScratch")
	int32 TargetStateId;

};

