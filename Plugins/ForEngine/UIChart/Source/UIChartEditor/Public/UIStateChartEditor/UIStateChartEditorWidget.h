// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartEditorWidget.generated.h"

class UDetailsView;
class USinglePropertyView;
class UTreeView;
class UUIStateChart;
class UUIStateChartAssetSelection;
class UUIStateChartEditorStateInfo;
class UUIStateChartEditorTransitionAddEditDialog;
class UUIStateChartEditorTransitionInfo;
class UUIStateChartEditorTransitionList;
class UUIStateConfiguration;
class UWidget;

UENUM()
enum class EUIStateChartEditorChildType : uint8
{
	Regular = 0,
	ParallelRegion = 1,
};

UCLASS()
class UUIStateChartAssetSelection : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateChart")
	TObjectPtr<UUIStateChart> StateChart;

};

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleAssetSelectionChanged(FName InPropertyName);

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USinglePropertyView> AssetSelectionPropertyView;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTreeView> StateTreeView;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> RightSide;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDetailsView> StateDetailsView;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUIStateChartEditorTransitionList> OutgoingTransitionList;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUIStateChartEditorTransitionList> InheritedTransitionList;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUIStateChartEditorTransitionList> IncomingTransitionList;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUIStateChartEditorTransitionAddEditDialog> TransitionAddEditDialog;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartAssetSelection> AssetSelectionObject;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UIStateChartEditorWidget")
	TObjectPtr<UUIStateChart> StateChartToEdit;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UUIStateConfiguration*> StateTreeItems;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<int32, UUIStateConfiguration*> StatesById;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorStateInfo*> StateInfoList;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UUIStateConfiguration*> RegionRoots;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<UUIStateConfiguration*, UUIStateConfiguration*> ParentStatesByChild;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateConfiguration> SelectedState;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorTransitionInfo*> TransitionInfoList;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorTransitionInfo*> IncomingTransitions;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorTransitionInfo*> OutgoingTransitions;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorTransitionInfo*> InheritedTransitions;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartEditorTransitionInfo> AddEditTransition;

};

