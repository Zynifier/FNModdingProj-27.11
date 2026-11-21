// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"
#include "UIStateChartEditorStateItem.generated.h"

class UBorder;
class UImage;
class UOverlay;
class UTextBlock;
class UTexture2D;
class UUIStateChartEditorStateContextMenu;
class UUIStateChartEditorStateItemDragged;
class UUIStateChartEditorWidget;
class UUIStateConfiguration;
class UWidget;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorStateItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UUIStateChartEditorStateItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> StateName;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Background;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> ArrowIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> IndentationGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ExpansionToggle;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ParallelRegionVisuals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	FLinearColor SelectedBackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	FSlateColor SelectedTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	FLinearColor UnselectedBackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	FSlateColor UnselectedTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	TObjectPtr<UTexture2D> ExpandedIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	TObjectPtr<UTexture2D> CollapsedIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	float Indentation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	TSubclassOf<UUIStateChartEditorStateItemDragged> DragWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItem")
	TSubclassOf<UUIStateChartEditorStateContextMenu> ContextMenuClass;

protected:
	UFUNCTION(BlueprintCallable)
	void ToggleExpanded();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateConfiguration> StateConfiguration;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateChartEditorWidget> StateChartEditorWidget;

};

